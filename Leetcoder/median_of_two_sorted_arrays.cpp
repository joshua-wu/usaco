#include<iostream>
using namespace std;


class Solution {
public:
    //find the k-th
    int get_the_num( int k, int A[], int m, int B[], int n )
    {
        if( m == 0 )
            return B[k-1];
        
        if( n ==  0 )
            return A[k-1];
            
         if( k == 1 )
             return min( A[0], B[0] );
             
         if( m == 1 && n == 1 )
             if( k == 1 )
                 return min( A[0], B[0] );
             else
                 return max( A[0], B[0] );
  
        
        //now both array are not zero and need to find the kth
        int mid_a = m / 2;
        int mid_b = n / 2;
        if( A[mid_a] < B[mid_b] )
            return get_the_num( k, B, n , A, m );
        
        
       //( A[mid_a] >= B[mid_b] )

            // A: ---mid_a----
            // B: ----mid_b----
            ////half open interval, not include. k is the index,so k meaning that there are 
            //n/2 + m/2 + 2 element in the left of index k
        if( k > n/2 + m/2 + 1   ) 
        {  //there are at least n/2 + m/2 + 1 point less than a and include b
             return get_the_num( k -  n/2 - 1  , A, m , B + n/2 + 1 , n - n/2 - 1 );               
        }
        else //if ( k < n/2 + m/2 )//A:[0,m/2) [0,n/2]
        {
             return get_the_num( k, A, m/2, B, n );
        } 

    }
       
       
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // get the median of the two array
        return 0.5 *(get_the_num( (m+n)/2, A, m, B,n) + get_the_num( (m+n-1)/2, A, m, B, n));   
    }
    
    double findMedianSortedArrays_t(int A[], int m, int B[], int n,int t) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // get the median of the two array
        return get_the_num( t, A, m, B, n );  
    }
};

int main()
{
    Solution * p = new Solution();
    
    int A[] = { 1};
    int B[] = {2,3};
    int m = sizeof(A)/sizeof(int );
    int n = sizeof(B)/sizeof( int );
    for( int i = 1;i <= m + n; i++ )
         cout<<p->findMedianSortedArrays_t( A, m, B, n, i )<<endl;
    cin.get();
    return 0;
}
