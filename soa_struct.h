#ifndef SOA_STRUCT_H
#define SOA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>


/*typedef struct VertexTable {
	int * vid;
	double * scaledRank;
	double * oneOverDegree;
	int * neighCount;
	int * startIndex;
	int * inEdgeCount;
	int * outEdgeCount;
	int * vertexData;
	bool * isValid;
} vt;

*/



extern int rownum ;
//rownum = 16;
class VertexTable {
	public:
		int * vid;
		double * scaledRank;
		double * oneOverDegree;
		int * neighCount;
		int * startIndex;
		int * inEdgeCount;
		int * outEdgeCount;
		int * vertexData;
		bool * isValid;

		void initVertexTable()
		{
			vid = (int*) malloc(rownum * sizeof(int));
			scaledRank = (double*) malloc(rownum * sizeof(double));
			oneOverDegree = (double*) malloc(rownum * sizeof(double));
			neighCount = (int*) malloc(rownum * sizeof(int));
			startIndex = (int*) malloc(rownum * sizeof(int));
			inEdgeCount = (int*) malloc(rownum * sizeof(int));
			outEdgeCount = (int*) malloc(rownum * sizeof(int));
			vertexData = (int*) malloc(rownum * sizeof(int));
			isValid = (bool*) malloc(rownum * sizeof(bool));


			for(int i = 0; i < rownum; i++){
				vid[i] = 0;
				scaledRank[i] = 0;
				oneOverDegree[i] = 0;
				neighCount[i] = 0;
				startIndex[i] = 0;
				inEdgeCount[i] = 0;
				outEdgeCount[i] = 0;
				vertexData[i] = 0;
				isValid[i] = 0;
			}
		}
};
extern VertexTable vt;


#endif

