//template

/*
  ID: wujian.1
  PROG: crypt1
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <assert.h>     /* assert */

using namespace std;

//#define __DEBUG__

bool test_ok( int digit, int n , bool has_digit[])
{
     //test n is ok or not
     for( int i = 0; i < digit; i++)
     {
          if( !has_digit[ n % 10] )
              return false;
          n /= 10;
     }
     
     return n == 0;
 }


int generate( int A[], int cur_len,int max_len, bool has_digit[] )
{
    //test if the cur_pos is the max_pos
    if( cur_len == max_len )
    {
        //A[0] A[1] A[2]
        //     A[3] A[4]
        int a = A[0] * 100 + A[1] * 10 + A[2];
        int pt1 = a * A[4];
        int pt2 = a * A[3];
        int result = pt1 + 10 * pt2;
        if( test_ok( 3, pt1, has_digit ) 
            && test_ok( 3, pt2, has_digit )
            && test_ok( 4, result, has_digit )
            )
            return 1;
        return 0;
        
    }
    
    //generate others
    int count = 0;
    for( int i = 1; i < 10; i++ )
    {
         if( !has_digit[ i ] ) 
             continue;
         //geneate next
         A[cur_len] = i;
         count += generate( A, cur_len + 1,5, has_digit );
    }
    
    return count;
    
}



int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
    
    //begin to imput
    int n;  //n is useless
    bool has_digit[10];
    memset( has_digit, 0, sizeof( has_digit ) );
    int tp;
    fin>>n;
    for( int i = 0; i < n; i++ )
         { fin>>tp; has_digit[tp] = true; }
         
    //now generate and test
    // i j k 
    //   l m
    //--------
    int A[5];
    fout<<generate( A, 0,5, has_digit )<<endl;
    
    //some clean work
    fout.close();
    fin.close();

#ifdef __DEBUG__
    cin.get();
#endif
    return 0;
}
