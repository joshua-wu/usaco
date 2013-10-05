//template

/*
  ID: wujian.1
  PROG: packrec
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <assert.h>     /* assert */

using namespace std;

#define __DEBUG__

#define INF 99999


pair<int,int> cal_1( const vector<pair<int,int> > & recs )
{
    int idx_of_max = 0;
    for ( int i = 1; i < recs.size(); i++ )
        if( recs[i].second > recs[idx_of_max].second ) idx_of_max = i;
    return make_pair( recs[0].first + recs[1].first + recs[2].first + recs[3].first, 
                  recs[idx_of_max].second );
                      
}

pair<int, int> cal_2( const vector<pair<int,int> > & recs )
{
    
    return make_pair( max( recs[0].first + recs[1].first + recs[2].first, recs[3].first ), max( max(recs[0].second, recs[1].second), recs[2].second) + recs[3].second );
}

pair<int,int> cal_3( const vector<pair<int,int> > & recs )
{
    return make_pair( max( recs[0].first + recs[1].first, recs[3].first ) + recs[2].first, max(  max(recs[0].second, recs[1].second ) + recs[3].second , recs[2].second ));
}

pair<int,int> cal_4( const vector<pair<int,int> > & recs )
{
    return make_pair( recs[0].first + max(recs[1].first, recs[2].first) + recs[3].first, 
                      max( max( recs[0].second, recs[3].second ), recs[1].second + recs[2].second));
}

pair<int,int> cal_6( const vector< pair<int,int> > & recs )
{
    int dia_hor_opp = recs[1].first + recs[2].first;
    int dia_ver_opp = recs[1].second + recs[2].second;
    //here is very trick
    //1.situation if the diagonal's sum are both bigger than the horizon and vetical
    int horizon = max(recs[0].first + recs[1].first, recs[2].first + recs[3].first );
    int vertical = max(recs[0].second + recs[2].second, recs[1].second + recs[3].second);
    int dia_hor = recs[0].first + recs[3].first;
    int dia_ver = recs[0].second + recs[3].second;
    if( dia_hor_opp > horizon && dia_ver_opp > vertical )
        return make_pair( INF, INF );
    
    
    if( dia_hor > horizon && dia_ver > vertical )
    {
        //to find the less one
        int a1 = horizon;
        int b1 = dia_ver;
        int a2 = dia_hor;
        int b2 = vertical;
        if( a1 * b1 < a2 * b2)
            return make_pair( a1, b1 );
        else
            return make_pair( a2, b2 );
    }
    else
    {
        return make_pair( horizon, vertical );
    }
}

int deal_with_result( int min_pack, pair<int,int> result, vector<pair<int,int> > & solution)
{
      if( result.first * result.second == min_pack )
        {
            //check if the solution exist
            if( result.first > result.second ) 
                swap( result.first, result.second );
            
            //now to find
            bool found = false;
            for( int i = 0; i < solution.size(); i++ )
            {                 
               if( solution[i] == result )
                { 
                    found = true;
                    break;
                }
            }

            if( !found )
                solution.push_back( result );

        }
        else if( result.first * result.second < min_pack )
        {
            min_pack = result.first * result.second;
            //find a new minimal, update
            solution.clear();
            if( result.first > result.second ) 
                swap( result.first, result.second );
            solution.push_back( result );
        }
        


        return min_pack;
}


int generate_and_test( vector<pair<int,int> > & recs, vector<pair<int,int> >  packs, int size, bool used[] , int min_pack, vector<pair<int,int> > & solution )
{
    if( size == 4 )
    {
        //calculate
        pair<int,int> result;
        result = cal_1( recs );
        min_pack = deal_with_result( min_pack, result, solution );
        if( result.first * result.second == 288 )
            for( int i = 0; i < 4 ; i++ )
                 cout<<recs[i].first<<" "<<recs[i].second<<endl;
        
        result = cal_2( recs );
        min_pack = deal_with_result( min_pack, result, solution );
        if( result.first * result.second == 288 )
            for( int i = 0; i < 4 ; i++ )
                 cout<<recs[i].first<<" "<<recs[i].second<<endl;
        
        result = cal_3( recs );
        min_pack = deal_with_result( min_pack, result, solution );
        if( result.first * result.second == 288 )
            for( int i = 0; i < 4 ; i++ )
                 cout<<recs[i].first<<" "<<recs[i].second<<endl;
        
        result = cal_4( recs );
        min_pack = deal_with_result( min_pack, result, solution );
        if( result.first * result.second == 288 )
            for( int i = 0; i < 4 ; i++ )
                 cout<<recs[i].first<<" "<<recs[i].second<<endl;
        
         result = cal_6( recs );
        min_pack = deal_with_result( min_pack, result, solution );
        if( result.first * result.second == 288 )
            for( int i = 0; i < 4 ; i++ )
                 cout<<recs[i].first<<" "<<recs[i].second<<endl;
        
        return min_pack;
    }


    //now to generate the next
    for( int i = 0; i < packs.size(); i++ )
    {
        if( used[i] )
            continue;
        //now to generate it
        recs[size] =  packs[i] ;
        used[ i ] = true;
        min_pack = generate_and_test( recs, packs, size + 1, used, min_pack, solution );
        swap( recs[size].first , recs[size].second );
        min_pack = generate_and_test( recs, packs, size + 1, used, min_pack, solution );
        
        //recover
        used[ i ] = false;
    }
    return min_pack;
}




int main() {
    ofstream fout ("packrec.out");
    ifstream fin ("packrec.in");
    
    //begin to input
    vector<pair<int,int> > recs(4);
    vector<pair<int,int> > packs(4);
    vector<pair<int,int> > solution;
    for( int i = 0; i < 4 ; i++ )
        fin>>packs[i].first>>packs[i].second;
    
    bool used[4];
    for( int i = 0; i < 4; i++ ) 
        used[i] = false;
    
    int min_pack = generate_and_test( recs, packs, 0, used, INF, solution);
    
    sort( solution.begin(), solution.end() );
    
    fout<<min_pack<<endl;
    for( int i = 0; i < solution.size();i++ )
        fout<<solution[i].first<<" "<<solution[i].second<<endl;

    
    //some clean work
    fout.close();
    fin.close();

#ifdef __DEBUG__
    cin.get();
#endif
    return 0;
}

