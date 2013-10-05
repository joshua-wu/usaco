class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //1.find the one from the right to the left, unitl first drop
        int idx_i = -1;
        for( int i = num.size() -1; i > 0; i-- )
            if( num[i] > num[i-1])
            {
                idx_i = i-1;
                break;
            }
            
        if( idx_i == -1 )
        {
            reverse( num.begin(), num.end() );
            return;
        }
        
        //now to find j
        int idx_j = -1; //bug here set idx_j to the last so the (2,3,1) will not pass
        for( int i = num.size()-1; i > idx_i; i-- )
            if( (idx_j== -1 || num[i] < num[idx_j]) && num[i] > num[idx_i] )
                idx_j = i;
        
        //now to swap
        swap( num[idx_i], num[idx_j] );
        reverse( num.begin() + idx_i + 1, num.end() );            
    }
};
