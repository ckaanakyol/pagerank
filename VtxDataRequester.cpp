#include "systemc.h"
using namespace std;
#include <queue>


#include "soa_struct.h"

//VertexTable vt;
//extern int rownum;
//vt VertexTable;
//VertexTable vt;
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
        printf("%d\n", vt.vid[0]);
        vt.vid[0] = 3;
        printf("%d\n", vt.vid[0]);
        printf("%d\n", rownum);
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
    	/*int firstInvalidIndex = findFirstInvalid();
    	if(firstInvalidIndex != -1){
    		vertexTable.vid[firstInvalidIndex] = RespondID.read();
    		vertexTable.scaledRank[firstInvalidIndex] = ScaledRank.read();
    		vertexTable.oneOverDegree[firstInvalidIndex] = OneOverInDegree.read();
    		vertexTable.neighCount[firstInvalidIndex] = NeighCount.read();
    		vertexTable.inEdgeCount[firstInvalidIndex] = InEdgeCount.read();
    		vertexTable.outEdgeCount[firstInvalidIndex] = OutEdgeCount.read();
    		vertexTable.vertexData[firstInvalidIndex] = VertexData.read();
    		vertexTable.isValid[firstInvalidIndex] = 1;
    	}*/
    }

    /*int findFirstInvalid()
    {
    	for(int i = 0; i< rownum; i++){
    		if(vertexTable.isValid[i] == 0)
    			return i;
    	}
    	return -1;
    }*/
    

};