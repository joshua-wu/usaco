//template

/*
  ID: wujian.1
  PROG: pprime
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

bool is_prime( int n )
{
     //compexity:o(sqrt(n))
     //bug not consider
     assert( n > 0 );

     //n is 1, or n is an even except 2
     if( n == 1 || ((n & 1) == 0 && n != 2 ))
         return false;     
     for( int i = 3;  i <= sqrt( n ); i+=2 )
          if( n % i == 0 )
              return false;
              
     //if n  is 2 we will reach here
     return true;
}

//get the max bit and reverse
pair<int,int> reverse( int n )
{
     //reverse for, here n will not overflow
     int rn = 0;
     int bit = 1;
     while( n > 0 )
     {
            rn *= 10;
            rn += n % 10;
            n /= 10;
            bit *= 10;
     }
     
     return make_pair( rn, bit ) ;
}
 

int main() {
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");
    
    //init the prime table first
    int a,b;
    fin>>a>>b;
    //vector<int> result;
    //now generate the palindrom
    int next;
    int m;
    int ri;
    //complexity sqrt(n)
    for( int i = 0; i <= sqrt( b ); i++ )
    {
         //generate even
         pair<int,int> p =  reverse( i );
         m = p.second;
         ri = p.first;
         //save ri to get 5, 7
         if( (ri & 1) == 0 && ri != 0   )
             continue;
         next =  m * i  + ri ;
         if( is_prime( next ) &&  next >= a && next <= b )
             fout<<next<<endl;//result.push_back( next );
         //generate odd
         for( int j = 0; j <= 9; j++ )
         {
              //here can not reverse for 10 ->10301 1 -> can not be 10301
              next =  ( i * 10 + j ) * m  + ri;  
              if( is_prime( next ) &&  next >= a && next <= b )
                   fout<<next<<endl;//result.push_back( next );
         }             

    }
    
       

#ifdef __DEBUG__
    cin.get();
#endif
    return 0;
}


