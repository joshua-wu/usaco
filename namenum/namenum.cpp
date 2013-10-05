//template

/*
ID: wujian.1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <assert.h>     /* assert */

using namespace std;

//#define __DEBUG__

int find( const vector<string> & dict,  const string & to_find )
{
  //binsearch to find
  //left, right [,)
  //if so ,then the update of right must be rigth = mid
  //or you will miss some one,like [1,3,5],to find 3

  int mid;
  int left = 0;
  int right = dict.size() ;
  while( left < right )
    {
      mid = left + ( right - left ) / 2;
      if( dict[mid] == to_find )
	return mid;
      else if( dict[mid] > to_find )
	right = mid ;
      else // dict[mid] < to_find
	left = mid + 1;
    }

  return -1;
}


//#define __DEBUG__
bool generate_name( string & names, int position, const string & id, ofstream & fout, const vector<string> & dict )
{
   static string codes = "ABCDEFGHIJKLMNOPRSTUVWXY";
  //to test end or not
  if( position == id.size() )
    {
    //if( names == "KRISTOPHER")
    //    fout<<names<<endl;
               
      if( find( dict, names ) >= 0 )
	  {    
           fout<<names<<endl;
           return true;
      }
      else
      {
          return false;
      }
    }

  //to generate the next
  bool result;
  names[position] = codes[ ( id[position] - '2' ) * 3 ] ;
  result = generate_name( names, position + 1, id, fout, dict );

  names[position] = codes[ ( id[position] - '2' ) * 3 + 1 ] ;;
  result |= generate_name( names, position + 1, id, fout, dict );
  names[position] = codes[ ( id[position] - '2' ) * 3 + 2 ] ;
  result |= generate_name( names, position + 1, id, fout, dict );

  return result;
}



int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream dictfin("dict.txt");
    assert( fin && fout && dictfin);
    
    //load the dict
    vector<string> dict;

    string cur_str;
    while( dictfin >> cur_str )
           dict.push_back( cur_str );
    
    //load the id
    string id;
    fin>>id;
    
    //now to generate 
    string names( id.size(), 0 );
    bool result = generate_name(names, 0, id, fout,dict ); 
    if( !result  )
      fout<<"NONE"<<endl;
 
#ifdef __DEBUG__
    cin.get();
#endif
    return 0;
}

