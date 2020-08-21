#include<bits/stdc++.h>

using namespace std;

class Box{
private:
    unsigned long long int m_l, m_b, m_h;

public:
    Box(){
        m_l=0;
        m_b=0;
        m_h=0;
    }

    Box(unsigned long long int l, unsigned long long int b, unsigned long long int h) : m_l{l}, m_b{b}, m_h{h}{}

    Box(Box& box){
        m_l = box.m_l;
        m_b = box.m_b;
        m_h = box.m_h;
    }

    unsigned long long int getLength(){return m_l;}

    unsigned long long int getBreadth(){return m_b;}

    unsigned long long int getHeight(){return m_h;}

    long long CalculateVolume(){return (m_l*m_b*m_h);}

    friend std::ostream& operator<<(std::ostream& out, const Box& b);

    friend bool operator<(const Box& b1, const Box& b2);
};

std::ostream& operator<<(std::ostream& out, const Box& b){
    out << b.m_l << ' ' << b.m_b << ' ' << b.m_h << std::endl;
    return out;
}

bool operator<(const Box& b1, const Box& b2){
    bool test1, test2, test3;

    test1 = (b1.m_l < b2.m_l);
    test2 = ((b1.m_b < b2.m_b) && (b1.m_l == b2.m_l));
    test3 = ((b1.m_h < b2.m_h) && (b1.m_b == b2.m_b) && (b1.m_l == b2.m_l));

    if (test1 || test2 || test3){
        return true;
    }else{
        return false;
    }
}

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			//cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			//cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				//cout<<"Lesser\n";
			}
			else
			{
				//cout<<"Greater\n";
			}
		}
		if(type==4)
		{
		    cout << temp.getLength() << ' ' << temp.getBreadth() << ' ' << temp.getHeight() << std::endl;
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			//cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
