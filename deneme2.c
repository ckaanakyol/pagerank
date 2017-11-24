#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "deneme.h"


extern int** global;
extern int rownum;
extern int colnum;

int main(int argc, char** argv) {

  bar();
  printf("%d\n", global[0][0]);
  printf("%d %d\n", rownum, colnum);
  global[0][0] = 50;
  foo();
  printf("%d\n", global[0][0]);



  double whole = 3.5;
  double fraction = whole - ((int)whole);

  printf("%d\n", (int)whole);
  printf("%d\n", (int)((whole-(int)whole)*10000));

  
}