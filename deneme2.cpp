#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "deneme.h"
#include <vector>
using namespace std;
#include <iostream>


/*extern int** global;
extern int rownum;
extern int colnum;*/
extern struct VertexTable vt;
extern int rownum;

int main(int argc, char** argv) {

	vector<int> v(10);
  v.at(0)=5;
	cout<< v[0]<<endl;
	foo();
	printf("%d\n", vt.vid[0]);

  /*bar();
  printf("%d\n", global[0][0]);
  printf("%d %d\n", rownum, colnum);
  global[0][0] = 50;
  foo();
  printf("%d\n", global[0][0]);



  double whole = 3.5;
  double fraction = whole - ((int)whole);

  printf("%d\n", (int)whole);
  printf("%d\n", (int)((whole-(int)whole)*10000));*/

  
}