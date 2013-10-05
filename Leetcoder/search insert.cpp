class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // get the uppper bound
        int l = 0; 
        int r = n;
        int m;
        while( l < r )
        {
            m = l + (( r - l )>>1);
            if( A[m] > target )
                r = m;
            else
                l = m + 1;
        }
        
        if( r != 0 && A[r-1] == target )
            r = r-1;
        return r;
    }
};
