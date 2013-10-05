#include<iostream>
using namespace std;
class Solution_rec {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if( n == 0 )
            return -1;

        int l = 0;
        int r = n - 1;
        int m = n/2; 
        
        //deal with only one case        
        if( A[m] == target )
            return m;
         
        int result;
        if( A[r] >= A[m] )
        {
            if( target >= A[m] && target <= A[r] )
            {
                result = search( A+m, n - m , target );
                return result == -1?-1:result + m;
            }
            else
            {
                result = search( A, m, target );
                return result;
            }
        }
        else
        {
            if( target >= A[0] && target <= A[m] )
            {
                result = search( A, m + 1 , target );//here is why we need to porcess the 1 element
                return result;
            }
            else
            {
                result = search( A + m + 1, n - m - 1, target );
                return result==-1?-1:result + m + 1;
            }
        }
    }
};

class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if( n == 0 )
            return -1;
            
       
        int l = 0;
        int r = n ;
        int m ; 
        //here m can not be (l+r)>>2 or it will bug, because when there are two element
        //m and l point to the same 
        
        while( l < r )
        {
               m = l + ( r - l ) /2; //here is very easy to get a bug: ((r-l)>>2) because >> is very low priority
               if( A[m] == target ) return m; //deal well when only 1 case
               
               if( A[l] <= A[m] )
                   if( target >= A[l] && target < A[m] )
                       r = m;
                   else//[m,r)
                       l = m + 1;
               else //[m,r) is sorted
                   if( target > A[m] && target <= A[r-1] )
                       l = m + 1;
                   else //[0,m-1)
                       r = m;            
        }
        
        return -1;
    }
};



int main()
{
    int A[] = {4,5,6,7,0,1,2};
    Solution s;
    cout<<s.search( A, 7, 0 )<<endl;
    cin.get();
}
