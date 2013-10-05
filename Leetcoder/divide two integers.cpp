#include<iostream>
using namespace std;

class Solution1 {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( divisor == 0 || dividend == 0)
            return 0;
        
        
        int sign =  (dividend>0?1:-1) * (divisor>0?1:-1) >0?1:-1;
        unsigned result = 0;
        unsigned count = 1;
        long long de = dividend ;
        long long d = divisor;
        de = abs(de);
        d = abs(d );
        while( d * 2 <= de )
        {
            d *= 2;
            count *=2;
        }
        
        
        //now to get the result
        while( d >= dividend )
        {
            if( de - d >= 0 )
            {
                de -= d;
                result += count;
            }
            d /= 2;
            count /= 2;
        }
        //余数是当前的de 
        
        
        
        return result*sign;
    }
};


//great code
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = abs((double)dividend);;
        long long b = abs((double)divisor);

        long long ret = 0;
        while (a >= b) 
        {
            long long c = b;
            //delete as more as possible
            for (int i = 0; a >= c; ++i, c <<= 1) 
            {
                a -= c;
                ret += 1 << i;
            }
        }

        return ((dividend^divisor)>>31) ? (-ret) : (ret);
    }
};



int main()
{
    Solution s;
    cout<<INT_MAX<<endl;
    cout<<s.divide(1, -1)<<endl;
    cin.get();
}
