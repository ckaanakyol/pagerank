#include "systemc.h"
using namespace std;
#include <queue>
#include <fstream>
#include <vector>

using std::ifstream ;
using std::ofstream ;

//http://graphonline.ru/en/?graph=vkXoEXLWYzgTNRIJ

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
	int vtxCnt, edgeCnt;


	vector<double> vtxRanks;
	vector<double> vtxOneOverDegrees;  
	//vector<int> vtxOtherVtxIds;  
	vector<int> vtxInEdgeCounts;  
	vector<int> vtxEdgeOffsets;  
	vector<int> vtxData;  
	vector<int> vtxEdgeCnt;  

	int * vtxOtherVtxIds;

	/*double * vtxRanks;
	double * vtxOneOverDegrees;
	int * vtxOtherVtxIds;
	int * vtxInEdgeCounts;
	int * vtxEdgeOffsets;
	int * vtxData;
	int * vtxEdgeCnt;*/


	SC_CTOR(VtxDataResponder)
    {
        SC_METHOD(execute);
        sensitive << Port_CLK;

        readGraph();
    }

    ~VtxDataResponder() {  }

private:
	std::queue <int> vertices;


    void execute()
    {
    	vertices.push(In_Id.read());

    	int readThisVtx = vertices.front();
    	vertices.pop();
    	if(readThisVtx <= vtxCnt ){
	    	cout << "read: " << readThisVtx << endl;
	    	ScaledRank.write(vtxRanks[readThisVtx]);
	    	OneOverInDegree.write(vtxOneOverDegrees[readThisVtx]);
	    	NeighCount.write(vtxEdgeCnt[readThisVtx]);
	    	StartIndex.write(vtxEdgeOffsets[readThisVtx]);
	    	InEdgeCount.write(vtxInEdgeCounts[readThisVtx]);
	    	OutEdgeCount.write(vtxEdgeCnt[readThisVtx] - vtxInEdgeCounts[readThisVtx]);
	    	VertexData.write(0);
	    	Out_Id.write(readThisVtx);

	 		//cout << vtxRanks[readThisVtx] << endl;
	 	}

    }

    void readGraph()
    {
    	string filename = "g9.in";
    	ifstream ifs(filename.c_str());
		
		ifs>>vtxCnt;
		ifs>>edgeCnt;

		cout<<"Reading graph: "<<filename<<endl;
		cout<<"Number of Vtxs: "<<vtxCnt<<" number of edges: "<<edgeCnt<<endl;


		/*vtxRanks = new double[vtxCnt];
		vtxOtherVtxIds = new int[edgeCnt];
		vtxData = new int[vtxCnt];
  		vtxOneOverDegrees = new double[vtxCnt];
		vtxEdgeOffsets = new int[vtxCnt+1];
		vtxEdgeCnt = new int[vtxCnt];
		vtxInEdgeCounts = new int[vtxCnt];*/

		vtxOtherVtxIds = new int[edgeCnt];



		int currEdgeId = 0;
		for(unsigned int vtxIter=0; vtxIter<vtxCnt; vtxIter++){
			cout<<"VtxId: "<<vtxIter;
			int numEdges;
			int numInEdges;

			ifs>>numEdges;
			ifs>>numInEdges;
			//vtxEdgeCnt[vtxIter]=numEdges;
			vtxEdgeCnt.push_back(numEdges);
			cout<<"- numEdges: "<<numEdges<<" numInEdges: "<<numInEdges;
			//vtxEdgeOffsets[vtxIter]=currEdgeId;
			vtxEdgeOffsets.push_back(currEdgeId);
			vtxInEdgeCounts.push_back(numInEdges);
			cout << "- offset: " << vtxEdgeOffsets.at(vtxIter);
			for(unsigned int edgeIter=0; edgeIter<numEdges; edgeIter++){
				int edgeId;
				int otherVtxId;
				ifs>>edgeId;
				ifs>>otherVtxId;

				if(edgeIter<numInEdges){
					vtxOtherVtxIds[currEdgeId]=otherVtxId;
					//cout<<"\t"<<otherVtxId;
					currEdgeId++;
				}
			}
			cout<<endl;
			double scaledPageRank;
			double oneOverVtxDegree;
			
			ifs>>oneOverVtxDegree;
			ifs>>scaledPageRank;
			
			vtxRanks.push_back(scaledPageRank);
			vtxOneOverDegrees.push_back(oneOverVtxDegree);
			//vertexData[vtxIter].oneOverVtxDegrees = oneOverVtxDegree;

			//COUT<<"- scaledPageRank: "<<scaledPageRank<<" oneOverVtxDegree: "<<oneOverVtxDegree<<endl;
		}
	  	vtxEdgeOffsets.push_back(currEdgeId);

	  	/*for(int i = 0; i < vtxCnt + 1; i++){
	  		cout<<"\n" << vtxEdgeOffsets[i];
	  	}
	  	cout<<endl<<endl;
	  	for(int i = 0; i < edgeCnt; i++){
	  		cout<<"\n" << vtxOtherVtxIds[i];
	  	}

	  	cout<<endl<<endl;
	  	for(int i = 0; i < vtxCnt; i++){
	  		cout<<"\n" << vtxInEdgeCounts[i];
	  	}*/
	  	

    }


};