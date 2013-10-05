class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int mvalue[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        char * svalue[] = { "I","IV","V", "IX","X", "XL", "L", "XC", "C", "CD", "D",  "CM", "M"};
        
        string result;
        int idx = 12;
        while( num > 0 )
        {
             if( num >= mvalue[idx] )
             {
                 num -= mvalue[idx];
                 result += svalue[idx];
             }
             else
             {
                 idx--;
             }
        }
        
        return result;
        
    }
};
