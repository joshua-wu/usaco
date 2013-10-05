//template

/*
  ID: wujian.1
  PROG: ariprog
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

//#define __DEBUG__

//check the arithmetic progressions begin at an index of A
//will has at least count number s in A
bool match_condition( int first, int d,  int count, bool A[] , int len )
{     
    int cur_count = 0;
    for( int i = first; i < len && A[i] == true && cur_count < count; i+=d )
        cur_count++;
    if( cur_count == count )
        return true;
    else
        return false;
}

#define LEN_A (255*255*2)
bool A[LEN_A ];
int candidate[LEN_A];

int main() {
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");

    int n,m;
    //n in [3,25]
    //m in [1,250]
    fin>>n>>m;
    //generate all the biseque
    for( int i = 0; i <= m; i++ )
        for ( int j = i; j <= m ; j++ )
            A[ i * i + j * j ] = true;
                        
    int idx = 0;        
    for( int i = 0; i < LEN_A; i++ )
         if( true == A[i] )
             candidate[idx++] = i; 
    
    vector<pair<int,int> > result; //the first element is the differenct, the second is the first
    //now to test
    
    //bug, d may not be continue
    for( int first = 0; first < idx ; first++ )
        for( int second = first + 1; second < idx  ; second++ )
        {
             //now to test
            if( match_condition( candidate[first], candidate[second] - candidate[first], n, A, LEN_A ) )
                result.push_back( make_pair( candidate[second] - candidate[first],  candidate[first] ));                
        }

    sort( result.begin(), result.end() );
    for( int i = 0; i < result.size(); i++ )
        fout<<result[i].second<<" "<<result[i].first<<endl;
    if( result.size() == 0 )
        fout<<"NONE"<<endl;
    //some clean work
    fout.close();
    fin.close();

#ifdef __DEBUG__
    cin.get();
#endif
    return 0;
}
