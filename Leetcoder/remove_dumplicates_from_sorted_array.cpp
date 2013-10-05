class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //count form the begin to the end
        //test case {1,1,2}
        //test case {1,1,1}
        //test case {}
    
        int count = 0;
        for( int i = 0; i < n ; i++ )
        {
            //to test if there is a new element appearance
            if( i == 0 || A[i] != A[i-1] )
                A[count++] = A[i];            
        }
        
        return count;
    }
};
