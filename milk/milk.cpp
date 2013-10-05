//template

/*
ID: wujian.1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <assert.h>     /* assert */

using namespace std;

//#define __DEBUG__



int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    
    int milk_needed, num_of_farmer;
    fin>>milk_needed>>num_of_farmer;
    
    vector<pair<int,int> > price_production_vct( num_of_farmer );
    
    for( int i = 0; i < num_of_farmer; i++ )
         fin>>price_production_vct[i].first>>price_production_vct[i].second;
    
    sort( price_production_vct.begin(), price_production_vct.end() );
    
    int now_need = milk_needed;
    int cost = 0;
    for( int i = 0; i < price_production_vct.size() && now_need > 0; i++ )
    {
         int bought = price_production_vct[i].second;
         if( now_need <  bought )
             bought = now_need;

                       ;
         cost += bought * price_production_vct[i].first;
         now_need -= bought;  
      
    }
    
    fout<<cost<<endl;
         

#ifdef __DEBUG__
    cin.get();
#endif
    return 0;
}

