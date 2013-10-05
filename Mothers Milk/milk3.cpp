//template

/*
  ID: wujian.1
  PROG: milk3
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

#define MAX_CAPACITY 24

bool existed[MAX_CAPACITY * MAX_CAPACITY * MAX_CAPACITY];

struct Status
{
    int a, b, c;
    Status( int a_ = 0, int b_ = 0, int c_ = 0 )
        :a(a_), b( b_ ), c( c_ ){}
    int hash()
    {
        return a * MAX_CAPACITY * MAX_CAPACITY + b * MAX_CAPACITY + c;
    }
};

int low_bound_w( int A[], int n , int key)
{
    //find the low bound that whether is the key or the place to insert
    int l = 0;
    int r = n;
    int m;
    while( l < r )
    {
        m = l + (( r - l )>>1);
        if( A[ m ] >= key )
            r = m;
        else
            l = m + 1;
    }

    return l;
}

void move( int & a, int & b, int CA, int CB )
{
    //move a to b
    int milk_move = min( CB - b, a ); // min of a can provider and b can receive
    a -= milk_move;
    b += milk_move;    
}

//return the len of the result
int bfs( Status & s,int CA, int CB, int CC,  int result[] )
{
    queue<Status> q;
    
    existed[ s.hash() ] = true;  //here is important
    q.push(  s );

    int len_result = 0; // len of result
    while( !q.empty() )
    {
        s = q.front();
        q.pop();

        //add to the result when pop out the queue
        if( s.a == 0 )
        {
            int pos = low_bound_w( result, len_result, s.c );
            if( pos == len_result || result[ pos ] != s.c )
            {
                //not found, insert
                for( int i = len_result; i > pos; i-- )
                     result[ i ] = result[ i - 1];
                     result[ pos ] = s.c;
                     len_result++;
                }
        }

        //generate the next 
        //store a copy
        Status copy = s;

        move( s.a, s.b, CA, CB );
        if(!existed[ s.hash() ]  ) 
        {
            existed[ s.hash()] = true;
            q.push( s );
        }
        //recove
        s = copy;

        move( s.b, s.a, CB, CA );
        if(!existed[ s.hash() ]  ) 
        {
            existed[ s.hash()] = true;
            q.push( s );
        }
        //recove
        s = copy;

        move( s.a, s.c, CA, CC );
        if(!existed[ s.hash() ]  ) 
            q.push( s );
        //recove
        s = copy;

        move( s.c, s.a, CC, CA );
        if(!existed[ s.hash() ]  ) 
        {
            existed[ s.hash()] = true;
            q.push( s );
        }
        //recove
        s = copy;

        move( s.b, s.c, CB, CC );
        if(!existed[ s.hash() ]  ) 
        {
            existed[ s.hash()] = true;
            q.push( s );
        }
        //recove
        s = copy;

        move( s.c, s.b, CC, CB );
        if(!existed[ s.hash() ]  ) 
        {
            existed[ s.hash()] = true;
            q.push( s );
        }
        s = copy;        
    }
    
    return len_result;
}


int main() {
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");

    int CA, CB, CC;
    fin>>CA>>CB>>CC;
    Status s;
    s.c = CC;
    
    int result[MAX_CAPACITY];
    int len_result = bfs( s, CA, CB, CC, result );
    
    fout<<result[0];
    for( int i = 1; i < len_result ; i++ )
        fout<<" "<<result[ i ] ;
    fout<<endl;
  
    //some clean work
    fout.close();
    fin.close();

#ifdef __DEBUG__
    cin.get();
#endif
    return 0;
}


