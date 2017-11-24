#include <stdio.h>
#include <stdlib.h>


struct VertexTable {
	int * vid;
	double * scaledRank;
	double * oneOverDegree;
	int * neighCount;
	int * startIndex;
	int * inEdgeCount;
	int * outEdgeCount;
	int * vertexData;
	bool * isValid;
};

int rownum = 16;

struct VertexTable vertexTable;


void initVertexTable()
{
	vertexTable.vid = (int*) malloc(rownum * sizeof(int));
	vertexTable.scaledRank = (double*) malloc(rownum * sizeof(double));
	vertexTable.oneOverDegree = (double*) malloc(rownum * sizeof(double));
	vertexTable.neighCount = (int*) malloc(rownum * sizeof(int));
	vertexTable.startIndex = (int*) malloc(rownum * sizeof(int));
	vertexTable.inEdgeCount = (int*) malloc(rownum * sizeof(int));
	vertexTable.outEdgeCount = (int*) malloc(rownum * sizeof(int));
	vertexTable.vertexData = (int*) malloc(rownum * sizeof(int));
	vertexTable.isValid = (bool*) malloc(rownum * sizeof(bool));


	for(int i = 0; i < rownum; i++){
		vertexTable.vid[i] = 0;
		vertexTable.scaledRank[i] = 0;
		vertexTable.oneOverDegree[i] = 0;
		vertexTable.neighCount[i] = 0;
		vertexTable.startIndex[i] = 0;
		vertexTable.inEdgeCount[i] = 0;
		vertexTable.outEdgeCount[i] = 0;
		vertexTable.vertexData[i] = 0;
		vertexTable.isValid[i] = 0;
	}
}
