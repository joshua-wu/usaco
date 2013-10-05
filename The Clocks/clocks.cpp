//template

/*
  ID: wujian.1
  PROG: clocks
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

#define __DEBUG__



//bfs 
//set the 12:00 as 0
// 3:00 1
// 6:00 2
// 9:00 3

char * move_detail[] = {"ABDE", "ABC", "BCEF", "ADG", "BDEFH", 
                      "CFI", "DEGH", "GHI", "EFHI"};
bool status_indicator[ 4*4*4*4*4*4*4*4*4 ];



//the target is 0
int path[ 4*4*4*4*4*4*4*4*4 ];



class Grid
{
private:
    int m_status[9];
    int m_used[9];
    int m_hash_value;
public:
    Grid( int status[9] )
        {
            for( int i = 0; i < 9; i++ ) 
            {
                m_status[i] = status[i]; 
                m_used[i] = 4;
            }        
            
            m_hash_value = to_hash();
        }



    Grid( const Grid & it )
        {            *this = it;        }
    
    
    Grid & operator=( const  Grid & it )
        {          
            for( int i = 0; i < 9;i++ )
            {
                m_status[i] = it.m_status[i];
                m_used[i] = it.m_used[i];
            }
            m_hash_value = to_hash();
            return *this;
        }
     bool move( int type )
        {
            //move as the type, type begin from 0
            assert( type >= 0 && type < 9 );

            if( m_used[type] == 0 )
                return false;

            //now to roate
            char * p = move_detail[ type ];
            while( *p != '\0' )
            {
                   //bug 5
                m_status[ *p - 'A' ] = ( m_status[ *p - 'A'] + 1 ) % 4;
                p++;
            }
            m_used[type]--;
            
            m_hash_value = to_hash();
            return true;
        }

    
    int hash()const
        {
            return m_hash_value;
        }

    int to_hash( )const
        {
            //hash it
            int base = 1;
            int result = 0;
            for( int i = 0; i < 9; i++ )
            {
                result += m_status[i] * base;
                base *= 4;
            }
            return result;
        }
};


//record to reach the status,what transform needed
int trans[ 4*4*4*4*4*4*4*4*4 ];

void bfs( Grid & status )
{
     //bug4
    status_indicator[ status.hash() ] = true;
    queue<Grid> q;
    q.push( status );
    while( !q.empty() )
    {
        status = q.front(); 
        q.pop();

        //now to generate the next
        
        Grid copy = status;
        //this status not exist and not the target, so we expand it
        for( int i = 0; i < 9; i++ )
        {
             //bug3
             status = copy;
            //now generate the next
            if(!status.move( i )
               ||status_indicator[ status.hash() ]  )
                continue;
            
            //check exist or not
            //if not exist, add the path
            path[status.hash()] = copy.hash();
            trans[ status.hash() ] = i + 1;
            status_indicator[ status.hash() ] = true;
            
            //check is the target or not
            if( status.hash() == 0 )
                return;
            q.push( status );
        }
    }
}

void print_path( ofstream & fout )
{
    //we know that the end state is 0
    //in the path we can trace backword
    //here we get all status out
    vector<int> transform_passed;
    int cur_status = 0;
    while( path[cur_status] != -1 )
    {
        transform_passed.push_back( trans[ cur_status ] );
        cur_status = path[ cur_status ];
    }
    
    //to output
    //bug1
    if( transform_passed.size() > 0 )
    {
        fout<<*transform_passed.rbegin();
        for( vector<int>::reverse_iterator c_iter = transform_passed.rbegin() + 1; 
             c_iter != transform_passed.rend();
             c_iter++ )
             fout<<" "<<*c_iter;
        fout<<endl;
    }
}

int main() {
    ofstream fout ("clocks.out");
    ifstream fin ("clocks.in");

    memset( path, -1, sizeof( path ) );
    memset( trans, -1, sizeof( trans ));
    //begin to input
    int A[9];
    for( int i = 0; i < 9; i++ )
        {
             fin>>A[i];
             //bug2
             A[i] = (A[i] / 3 )%4;
        }
    Grid status( A );
    bfs( status );
    print_path( fout );
        
    //some clean work
    fout.close();
    fin.close();

#ifdef __DEBUG__
    cin.get();
#endif
    return 0;
}
