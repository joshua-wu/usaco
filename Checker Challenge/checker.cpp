//template

/*
  ID: wujian.1
  PROG: checker
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <queue>
#include <assert.h>     /* assert */

using namespace std;


//a lot of time costed!!!!
//next time should consider the for loop
//you should know every bit's complexity of you algorithm
//you should test every function possible

#define MAX_COL 13

//0:row
//1:main diag
//2:vice diag

bool vis[3][2 * MAX_COL];


int dfs( int col[],  int cur, int n , ostream & fout, int & num_to_print )
{
     //first check if end or not
     if( n == cur )
     {
         //now got a solution
         if( num_to_print > 0 )
         {
             fout<<col[0] + 1;
             for( int i = 1; i < n; i++ )
                  fout<<" "<<col[i] + 1;
             fout<<endl;
             
             num_to_print--;
         }
         
         return 1;
     }
     
     //now to generate the next
     //from row 0 to row n - 1
     int count = 0;
     for( int i = 0; i < n ; i++ )
     {         
          if( vis[0][ i ] || vis[1][ i - cur + n ] || vis[2][ i + cur] )
              continue; 
          //1. if some one in the same row or in the diagonals
          //for( int j = 0; j < cur && valid; j++ )
          //     if( col[ j ] == i || col[j] - j == i - cur || col[j] + j == i + cur )
          //              valid = false;
          
          //if( !valid )
          //    continue;
          
          
          //move state
          col[ cur ] = i;
          vis[0][i] = vis[1][i - cur + n] = vis[2][ i + cur] = true; 
          count += dfs( col, cur + 1, n, fout, num_to_print );
          //recover
          vis[0][i] = vis[1][i - cur + n] = vis[2][ i + cur] = false;
     } 
     
     return count;
     
}



int main() {
    ofstream fout ("checker.out");
    ifstream fin ("checker.in");
    
    int n ;
    fin>>n;
    int col[ MAX_COL ];   
    int num_to_print = 3;
    int num_of_solutions = dfs( col , 0, n, fout, num_to_print );     
    fout<<num_of_solutions<<endl;
#ifdef __DEBUG__
    cin.get();
#endif
    return 0;
}


