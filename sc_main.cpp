#include "systemc.h"
#include "VtxDataRequester.cpp"

int rownum = 16;
int features = 11;

int **VertexTable;
int sc_main(int argc, char* argv[])
{
	cout << "\n\nCreating Modules............\n";
	sc_start(50000, SC_PS);


	VertexTable = (int **)malloc(features * sizeof(int *));
 	for (int i=0; i<features; i++)
         VertexTable[i] = (int *)malloc(rownum * sizeof(int));






	return 0;
}