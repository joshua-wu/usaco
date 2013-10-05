class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //first to skip the white space
        if( NULL == str )
            return 0;


        //skip the white char
        while( '\t' == *str 
               || ' '  == *str
               || '\n' == *str )
            str++;
        
        //test end or not number or +,-
        if( *str =='\0'
            || !( *str == '+' || *str == '-' ||  (*str >= '0' && *str <= '9' )) )
            return 0;
        
        //convert sign
        //here can not using two if, or +-33 will pass the test
        int sign = 1;
        if( *str == '+' )
        {
            sign = 1;
            str++;
        }else if( *str== '-' )
        {
            sign = -1;
            str++;
        }
        
        //test if it is digital
        if( !( *str >= '0' && *str <= '9' ) )
            return 0;
            
        bool overflow = false;
        
        //now convert
        long long n = 0;
        while( *str != '\0' &&
               ( *str >= '0' && *str <= '9' ) 
            )
        {
            //test overflow
			//if not permit to use th long long
			//you can test 
			// sign == 1 && ( n > INT_MAX || n == INT_MAX/10 && *str-'0'>= INT_MAX%10 )
			//|| sign == -1 && ( n > -INT_MIN || n == -INT_MIN/10 && *str-'0'>= -INT_MIN%10 )
            if( sign == 1 && n > INT_MAX
				|| sign == -1 && n > - INT_MIN
                )
            {
                overflow = true;
                break;
            }
            
            n *= 10;
            n += *str - '0';
            str ++;
            
        }
        
        if( overflow )
            return sign > 0?INT_MAX:INT_MIN;
            
        return n * sign;        
        
    }
