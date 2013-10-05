//template

/*
ID: wujian.1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <assert.h>     /* assert */

using namespace std;

//#define __DEBUG__

#define MAX_BARN (50+1)
#define MAX_COW  ( 200 + 1 )
#define INF 999999

int cost[MAX_COW][MAX_BARN];

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    
    int max_barn_count, stall_count, cow_count;
    fin>>max_barn_count>>stall_count>>cow_count;
    int * stall_number = new int[ cow_count + 1];
    for( int i = 0; i < cow_count; i++ ) 
         fin>>stall_number[i];
    
    //sort the stall_number
    sort( stall_number, stall_number + cow_count );
    
    
    
    //init the edge
    for( int i = 0;i < MAX_COW ; i++ ) 
         cost[ i ][ 0 ] = INF;
    for( int i = 0; i < MAX_BARN; i++ )
         cost[ cow_count ][ i ] = 0;
         
    //cost[ cow_num ] [ barn_num ], cow_num meaning that left cow_num - i to cost
    for( int i = 1; i <= max_barn_count; i++ )
         for( int j = cow_count - 1 ; j >= 0; j-- )
         {
              //init
              cost[ j ][ i ] = INF;
              for( int k = j + 1 ; k <= cow_count; k++ )
                   cost[j][i] = cost[k][i-1] + (stall_number[k-1] - stall_number[j] + 1 ) < cost [j][i] 
                                     ?  cost[k][i-1] + (stall_number[k-1] - stall_number[j] + 1 ):cost[j][i];
          }
              
    fout<<cost[0][max_barn_count]<<endl;
/*    
    for( int i = 0;i < cow_count + 1; i++ )
    {
         for( int j = 0; j < max_barn_count + 1; j++ )
              cout<<cost[i][j]<<'\t';
         cout<<endl;
     }
    
    cin.get();
 */   
    delete[] stall_number;
    
         

#ifdef __DEBUG__
    cin.get();
#endif
    return 0;
}

