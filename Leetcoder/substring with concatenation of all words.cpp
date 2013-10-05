#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

//bug not consider that one string may appear twice in the L
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        if( L.size() == 0 )
            return result;
            
        vector<int> count;
        map<string,int> str2idx;
        for( int i = 0; i < L.size(); i++ )
        {
             if( str2idx.find( L[i]  ) == str2idx.end() )
             {
                 int len = str2idx.size();
                 str2idx[L[i]] = len;
                 count.push_back( 1 );
             }
             else
             {
                 count[str2idx[L[i]]]++;
             }               
        }
        
        
        //for( int i = 0; i < count.size(); i++ )
        //     cout<<count[i]<<" ";
        //cout<<endl;
        
        int single_str_len = L[0].size();
        int pattern_size = single_str_len * L.size();
        
        //preprocess
        vector<int> idx;
        for( int i = 0; i + single_str_len <= S.size(); i++ )
        {
              string pattern = S.substr( i, single_str_len );
              if( str2idx.find( pattern  ) == str2idx.end() )
                  idx.push_back( -1 );
              else
                  idx.push_back( str2idx[pattern] );
        }
        
        //for( int i = 0; i < idx.size(); i++ )
        //     cout<<idx[i]<<" ";
        //cout<<endl;
        //bug here ,L.size() -1 ; not L.size()
        for( int i = 0; i + (L.size()-1) * single_str_len < idx.size() ; i++ )
        {
             vector<int> copy_count = count;
             //to test whether every string are in
             bool suc = true;
             for( int j = i;  j < i + L.size() * single_str_len && suc; j+=single_str_len)
             {
                  //bug the next line:not add i 
                  //optimize here, we can compare less time
                  if( idx[j] == -1 || copy_count[ idx[j] ] == 0)
                      suc = false;           
                  else            
                      copy_count[ idx[j] ]--;
              }
              //cout<<suc<<"("<<copy_count[0]<<","<<copy_count[1]<<")";
              if( !suc  )
                  continue;
              
              //test if all true
              bool all = true;

              for(int k = 0; k < copy_count.size(); k++ )
                   if( copy_count[k] != 0 )
                       all = false;


              if( all )
                 result.push_back( i );
         }
        
        return result;
    }
};


int main()
{
    Solution s;
    vector<string> L;
    L.push_back( "foo");
    L.push_back( "bar" );
    map<string,int> mp;
    cout<<mp["at"]++<<endl;
    cout<<s.findSubstring("barfoothefoobarman", L).size()<<endl;

    
    cin.get();
    return 0;
}
