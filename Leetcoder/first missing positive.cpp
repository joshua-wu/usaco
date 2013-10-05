class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //let out the negtive and the one bigger than n
        int i = 0;
        while( i < n )
        {
               //put the ith element to the next place
               if( A[i] >= 1 && A[i] < n + 1
               && A[i] != i + 1 // A[i] is not in the right place
               && A[A[i]-1] != A[i]) //A[A[i] -1] is not in the right place, this is because dump, eg:[1,1]
                      swap( A[i], A[A[i] - 1] );
               else
                   i++;
        }
        
        int nx;
        for( nx = 1; nx < n + 1 ; nx++ )
             if( A[nx-1] != nx )
                 break;
        return nx;    
    }
};
