//template

/*
ID: wujian.1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int np =0;
    //1.get the np
    fin>>np;
    
    //get each name,and map it to a set
    vector<string> order(np); 
    //get the name and map it to the money loss
    map<string, int> name_loss;
    string name;
    for( int i = 0;i < np; i++ )
    {
         fin>>name;
         name_loss[name] = 0;
         order[i] = name;
    }
    
    //now deal with each person
    int money , to_give_num ;
    string to_recv_name, to_give_name;
    while( fin>>to_give_name )
    {
        fin>>money>>to_give_num;
        if( to_give_num == 0 )
        {   
            continue;
        }
        
        name_loss[to_give_name] -= money / to_give_num * to_give_num;
        
        for( int i = 0; i < to_give_num; i++)
        {
             fin>>to_recv_name;
             name_loss[to_recv_name] += money / to_give_num;
        }
    }
    
    //print the name and the money
    for( int i =0; i < order.size();i++)
         fout<<order[i]<<" "<<name_loss[order[i]]<<endl;

    
    fin.close();
    fout.close();

    return 0;
}
