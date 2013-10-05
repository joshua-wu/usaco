//template

/*
  ID: wujian.1
  PROG: calfflac
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

#define MAX_PALINDROM 2000
#define MAX_STRING 20000

char A[MAX_STRING];
char A_dump[ MAX_STRING];
int map[MAX_STRING];
struct Interval
{ int begin;
  int end ;
  Interval(int b_ = 0, int e_ = 0)
  :begin(b_),end(e_){}
  
  bool operator<( const  Interval & it )
  {return (end - begin )<(it.end - it.begin);}
};

Interval find_max( int left, int right, const string & str )
{
        Interval range; 

        while( left >= 0 && right < str.size() && str[left] == str[right] )
               { left--; right++; }
        //so the left+1, right -1 will be palindrom
        left++;right--;
        if( left <= right && right - left + 1 > range.end - range.begin )
            {range.begin = left, range.end = right + 1 ;}
        return range;          
}

Interval get_max_palindrome_mid( const string & str )
{
         Interval range;
         //assume i is the mid of palindrom
         for( int i = 0; i < str.size(); i++ )
         {
              Interval temp_range;
              //case when odd, this one and previous one is the center
              temp_range = find_max( i - 1, i, str );

              if(  range  < temp_range )
                  range = temp_range;
              //case when even, this one and previous one is the center             
              temp_range = find_max( i - 1, i + 1, str );

              if(  range  < temp_range )
                  range = temp_range;
         }
         return range;
}

Interval get_max_palindrome_bf( const string & str )
{
    Interval range;
    //loop from the begin to the end, and find the max palindrom at each point
    for( int i = 0; i < str.size() ; i++ )
    {
        //to check a palindrom begin at i, with a length j
        for( int j = 1; j < MAX_PALINDROM && i + j <= str.size(); j++ )
        {
            int begin = i;
            int end = i + j - 1;
            while( begin < end 
                   && str[begin] == str[end] )
                {begin++; end --;}
            //if got it, update the palindrom
            if( begin >= end  && j >  range.end - range.begin )
                {
                      range.begin = i;
                      range.end = i + j;
                }
        }
    }

    return range;
}


int main() {
    ofstream fout ("calfflac.out");
    ifstream fin ("calfflac.in");
    
    //input the data
    int n = 0;
    char ch;
    while( fin.get(ch) )
           A[n++] = ch;   
    A[n] = '\0';

    int dump_idx = 0;
    //stripe out the nonalpha char, and build the map
    for( int i = 0; i < n; i++ )
        if( isalpha( A[i] ) )
        {   
            if( A[i] >='A' && A[i] <= 'Z' )
                A_dump[ dump_idx ] = A[i] - 'A' + 'a';
            else 
                 A_dump[ dump_idx ] = A[i];
            map[ dump_idx ] = i;
            dump_idx++;
        }
        
    A_dump[dump_idx] = '\0';
    
    //get the palindrome
    Interval range = get_max_palindrome_mid( string(A_dump) );
    fout<<range.end - range.begin<<endl;
    range.begin = map[ range.begin ];
    range.end = map[ range.end - 1] + 1;
    fout<< string(A).substr( range.begin, range.end - range.begin )<<endl ;
    

    fout.close();
    fin.close();

#ifdef __DEBUG__
    cin.get();
#endif
    return 0;
}
