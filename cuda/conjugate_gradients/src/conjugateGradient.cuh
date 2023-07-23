#ifndef CONJUGATE_GRADIENT_DATA_H
#define CONJUGATE_GRADIENT_DATA_H

enum ConjugateGradientEnum {
  _Mult1_      = 0,
  _Mult2_      = 1,
  _Alpha_      = 2,
  _Beta_       = 3,
  _Solution_   = 4,
  _Projection_ = 5,
  _Direction_  = 6,
  _Residual_   = 7,
  _Rhs_        = 8,
  _Diag_       = 9,
  _OffDiag_    = 10,
  _Aux_        = 11
};

struct ConjugateGradientData{
  double *alpha, *beta;
  double *mult1, *mult2;

  double *solution;
  double *projection;
  double *direction;
  double *residual;

  double *rhs;
  double *diag;    // Store diagonal coefs of A
  double *offDiag; // Store off-diagonal coefs of A

  double *aux;

  double *get(ConjugateGradientEnum data) const {
    switch (data){
      case _Mult1_      : return mult1;
      case _Mult2_      : return mult2;
      case _Alpha_      : return alpha;
      case _Beta_       : return beta;
      case _Solution_   : return solution;
      case _Projection_ : return projection;
      case _Direction_  : return direction;
      case _Residual_   : return residual;
      case _Rhs_        : return rhs;
      case _Diag_       : return diag;
      case _OffDiag_    : return offDiag;
      case _Aux_        : return aux;
    }

    return NULL;
  }
};

struct ConjugateGradientDataPtrs {
  ConjugateGradientData *hostPtr;     // Host pointer  , its members point to host   memory locations
  ConjugateGradientData *deviceData;  // Host pointer  , its members point to device memory locations
  ConjugateGradientData *devicePtr;   // Device pointer, its members point to device memory locations
};

#endif
