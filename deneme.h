// Author: Wes Kendall
// Copyright 2011 www.mpitutorial.com
// This code is provided freely with the tutorials on mpitutorial.com. Feel
// free to modify it for your own use. Any distribution of the code must
// either provide a link to www.mpitutorial.com or keep this header intact.
//
// An example of a function that implements MPI_Bcast using MPI_Send and
// MPI_Recv
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int rownum = 2;
int colnum = 2;
//int global[2][rownum];
sadasdfas
int ** global;

void foo()
{
	printf("%d\n", global[0][0]);
  global[0][0] = 10000;
}

void bar()
{
  global = (int **)malloc(rownum * sizeof(int *));
 	for (int i=0; i<rownum; i++)
         global[i] = (int *)malloc(colnum * sizeof(int));


}


