//template

/*
ID: wujian.1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

using namespace std;


int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

    //get the num of beads
    int n;
    fin>>n;
    //allocate the memory
    char * beads = new char[n];
    //to read it
    for( int i = 0; i < n; i++)
         fin>>beads[i];
    //now to split by each point
    int max_split_num = -1;

    for( int i = 0; i < n; i++)
    {
    //split i is in the left of the point i,   |i
     //count the left
     int left = ( i -1 + n ) %n;
     int left_count = 0;
     char lcolor = beads[ left ];
     while( ( beads[ left ] == lcolor || beads[ left ] == 'w' || lcolor == 'w' )&& left_count < n)
      {
             //updata the base lcolor
             if( lcolor == 'w' && beads[left] != 'w' )
                 lcolor = beads[left];
             left_count++;
             left = ( left - 1 + n ) % n;
      } 
      
      //check whether all are in the same color
      if( left_count == n )
      {
          max_split_num = n;
          break;
      }
      
      int right = i;
      int right_count = 0;
      char rcolor = beads[ right ];
      while( beads[ right ] == rcolor || beads[ right ] == 'w' || rcolor == 'w')
      {
             if( rcolor == 'w' && beads[right] != 'w' )
                 rcolor = beads[right];
             right_count++;
             right = ( right + 1 ) % n;
      }
      
      max_split_num = max_split_num > (left_count + right_count)?max_split_num:(left_count + right_count );
      if( max_split_num > n )
          max_split_num = n;
    }
    
    fout<<max_split_num<<endl;  
    
    delete[] beads;
    
    fin.close();
    fout.close();

    return 0;
}
