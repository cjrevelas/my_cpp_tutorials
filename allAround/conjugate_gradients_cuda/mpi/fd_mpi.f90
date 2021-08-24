program main
implicit none
include 'mpif.h'
integer :: i,j,n
real(8), allocatable, dimension(:)   :: x,b,y
real(8), allocatable, dimension(:)   :: res
real(8) :: stopping_criterion,shift
integer :: iter_max, info
integer :: n_local,temp
integer :: myid,numprocs,error
real(8) :: T0,Tend,diag,beta

call MPI_INIT(error)

call MPI_COMM_RANK(MPI_COMM_WORLD, myid, error)
call MPI_COMM_SIZE(MPI_COMM_WORLD, numprocs, error)


n=100 !The order of the linear system

      n_local = n / numprocs
      temp=0
      if(myid==(numprocs-1)) then
        temp = n - n_local * numprocs
        n_local = n_local + temp
      endif

allocate(b(n_local),x(n_local),y(n_local),res(n))


call genSPD(n,T0,Tend,diag,beta)

b=beta
if(myid==0) b(1)=T0
if(myid==numprocs-1) b(n_local)=Tend

x=0.d0
if(myid==0) x(1)=T0 
if(myid==numprocs-1) x(n_local)=Tend


stopping_criterion=1.d-20
iter_max=n
call cg(diag,b,x,n_local,stopping_criterion,iter_max,myid,numprocs,info)

!export the gathered results for solution array x, root thread = 0
open(unit=1, file="solution.dat")

call MPI_GATHER(x,n_local,MPI_DOUBLE_PRECISION,res,n_local,MPI_DOUBLE_PRECISION, & !every thread sends n_local=10 elements to the root
                                          0,MPI_COMM_WORLD,error)

if (myid==0) then
   do i=1,n
       write(1,*) res(i)
   enddo
endif   

call MPI_FINALIZE(error)

end

subroutine cg(diag,b,x,n,stopping_criterion,iter_max,myid,numprocs,info)
implicit none
integer,                 intent(IN)    :: n,myid,numprocs
real(8), dimension(n)  , intent(IN)    :: b 
real(8), dimension(n)  , intent(INOUT) :: x
real(8)                , intent(IN)    :: stopping_criterion,diag
integer                , intent(IN)    :: iter_max
integer                , intent(OUT)   :: info
real(8), allocatable, dimension(:) :: ro,po,r1,p1,y
real(8) :: dot_initial_residual,norm2_initial_residual,error
real(8) :: alfa,bita,dot_residual,norm2_residual
integer :: iter
real(8) :: dotproduct


info=0 !successful exit

allocate(ro(n),po(n),r1(n),p1(n),y(n))

call matvec(x,ro,n,diag,myid,numprocs) 
ro=b-ro

! stopping_criterium=1.E-6 means that the 2-norm of the residual will be reduced by 
! a factor of 10^6 relative to the 2-norm of the initial residual.
dot_initial_residual=dotproduct(ro,ro,n)
norm2_initial_residual=sqrt(dot_initial_residual)
error=stopping_criterion*norm2_initial_residual
if(norm2_initial_residual<epsilon(error)) then
  print *, "I think someone is very lucky!!!"
  return
endif

po=ro
iter=0

do !until convergence
  iter=iter+1
  call matvec(po,y,n,diag,myid,numprocs) 
  alfa=dotproduct(ro,ro,n)/dotproduct(y,po,n)
  x=x+alfa*po
  call matvec(po,r1,n,diag,myid,numprocs) 
  r1=ro-alfa*r1
  
  ! Check for convergence using the second norm of the residual r1
  dot_residual=dotproduct(r1,r1,n)
  norm2_residual=sqrt(dot_residual)
  if(myid==0) print *, iter,norm2_residual
  if(norm2_residual<error) exit
  if(iter>=iter_max) then
    if(myid==0) print *, "Maximum number of iterations exceeded"
    info=-1
    exit
  endif


  bita=dot_residual/dotproduct(ro,ro,n)
  p1=r1+bita*po

  ro=r1
  po=p1
enddo

end subroutine cg


real(8) function dotproduct(x,y,n)
implicit none
include 'mpif.h'
integer,                 intent(IN)  :: n
real(8), dimension(n),   intent(IN)  :: x,y
real(8) local,global
integer error,i

local=0.d0
do i=1,n
  local=local+x(i)*y(i)
enddo

! ***** TODO *****
! write the MPI call to sum up local to global  (mpi all reduce)

call MPI_ALLREDUCE(local,global,1,MPI_DOUBLE_PRECISION, &
                                MPI_SUM,MPI_COMM_WORLD,error)

dotproduct=global

end function dotproduct



subroutine genSPD(n,T0,Tend,diag,beta)
implicit none
integer, intent(IN)  :: n
real(8), intent(OUT) :: T0,Tend,diag,beta
real(8) h,Tinf,deltax,rod_len

h=0.05d0
Tinf=200.d0
T0=300.d0
Tend=400.d0
rod_len=10.d0

deltax=rod_len/(dfloat(n)-1.d0)

diag=2.d0+h*deltax**2.d0
beta=h*Tinf*deltax**2.d0


end subroutine genSPD
 

subroutine matvec(x,y,n,diag,myid,numprocs)
implicit none
integer,                 intent(IN)  :: n,myid,numprocs
real(8), dimension(n),   intent(IN)  :: x
real(8),                 intent(IN)  :: diag
real(8), dimension(n),   intent(OUT) :: y
integer :: i
real(8) :: x_recv_from_prev,x_recv_from_next,a,b,c

call communication(x,x_recv_from_prev,x_recv_from_next,n,myid,numprocs)

do i=2,n-1
  a=x(i-1)
  b=x(i)
  c=x(i+1)
  y(i)=(-1.d0)*a+(diag)*b+(-1.d0)*c
enddo

if(myid==0) then
  b=x(1)
  y(1)=1.d0*b
else
  a=x_recv_from_prev                       !******************************************************* 
  b=x(1)
  c=x(2)
  y(1)=(-1.d0)*a+(diag)*b+(-1.d0)*c
endif

if(myid==numprocs-1) then
  b=x(n)
  y(n)=(1.d0)*b
else
  a=x(n-1)
  b=x(n)
  c=x_recv_from_next                       !********************************************************
  y(n)=(-1.d0)*a+(diag)*b+(-1.d0)*c
endif


end subroutine matvec


subroutine communication(x,x_recv_from_prev,x_recv_from_next,n,myid,numprocs)
implicit none
include 'mpif.h'
integer,                 intent(IN)  :: n,myid,numprocs
real(8), dimension(n),   intent(IN)  :: x
real(8),                 intent(OUT) :: x_recv_from_prev,x_recv_from_next
integer :: error, next, prev
integer tag1, tag2
real(8) :: x_send_to_prev,x_send_to_next
integer statuses(MPI_STATUS_SIZE,4), requests(4)

x_recv_from_prev=0.d0
x_recv_from_next=0.d0
x_send_to_prev=x(1)                        !******************************************************** 
x_send_to_next=x(n)                        !********************************************************

tag1=1
tag2=2

prev=myid-1
next=myid+1

!ring correction for start and end nodes
if (myid==0)          prev=numprocs-1
if (myid==numprocs-1) next=0 

if (myid==0)          x_recv_from_prev=0.d0  !********************************************************
if (myid==numprocs-1) x_recv_from_next=0.d0  !********************************************************  

call MPI_IRECV(x_recv_from_prev,1,MPI_DOUBLE_PRECISION,prev,tag1,&
                        MPI_COMM_WORLD, requests(1), error)

call MPI_IRECV(x_recv_from_next,1,MPI_DOUBLE_PRECISION,next,tag2,&
                        MPI_COMM_WORLD, requests(2), error)                           
 
call MPI_ISEND(x_send_to_prev,1,MPI_DOUBLE_PRECISION,prev,tag2,  &
                        MPI_COMM_WORLD, requests(3), error)

call MPI_ISEND(x_send_to_next,1,MPI_DOUBLE_PRECISION,next,tag1,   &
                        MPI_COMM_WORLD, requests(4), error)     


call MPI_WAITALL(4, requests, statuses, error)

end subroutine communication


