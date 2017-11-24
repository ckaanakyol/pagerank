#include "systemc.h"
#include "soa_struct.h"
#include "VtxDataRequester.cpp"


extern struct VertexTable vertexTable;
extern int rownum;
int sc_main(int argc, char* argv[])
{
	
	cout << "\n\nInitializing VertexTable............\n";
	initVertexTable();

	cout << "\n\nCreating Modules............\n";
	sc_start(50000, SC_PS);





	return 0;
}