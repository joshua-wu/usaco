class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //key to find a sorted range
        int l = 0; 
        int r = n;
        int mid;
        while( l < r )
        {
               mid = l + (( r - l )>>1 );
               if( A[mid] == target )
                   return mid;
               //now to find, [l, mid) is sorted
               if( A[l] <= A[mid] )
               {
                   //bug here, I set A[l] as A[0]
                   if( target >= A[l] && target < A[mid] )
                       r = mid;
                   else
                       l = mid + 1;
               }
               else//A[l] > A[mid]-A[end]
               {
                   if( target > A[mid] && target <= A[r - 1] )
                       l = mid + 1;
                   else
                       r = mid;
               }
        }
        
        return -1;
    }
};
