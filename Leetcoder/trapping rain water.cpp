class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //the water contain is depend on the right max and the left max
        int * left_max  = new int[n];
        int * right_max = new int[n];
        int max_elem = 0;
        for( int i = 0; i< n; i++ )
        {
             left_max[i] = max_elem;
             max_elem = max( max_elem, A[i] );
        }   
        
        max_elem = 0;
        for( int i = n-1; i >= 0; i-- )
        {
             right_max[i] = max_elem;
             max_elem = max( max_elem, A[i] );
        }  
        
        
        int s = 0;
        int contain = 0;
        for( int i = 0; i < n; i++ )
        {
             contain = min( left_max[i], right_max[i] ) - A[i];
             s += contain>0?contain:0;
        }
        
        return s;
    }
};





class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //the water contain is depend on the right max and the left max
        int * cur_max  = new int[n];
        int max_elem = 0;
        for( int i = 0; i< n; i++ )
        {
             cur_max[i] = max_elem;
             max_elem = max( max_elem, A[i] );
        }   
        
        max_elem = 0;
        for( int i = n-1; i >= 0; i-- )
        {
             cur_max[i] = min( max_elem, cur_max[i] );
             max_elem = max( max_elem, A[i] );
        }  
        
        
        int s = 0;
        int contain = 0;
        for( int i = 0; i < n; i++ )
        {
             contain = cur_max[i] - A[i];
             s += contain>0?contain:0;
        }
        
        return s;
    }
};

