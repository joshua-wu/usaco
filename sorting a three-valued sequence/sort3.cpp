/*
ID: wujian.1
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include<vector>
#include<algorithm>
using namespace std;

int tb[3][3];
int ct[4];//cumlated count
int A[1024];

int main() {
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");
    
    int n;
    fin>>n;
    for( int i = 0; i < n; i++ )
    {
           fin>>A[i];
           ct[A[i]]++;
    }
    
    //fill the count table
    ct[0] = 0;
    for( int i = 1; i <=3; i++ )
         ct[i] += ct[i-1];

    for( int i =0; i < 3; i++ )
         for( int j = ct[i]; j < ct[i+1]; j++ )
              tb[i][A[j]-1]++;
    
    int cost = 0;
    int min_switch;
    for( int i = 0;i < 3; i++ )
         for( int j = i+1; j < 3; j++ )
         {
              min_switch =  min( tb[i][j], tb[j][i] );
              cost += min_switch;
              tb[i][j] -= min_switch;
              tb[j][i] -= min_switch; 
         }
         
    cost += (tb[0][1] + tb[0][2])*2;  
    fout<<cost<<endl;
    return 0;
}
