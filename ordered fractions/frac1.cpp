 
/*
ID: wujian.1
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include<vector>
#include<algorithm>
using namespace std;

int gcd( int a, int b )
{
    int t;
    while( b != 0 )
    {
          t = b;
          b = a%b;
          a = b;
    }
    
    return a;
}


struct Fraction
{
       int d;//denominator
       int n; //numenator
       Fraction( int d_, int n_ )
       {
        //find the max 
        d = d_;
        n = n_;
        //int gcd_value = gcd( d, n );
        //d /= gcd_value;
        //n /= gcd_value;
       }
       
       bool operator== ( const Fraction & it )const
       {
            return it.d == d && it.n == n;
       }
       
       bool operator<( const Fraction & it )const
       {
            return n*1.0/d < it.n*1.0 / it.d;
       }
};

int main() {
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");
    
    int nvalue;
    fin>>nvalue;
    vector<Fraction> result;
    for( int d = 1; d <= nvalue; d++ )
         for( int n = 0; n <= d; n++ )
           if( gcd( d, n ) == 1 )
             result.push_back( Fraction( d,n ) );
             
    sort( result.begin(), result.end() );
    
    //now out put
    for( int i = 0;i < result.size(); i++ )
         if( i== 0 || !(result[i-1] == result[i]) )
             fout<<result[i].n<<"/"<<result[i].d<<endl;
    return 0;
}



