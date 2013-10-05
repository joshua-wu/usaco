class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int mvalue[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string> svalue = { "I","IV","V", "IX","X", "XL", "L", "XC", "C", "CD", "D",  "CM", "M"};
        
        string two_char;
        int result = 0;
        int i = 0;
        while( i < s.size()  )
        {
             //judge that current and the next combine is in the svalue or not
             two_char = s.substr( i, 2 );

             //get the index of the svalue
             int found_two = -1;
             int found_one = -1;
             for( int j = 0; j < svalue.size() && found_two < 0 ; j++ )
                  if( svalue[j] == two_char )
                      found_two = j;
                  else( svalue[j] == s[i] )
                      found_one = j;  
             if( found_two >= 0 )
             {
                result += mvalue[found_two];
                i +=2; 
             }
             else 
             {
                result += mvalue[found_one];
                i++;     
             }
        }
        
        return result;
    }
};
