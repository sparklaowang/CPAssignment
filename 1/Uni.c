
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "power.h"

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
	int i,j,seed,total,K;//seed just means seed , total is the amount that program generates
	const int m = 0x7FFFFFFF,a=16807;
	double buffer =0 ,sum = 0,first;


	//if there is an main() argument than use the main argument
	//else use default setting
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
		K  = atoi(argv[3]);
	}
	else
	{
		printf("loading default setting\n");
		total = 100000;
		seed = time(NULL)%m;
		i = seed ;
		K  = 3;
	}

	buffer = schrage(a , i , m)/(float)m; //buffer is the temporary position for the previous i
	first = buffer;//first is a signal for the first out put , if the program exceed the period of PRN, the program shall stop itself
	
	j = 0;
   
	sum  = 0 ;
	while(j++ != total)
	{
		i = schrage(a , i , m);
		buffer =power(((double)i)/m,K);

		sum += buffer;
	}
	printf("%Lf ",-sum/total + 1.00/(K + 1));
	getchar();//∑¿…¡ÕÀ 
	return(0);
}
