#include "systemc.h"
#include "soa_struct.h"
#include "VtxDataRequester.cpp"
//#include "VtxDataRequester.cpp"


//extern struct VertexTable vertexTable;
//extern int rownum;

int rownum = 16;
VertexTable vt;
int sc_main(int argc, char* argv[])
{
	
	//rownum = 16;
	cout << "\n\nInitializing VertexTable............\n";
	vt.initVertexTable();
	printf("%d\n", vt.vid[0]);
	vt.vid[0] = 11000;
	printf("%d\n", vt.vid[0]);

	cout << "\n\nCreating Modules............\n";


	VtxDataRequester vdr("vdr");

	printf("\n%d\n", vt.vid[0]);

	sc_start(50000, SC_PS);
	return 0;
}