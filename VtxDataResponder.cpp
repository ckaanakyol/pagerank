#include "systemc.h"
using namespace std;
#include <queue>
SC_MODULE(VtxDataResponder)
{
public:
	sc_in<bool> Port_CLK{"CLK"};
	sc_in<int> In_Id{"in_id"};

	sc_out<double> ScaledRank{"scaledrank"};
	sc_out<double> OneOverInDegree{"oneoverindegree"};
	sc_out<int> NeighCount{"neighcount"};
	sc_out<int> StartIndex{"startindex"};
	sc_out<int> InEdgeCount{"inedgecount"};
	sc_out<int> OutEdgeCount{"outedgecount"};
	sc_out<int> VertexData{"vertexdata"};
	sc_out<int> Out_Id{"outid"};

	SC_CTOR(VtxDataResponder)
    {
        SC_METHOD(execute);
        sensitive << Port_CLK;
    }

    ~VtxDataResponder() {  }

private:
	std::queue <int> vertices;


    void execute()
    {
    	vertices.push(In_Id.read());

    	int readThisVtx = vertices.front();

    }


};