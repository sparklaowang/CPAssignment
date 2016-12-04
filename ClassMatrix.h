#include  <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Smatrix
{
public:
	Smatrix(int rank,int c, double *sheet);//initializer
	void make_max_at_n_c(int column,int n);
	void make_max_at_n_r(int row,int n);
	void n_fac_f_m_c(int n , double f , int m );
	void print();
	int r;//rank
	int l;//column number max
	double mem(int i,int j);
	void val(double va,int i, int j);
private:
	void switch_r(int c1 , int c2);
	void switch_c(int r1 , int r2);
	double **table;
	double *linear_table;
};

Smatrix::Smatrix(int rank,int c,double *sheet)//use linear sheet instead of matrix to avoid overrun
{
	
	this->table = (double **)malloc(sizeof(double *)*c);
	this->linear_table = (double *)malloc(sizeof(double)*rank*c);
	int i = 0,j=0;
	for(i;i<c;i++)
	{
		table[i] = (double *)malloc(sizeof(double)*rank);
		for(j=0;j<rank;j++)
		{
			table[i][j] = sheet[i*rank + j];
			linear_table[i*rank + j] = sheet[i*rank + j];
		}
	}
	this -> r = rank;
	this -> l = c;
}
double Smatrix::mem(int i,int j)
{
	if(i>l || j > r || i<0 || j < 0)
	{
		exit(0);
	}
	return(this->linear_table[i*r + j]);
}
void Smatrix::val(double va ,int i , int j)
{
	if(i>l || j > r || i<0 || j < 0)
	{
		exit(0);
	}
	linear_table[i*r + j]= va;
	table[i][j] = va;
}
void Smatrix::switch_c(int r1, int r2)
{
	double *temp = (double *)malloc(r*sizeof(double));
	int i =0;
	for(i;i<r;i++)
	{
		temp[i] = mem(r1,i);
		val(mem(r2,i),r1,i);
		val(temp[i],r2,i);
	}
	free(temp);
}
/*
	r1 r2 --> i
c1
c2
|      a ij
|
v
j
*/
void Smatrix::switch_r(int c1, int c2)
{
	double *temp = (double *)malloc(l*sizeof(double));
	int i =0;
	for(i;i<l;i++)
	{
		temp[i] = mem(i,c1);
		val(mem(i,c2),i,c1);
		val(temp[i],i,c2);
	}
	free(temp);
}
void Smatrix::make_max_at_n_c(int column,int n)
{
	int col=column;
	int j=r-1;
	for(j ; j>n;j--)
	{
		if(mem(col,j)>mem(col,j))
		{
			switch_r(j,j-1);
		}
	}
}

void Smatrix::make_max_at_n_r(int row,int n)
{
	int j=l-1;
	for(j ; j>n;j--)
	{
		if(mem(j,row)>mem(j-1,row))
		{
			switch_c(j,j-1);
			std::cout<<"w"<<std::endl;
		}
	}
}
void Smatrix::n_fac_f_m_c(int n , double f, int m)
{
	int i = 0;
	for(i;i<r;i++)
	{
		val(mem(n,i)*f+mem(m,i),m,i);
	}
}
void Smatrix::print()
{
	int i =0,j=0;
	static int calltime =0;
	std::cout<<calltime++<<std::endl;
	for(i;i<l;i++)
	{
		for(j=0;j<r;j++)
		{	
			std::cout << " " << mem(i,j) << " " ;
		}
		std::cout <<std::endl;
	}
}

