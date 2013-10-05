//template

/*
  ID: wujian.1
  PROG: numtri
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <queue>
#include <assert.h>     /* assert */

using namespace std;

#define MAX_LINE 1024
int data[MAX_LINE][MAX_LINE];
int result[MAX_LINE][MAX_LINE];

int main() {
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    
    //first to input the data
    int n;
    fin>>n;
    //the line row has the line + 1 number
    for( int line = 0; line < n; line++ )
         for( int i = 0; i < line + 1; i++ )
              fin>>data[line][i];             
    //then to calculate 
    
    //init the last line first
    for( int i = 0; i < n; i++ )
         result[ n - 1 ][ i ] = data[ n - 1][i];
    
    //botton up to calculate the result
    for( int line = n - 2; line >= 0; line-- )
         for( int i = 0; i < line + 1; i++ )
              result[line][i] = data[ line ][i] + max( result[line+1][i], result[line+1][i+1] );
              
    fout<<result[0][0]<<endl;
    
    //then to get the result
    

#ifdef __DEBUG__
    cin.get();
#endif
    return 0;
}


