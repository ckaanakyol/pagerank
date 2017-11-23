#include "systemc.h"
using namespace std;
#include <queue>

//extern static const int rownum;
//extern int VertexTable[][rownum];

SC_MODULE(VtxDataRequester)
{
public:
	sc_in<bool> Port_CLK{"CLK"};

	sc_in<double> ScaledRank{"scaledrank"};
	sc_in<double> OneOverInDegree{"oneoverindegree"};
	sc_in<int> NeighCount{"neighcount"};
	sc_in<int> StartIndex{"startindex"};
	sc_in<int> InEdgeCount{"inedgecount"};
	sc_in<int> OutEdgeCount{"outedgecount"};
	sc_in<int> VertexData{"vertexdata"};
	sc_in<int> RespondID{"respondid"};
	

	sc_in<int> inID{"inid"}; //Comes from outside
	sc_out<int> requestID{"requestID"};



	SC_CTOR(VtxDataRequester)
    {
        SC_METHOD(execute);
        sensitive << Port_CLK;

        SC_METHOD(writeToTable);
        sensitive << Port_CLK;
    }

    ~VtxDataRequester() {  }

private:

	std::queue <int> vIDs;

	void execute()
    {
    	vIDs.push(inID.read());
    	int requestThisVtx = vIDs.front();
    	requestID.write(requestThisVtx);
    }

    void writeToTable()
    {

    }
    

};