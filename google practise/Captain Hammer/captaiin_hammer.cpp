#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<fstream>
#include<string.h>
#include<math.h>
using namespace std;





int main()
{
   //read in the case and map the string to node, modify it 
   // dfs the graph to see how many component it contain
   string file_name = "B-small-attempt0";
   ifstream ifs( (file_name + ".in").c_str());
   ofstream ofs( (file_name + ".out").c_str());
   
   ofs.precision(15);
   
   double pi = atan(1)*4;
   double g = 9.8;
 
   int T, V, D;
   ifs>>T;
   for( int now_case = 1; now_case <= T; now_case++ )
   {
        
    ifs>>V>>D;
    double result= D * g / ( V * V );
    result = asin( result ) / pi * 90;

              
   ofs<<"Case #"<<now_case<<": ";   
   ofs<<result;
    ofs<<endl;
    
   }
   
   return 0;
   
}
