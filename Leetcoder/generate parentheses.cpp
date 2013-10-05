 class Solution {
public:
    void generate( int l, int r, char A[], int pos, vector<string> & result )
    {
         if( l == 0 && r == 0 )
         {
             result.push_back( A );
             return; 
         }     
         
         //generate all next 
          if( l > 0 )
         {
               A[pos] = '(';
               generate( l -1, r, A, pos + 1 , result );
         }
         
         if( l < r )
         {
               A[pos] = ')';
               generate( l, r-1, A, pos + 1 , result );
         }       
         
    }
       
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
        char * A = new char[2*n+1];
        A[2*n] = '\0';
        generate( n, n ,A, 0, result );
        return result; 
    }
};
