//template

/*
ID: wujian.1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>
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
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    
    int base;
    fin>>base;
    
    for( int i = 1; i <= 300; i++ )
      {
	string n_in_base = convert_to_base( i*i, base );
	if( is_palindromic_number( n_in_base ) )
	  fout<<convert_to_base( i, base )<<' '<<n_in_base<<endl;
      }

#ifdef __DEBUG__
    cin.get();
#endif
    return 0;
}

