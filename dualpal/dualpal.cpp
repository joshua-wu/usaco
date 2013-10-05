//template

/*
ID: wujian.1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <string.h>
#include <assert.h>     /* assert */

using namespace std;

//#define __DEBUG__

bool is_palindromic_number( string it )
{
  //assume i > 0
  //judge that i is palindromic number or not
  for( int i= 0; i < it.size() / 2; i++ )
    if( it[ i ] != it[ it.size() - i - 1 ] )
      return false;

  return true;
}

//convert the num to string in the base "base"
string convert_to_base( int n, int base )
{
  assert( base > 0  && n > 0 );
  static string notation_map = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  
  string str_n;
  int remainder;
  while( n > 0 )
    {
      remainder = n % base;
      str_n += notation_map[ remainder ];
      n /= base;
    }
  
  reverse( str_n.begin(), str_n.end() );
  return str_n;
}


int main() {
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    
    int N,S;
    fin>>N>>S;
    
    int count = 0;
    int base_pal_count;
    
    while( count < N )
      {
           S++;
           base_pal_count = 0;
           for( int base = 2; base <= 10  ; base++ )
           {
                if( is_palindromic_number( convert_to_base( S , base ) ) )
                    base_pal_count++;
                if( base_pal_count == 2 )
                {
                    fout<<S<<endl;
                    count++;
                    break;
                }
           }
	             
      }

#ifdef __DEBUG__
    cin.get();
#endif
    return 0;
}

