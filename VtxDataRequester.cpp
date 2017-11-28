#include "systemc.h"
using namespace std;
#include <queue>


#include "soa_struct.h"

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
	sc_out<int> requestID{"requestID"}; //request

    sc_out<int> rowId{"rowid"};

    int isFirstTime;
    int id;
	SC_CTOR(VtxDataRequester)
    {
        /*printf("%d\n", vt.vid[0]);
        vt.vid[0] = 3;
        printf("%d\n", vt.vid[0]);
        printf("%d\n", rownum);*/
        isFirstTime = 1;
        SC_METHOD(execute);
        sensitive << Port_CLK;
        id = 2;
        SC_METHOD(writeToTable);
        sensitive << Port_CLK;
        vIDs.pop();
        vIDs.push(0);
        vIDs.push(1);
    }

    ~VtxDataRequester() {  }

private:

	std::queue <int> vIDs;

	void execute()
    {
    	//vIDs.push(inID.read());
        //if(id < 9)
        vIDs.push(id);
        id++;
    	int requestThisVtx = vIDs.front();
        cout<< "requestThisVtx: " << requestThisVtx << endl;
    	requestID.write(requestThisVtx);
        vIDs.pop();
    }

    void writeToTable()
    {
    	int firstInvalidIndex = findFirstInvalid();
    	if(firstInvalidIndex != -1 && isFirstTime != 1){
            
    		vt.vid[firstInvalidIndex] = RespondID.read();
    		vt.scaledRank[firstInvalidIndex] = ScaledRank.read();
    		vt.oneOverDegree[firstInvalidIndex] = OneOverInDegree.read();
    		vt.neighCount[firstInvalidIndex] = NeighCount.read();
    		vt.inEdgeCount[firstInvalidIndex] = InEdgeCount.read();
    		vt.outEdgeCount[firstInvalidIndex] = OutEdgeCount.read();
    		vt.vertexData[firstInvalidIndex] = VertexData.read();
    		vt.validity[firstInvalidIndex] = 1;

            //cout << firstInvalidIndex << ": " << vt.vid[firstInvalidIndex]<<"  " <<vt.scaledRank[firstInvalidIndex] << endl;
    	}
        isFirstTime = 0;
    }

    int findFirstInvalid()
    {
    	for(int i = 0; i< rownum; i++){
    		if(vt.validity[i] == 0)
    			return i;
    	}
    	return -1;
    }
    

};