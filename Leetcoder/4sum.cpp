#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:   
    vector<vector<int> > fourSum(vector<int> &num, int target) {         
         vector<vector<int> > result;        
         vector<int> cur_result( 4, 0 );
             
         sort(num.begin(), num.end());    
                           //bug here
         for( int i = 0;i < int(num.size()) - 3; i++ )
         {
              
              if( i != 0 && num[i] == num[i - 1] ) 
                  continue;
              for( int j = i + 1; j < int(num.size()) - 2; j++ )
              {
                   //now to find 2sum
                   //bug here
                   if( j != i+1 && num[j] == num[j -1] )
                       continue;
                       
                   //now to find the 2sum in j + 1, sum.size
                   int l = j+1;
                   int r = num.size() - 1;
                   int cur_sum ;
                   while( l < r )
                   {
                          if( l != j+1 && num[l] == num[l-1] )
                          {
                                  l++;
                                  continue;
                          }
                          
                          if( r != num.size() - 1 && num[r] == num[r+1] )
                          {
                                  r--;
                                  continue;
                          }                         
                                  
                          cur_sum = num[l] + num[r] + num[i] + num[j];
                          if( cur_sum < target )
                          {
                              l++;
                          }
                          else if( cur_sum > target )
                          {
                              r--;
                          }
                          else
                          {
                              //equal
                              cur_result[0] = num[i];
                              cur_result[1] = num[j];
                              cur_result[2] = num[l];
                              cur_result[3] = num[r];
                              result.push_back( cur_result );
                              
                              //and 
                              l++;
                              r--;
                          }                                       
                   }
              }
         }
         
         return result;
    }
};


int main()
{
    Solution * p = new Solution();
    vector<int> a;
    a.push_back( 0 );
    a.push_back( 0 );
    a.push_back( 0 );
    a.push_back( 0 );
    cout<<a.size()<<endl;
    cout<<p->fourSum(a,0).size()<<endl;
}
