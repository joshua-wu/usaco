 class Solution {
public:
        void generate( int candidate[], int n,   int A[], int pos,  int target, vector<vector<int>> & result )
         {
                     //test if end
                     if( target < 0  ) 
                         return;
                     if( target == 0 )
                     {
                         vector<int> solution;
                         for( int i = 0;i < pos; i++ )
                              solution.push_back( A[i] );
                         result.push_back( solution);
                         return;
                     }
                     
                     
                     //now to generate the next
                     for( int i = 0; i < n; i++ )
                     {
                          if( i != 0 && candidate[i-1] == candidate[i] )
                              continue;
                          //now to see if this one has been used out or not
                          //or use it
                          //for the candidate is sorted
                          if( target - candidate[i] < 0 )
                              break;
                          
                          //generatre next
                          A[pos] = candidate[i];                          
                          generate( candidate + i + 1 , n - i - 1, A, pos + 1, target - candidate[i], result );
                          //recover
                          // do nothing                          
                     }           
         }   
          
       
       
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        int* candidates_bak = new int[num.size()];
        for( int i = 0; i < num.size(); i++ )
             candidates_bak[i] = num[i];
        sort( candidates_bak, candidates_bak + num.size() );
        
        int * A = new int[target];
        
        vector<vector<int> > ret;
        
        generate( candidates_bak, num.size(), A, 0, target, ret );
        
        return ret;
    }
};
