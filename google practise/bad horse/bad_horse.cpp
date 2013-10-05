//bad hourse
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<fstream>
#include<string.h>
using namespace std;


#define MAX_ELEM  120
int graph[MAX_ELEM][MAX_ELEM];
bool visit[MAX_ELEM];
int set_value[MAX_ELEM];

void dfs( int node , int size_node )
{
     visit[node] = true;
     //dfs his neighbour
     for( int i = 0; i < size_node; i++ )
          if( !visit[i]  && graph[node][i] == 1)
          {
             set_value[i] = set_value[node]==1?0:1;//set different 
             dfs( i, size_node );
          }
}

int main()
{
   //read in the case and map the string to node, modify it 
   // dfs the graph to see how many component it contain
   string file_name = "A-small-2-attempt0";
   ifstream ifs( (file_name + ".in").c_str());
   ofstream ofs( (file_name + ".out").c_str());
   int n;
   ifs>>n;
   for( int i =0; i < n; i++ )
   {
        //init the graph and the visit and the set
        memset( visit, 0, sizeof( visit ));
        memset( graph, 0, sizeof( graph ));
        memset( set_value, 0, sizeof( set_value ));
        
        int pair_size;
        ifs>>pair_size;
        string name_a, name_b;
        map<string,int> name2id; //map string to id
        for( int j = 0; j < pair_size; j++ )
        {
             ifs>>name_a>>name_b;
             
             int size_of_current;
             size_of_current = name2id.size();             
             if( name2id.find( name_a ) == name2id.end() )
                 name2id[name_a] = size_of_current;
             size_of_current = name2id.size();
             if( name2id.find( name_b ) == name2id.end() )
                 name2id[name_b] = size_of_current;
             
             //now deal with the graph
             int node1 = name2id[name_a];
             int node2 = name2id[name_b];
             graph[node1][node2] = graph[node2][node1] = 1;             
        }     
        
        //now dfs and find the conponent
        for(int j = 0; j < name2id.size(); j++ )
           if( !visit[j] )
           {
               set_value[j] = 1;
               dfs( j, name2id.size());     
           }
           
        //now check consist
        bool consist = true;
        for( int j =  0; j < name2id.size() && consist; j++ )
             for( int k = j + 1; k < name2id.size() && consist ; k++ )
                  if( graph[j][k] == 1 && set_value[j] == set_value[k] )
                      consist = false;

              
        ofs<<"Case #"<<i+1<<": ";   
        if( consist  ) 
            ofs<<"Yes";
        else 
             ofs<<"No";
        ofs<<endl;
   }  
   
   return 0;
   
}
