class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0;
        int r = n-1;
        while(1)
        {
            //move l
            while( l <= r && A[l] != elem )
                l++;
            //foudn one 
            while( r >= l && A[r] == elem )
                r--;
            
            if( l > r )
                break;
            
            swap( A[l], A[r] );
            l++;
            r--;
        }
        
        return l;
    }
};
