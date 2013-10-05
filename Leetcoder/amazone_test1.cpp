#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
using namespace std;

string clockwise(int size) {
       
       string str_out;
       for( int x = 0; x < size;x++ )
       {
            for( int y = 0; y < size; y++ )
            {
                 if( x == 1 && y == 0 )
                     int k = 3;
                 
                 int center = size/2;
                 int dd = max( abs( x - size/2 ), abs( y - size/2 )  );
                 int size_inner = (2*dd -1 ) *(2*dd-1);
                 //judge the index and 4 base point
                 int l = center - dd;
                 int r = center + dd; 
                 int u = center - dd;
                 int d = center + dd;
                 
                 int result = size_inner;
                 //the first
                 if( y == r && x >u )
                 {
                     //the first
                     result += x - (u + 1 ) + 1;
                 }
                 else if( y == l && x < d )
                 {
                      //the third
                      result += 2 * 2*dd + ( d - 1 ) - x + 1; 
                 }
                  else if( x == u && y > l )
                  {
                       //the forth
                       result += 3*2*dd + y - ( l + 1 ) + 1;
                   }
                   else if( x == d && y < r )
                   {
                        //the second
                        result += 2*dd + (r - 1 ) - y + 1;
                   }
                   else
                   {//in the middle
                       // result += 1; 
                   }
                 ostringstream oss; 
                 oss<<result; 
                 str_out += oss.str();
                 if( y != size - 1 )
                     str_out += '*';
                 
            }
            str_out += '\n';
       }
       
       return str_out;
                 

}


int main()
{
    for( int i = 1; i < 10; i+=2 )
    {
              cout<<clockwise(i);
              cin.get();
    }
    cin.get();
    cin.get();
    return 0;
}
