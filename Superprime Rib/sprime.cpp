//template

/*
  ID: wujian.1
  PROG: sprime
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
    
    if( n <= 1 || (( n & 1) == 0 && n != 2) )
        return false;
    for( int i = 3; i <= sqrt( n ); i+=2 )
         if( n % i == 0 )
             return false;
    return true;   
}

void dfs( int a, int cur, int n , ostream & fout)
{  
     //if a is a prime    
     if( n == cur )
     {
         //get a superprime
         fout<<a<<endl;
         return;  
     }
          
     //now generate the next
     //only consider the odd num
     for( int i = 1; i < 10; i+=1 )
     {
          if( !is_prime( a * 10 + i )  )
              continue;
          //generate the next
          dfs( a * 10 + i, cur + 1, n, fout );
          
     }     
}



int main() {
    ofstream fout ("sprime.out");
    ifstream fin ("sprime.in");
    
    int n ;
    fin>>n;
    
    dfs( 0, 0, n, fout );     

#ifdef __DEBUG__
    cin.get();
#endif
    return 0;
}


