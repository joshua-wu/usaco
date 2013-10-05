 class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //invariance [0,l) will contain no elem
        int j = 0;
        for( int i = 0; i < n; i++ )
             if( A[i] != elem )
             {
                 //not equal
                 swap( A[i], A[j] );
                 j++;
             }
        
        return j;
    }
};


class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0;
        int r = n - 1;
        //invariance [0,l) will contain no elem
        while( 1 )
        {
               while( l <= r && A[l] != elem )
                      l++;
               while( l <= r && A[r] == elem )
                      r--;
               if( l >= r )
                   return l;
               
               swap( A[l], A[r] );
               l++;
               r--;
        }
        
    }
};
