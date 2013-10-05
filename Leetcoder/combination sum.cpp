class Solution {
public:
    void generate( int candidate[], int n, int A[], int pos,  int target, vector<vector<int>> & result )
         {
                     //test if end
                     if( target < 0 ) 
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
                          //for the candidate is sorted
                          if( target - candidate[i] < 0 )
                              break;
                          
                          //generatre next
                          A[pos] = candidate[i];                          
                          generate( candidate + i , n - i, A, pos + 1, target - candidate[i], result );
                          
                          //recover
                          // do nothing                          
                     }           
         }   
       
       
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int* candidates_bak = new int[candidates.size()];
        for( int i = 0; i < candidates.size(); i++ )
             candidates_bak[i] = candidates[i];
        sort( candidates_bak, candidates_bak + candidates.size() );
        
        int * A = new int[target];
        
        vector<vector<int> > ret;
        
        generate( candidates_bak, candidates.size(), A, 0, target, ret );
        
        return ret;
    }
};
