
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef NULL
#define NULL 0
#endif

int schrage(int fac, int z , int mod) //function schrage mod.for fac stand for a in In+1 = aIn + b mod m ,z for In , modder for m
{
	int temp,q,r;
	// mod = fac * q + r
	r = mod%fac ;
	q = mod/fac ; 

	temp = fac * (z%q) - r * (z/q);//raw value for returning
	if(temp > 0)
	{
		return(temp);
	}
	else
	{
		return(temp + mod);
	}
}
int main(int argc,char ** argv)//first arg srand for the amount of random number ,while second argv stand for i1
{
	int i,j,seed,total,l,buffer;//seed just means seed , total is the amount that program generates,l stand for the distance l
	const int m = 0x7FFFFFFF,a=16807;
	double   sum_x=0,sum_xs=0,sum_xx=0;//sum_x is the summary o fx ,sum_xs is summary of x^2 sumxx'is the sum of x_n*x_n+l
	if(argc == 4)
	{
		total = atoi(argv[1]);
		if(0 ==  strcmp(argv[2],"TIME"))//a user-friendly operation ,if u don't want a manual seed,u can use TIME instead
		{
			i = time(NULL);
			seed = i;
		}
		else
		{
			i = atoi(argv[2]);
			seed = i;//
		}
		l = atoi(argv[3]);
	}
	else
	{
		printf("loading default setting \n");
		total = 100000;
		seed = time(NULL)%m;
		i = seed ;
		l = 5;
	}
	j =0 ;
	buffer = (double)i ;
	while(j++ != total)
	{
		i =  schrage(a , i , m);
		if(j>=l)
		{
			buffer = schrage(a , buffer , m);
			sum_xx += (i/(double)m) *(buffer/(double)m);
			sum_x += (buffer/(double)m);
			sum_xs += (buffer/(double)m) * (buffer/(double)m);
		}
	}
	double c;
	c =( sum_xx/total  - sum_x/total * sum_x/total ) / (sum_xs/total - sum_x/total * sum_x/total);

	fprintf(stdout,"%Lf ",c);
	getchar();//∑¿…¡ÕÀ 

	return(0);
}
