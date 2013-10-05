class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int rx = 0;
        int pn =  x > 0?1:-1;
        //now reverse each 
        x = abs( x );
        while( x > 0 )
        {
            rx *= 10;
            rx += x%10;  
            x /= 10;
        }
        
        
        return rx * pn;
    }
};


//what if the integer overflow
//1. using a long long or a float to store the copy of the num
//then test if to num are equal( attention that float num can not compare equal or not 
//they just want to in the smme range x2 - x1 < 1e6 )
//2. test if x > INT_MAX divide 10, if max than it, if equal , then compare the last bit of it
