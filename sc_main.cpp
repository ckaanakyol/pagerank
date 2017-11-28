#include "systemc.h"
#include "soa_struct.h"
#include "VtxDataRequester.cpp"
#include "VtxDataResponder.cpp"
#include <vector>


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

	
	VtxDataRequester vdreq("vdreq");
	VtxDataResponder vdres("vdres");


	sc_signal<double> ScaledRank{"scaledrank"};
	sc_signal<double> OneOverInDegree{"oneoverindegree"};
	sc_signal<int> NeighCount{"neighcount"};
	sc_signal<int> StartIndex{"startindex"};
	sc_signal<int> InEdgeCount{"inedgecount"};
	sc_signal<int> OutEdgeCount{"outedgecount"};
	sc_signal<int> VertexData{"vertexdata"};
	sc_signal<int> RespondID{"respondid"};
	

	sc_signal<int> inID{"inid"}; //Comes from outside
	sc_signal<int> requestID{"requestID"}; //request

    sc_signal<int> rowId{"rowid"};
    sc_clock clk;



    vdreq.ScaledRank(ScaledRank);
    vdreq.OneOverInDegree(OneOverInDegree);
    vdreq.NeighCount(NeighCount);
    vdreq.StartIndex(StartIndex);
    vdreq.InEdgeCount(InEdgeCount);
    vdreq.OutEdgeCount(OutEdgeCount);
    vdreq.VertexData(VertexData);
    vdreq.RespondID(RespondID);
    vdreq.inID(inID);
    vdreq.requestID(requestID);
    vdreq.rowId(rowId);
    vdreq.Port_CLK(clk);


    vdres.ScaledRank(ScaledRank);
    vdres.OneOverInDegree(OneOverInDegree);
    vdres.NeighCount(NeighCount);
    vdres.StartIndex(StartIndex);
    vdres.InEdgeCount(InEdgeCount);
    vdres.OutEdgeCount(OutEdgeCount);
    vdres.VertexData(VertexData);
    vdres.Out_Id(RespondID);
    vdres.Port_CLK(clk);
    vdres.In_Id(requestID);

	sc_start(50000, SC_PS);



	for (int i = 0 ; i < 9; ++i)
    std::cout << vt.vid[i] << ' ';
	return 0;
}