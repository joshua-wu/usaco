class Solution {
public:
    int upper_bound( int A[], int n , int target )
    {
        int l = 0; 
        int r = n;
        int mid;
        while( l < r )
        {
               mid = l + ((r-l)>>1);
               if( A[mid] > target )
                   r = mid ;
               else//A[mid} <= target
                   l = mid + 1;
        }
        
        return r;
    }
    
    int lower_bound( int A[], int n, int target )   
    {
        int l = 0; 
        int r = n;
        int mid;
        while( l < r )
        {
               mid = l + ((r-l)>>1);
               if( A[mid] >= target )
                   r = mid ;
               else//A[mid} < target
                   l = mid + 1;
        }
        
        return r;        
    }
       
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret(2,0);
        ret[0] =  lower_bound( A, n, target );
        ret[1] =  upper_bound( A, n, target ) - 1;
        if( ret[0] == n || A[ret[0]] != target )
            ret[0] = -1;
        if( ret[1] == -1 || A[ret[1]] != target )
            ret[1] = -1;
        return ret;
    }
};
