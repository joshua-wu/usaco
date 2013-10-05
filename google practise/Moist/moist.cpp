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
   string file_name = "C-small-2-attempt0";
   ifstream ifs( (file_name + ".in").c_str());
   ofstream ofs( (file_name + ".out").c_str());
    
    int T;
    ifs>>T;
   for( int now_case = 1; now_case <= T; now_case++ )
   {
     int n;
     ifs>>n;
     vector<string> cards;
     //input the data
     string card_name;
     ifs.get();//to skip the new line
     for( int i  = 0; i < n; i++ )
     {
               getline( ifs,  card_name);
               cards.push_back( card_name );
               //cout<<card_name<<endl;
     }
     int cost = 0;
    //insert sort
    for( int i = 0; i < cards.size() - 1; i++ )
         if( cards[i] > cards[i + 1 ] )
         {
             cost++; 
             swap( cards[i], cards[i+1] );
             //move the card i + 1 to it's right place
             //card_name = cards[ i + 1];
             //find the one that is less than card_name
             //int pos = i;
             //while( pos >= 0 && cards[pos] > card_name )
             //      {
            //            cards[pos + 1] = cards[pos]; 
             //           pos--;
             //      }
             //cards[pos+1] = card_name;             
         }

              
   ofs<<"Case #"<<now_case<<": ";   
   ofs<<cost;
    ofs<<endl;
    
   }
   
   //cin.get();
   return 0;
   
}
