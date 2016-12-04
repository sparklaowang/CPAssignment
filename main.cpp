#include "ClassMatrix.h"
using namespace std;
int main()
{
	double fac;
	double num[]={31,-13,0,0,0,-10,0,0,0,-15,-13,35,-9,0,-11,0,0,0,0,27,0,-9,31,-10,0,0,0,0,0,-23,0,0,-10,79,-30,0,0,0,-9,0,0,0,0,-30,57,-7,0,-5,0,-20,0,0,0,0,-7,47,-30,0,0,12,0,0,0,0,0,-30,41,0,0,-7,0,0,0,0,-5,0,0,27,-2,7,0,0,0,-9,0,0,0,-2,29,10};
	Smatrix a(10,9,num);
	int i,j,k,l;
	a.print();
	for(i=0;i<a.l;i++)
	{
		a.make_max_at_n_r(i,i);
		for(j=i+1;j<a.l;j++)
		{
			fac=-a.mem(j,i)/a.mem(i,i);
			a.n_fac_f_m_c(i,fac,j);
		}
	}
	a.print();
	for(i=a.l-1;i>0;i--)
	{
		for(j=i-1;j>=0;j--)
		{
			fac=-a.mem(j,i)/a.mem(i,i);
			a.n_fac_f_m_c(i,fac,j);
		}
	}

	a.print();
	for(i=0;i<a.l;i++)
	{
		a.val(a.mem(i,a.r-1)/a.mem(i,i),i,a.r-1);
		a.val(1,i,i);
	}
	a.print();
}
