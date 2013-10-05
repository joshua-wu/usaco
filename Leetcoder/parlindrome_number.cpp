class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //find the leftest bit
        //for the IMT_MAX is less than INT_MIN

        
        if( x < 0 )
            return false;
        
        
        
        int max_bit = 1;
        while( x / max_bit >= 10 )
        {
            max_bit *= 10;
        }
        
        //compare from both side
        int l = 1;
        int r = max_bit;
        while( l < r )
        {
            //test if this two bit equal
            if( ( x / l )%10 != (x/r)%10 ) 
                return false;
            l *= 10;
            r /= 10;
        }
        return true;
    }
};
