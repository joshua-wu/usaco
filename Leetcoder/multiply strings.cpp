#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
//bug need not to reverse the string
class Solution {
public:
    string add( const string & num1, const string & num2 )
    {
     //hrere we require that num1 >= num2
     if( num1.size() < num2.size() )
         return add( num2, num1);
           
     int carry = 0;
     string result; 
     int sum_value ;
     for( int i = 0; i < num1.size(); i++ )
     {
          sum_value = num1[i] - '0'  + carry;
          sum_value += (i >= num2.size())?0:num2[i]-'0';
          carry = sum_value / 10;
          sum_value = sum_value % 10;
          result += sum_value + '0';      
     }    
     
     if( carry > 0 )
         result += carry + '0';
   
       return result;
    }   
    
    string multiply( string num1, int n )
    {
    //hrere we require that num1 >= num2
           
     int carry = 0;
     string result; 
     int value ;
     for( int i = 0; i < num1.size(); i++ )
     {
          value = (num1[i] - '0') * n  + carry; //bug here, miss ()
          carry = value / 10;
          value = value % 10;
          result += value + '0';      
     }
    
    if( carry > 0 )
        result += carry + '0';
    return result;
   }    
       
    string multiply1(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        reverse( num1.begin(), num1.end() );
        reverse( num2.begin(), num2.end() );
        string result;
        string right_zero;
        for( int i = 0; i < num2.size(); i++ )
        {  
             result = add( result, right_zero + multiply( num1, num2[i]-'0')  );
             right_zero +='0';
        }
        
        int idx;
        for( idx = result.size()-1; idx>0; idx--)
             if( result[idx] !='0')
                 break;
        result = result.substr( 0, idx + 1 );
        
        reverse( result.begin(), result.end() );
        return result;
    }
    
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        reverse( num1.begin(), num1.end() );
        reverse( num2.begin(), num2.end() );
        
        vector<int> result( num1.size() + num2.size() + 2 , 0 );
        for( int i = 0; i < num1.size(); i++ )
             for( int j = 0; j < num2.size();j++ )
                  result[ i + j ] += (num1[i] - '0')* (num2[j] - '0' ); //bug num2[i] should be num2[j]

                  
        //now to get the char
        int carry = 0;
        ostringstream oss;
        for( int i = 0; i < result.size(); i++ )
        {
             oss<< (result[i] + carry ) % 10;
             carry =  (result[i] + carry )/ 10;
        }     
        
        //remove the leading zero
        string ret = oss.str();
        int idx;
        for( idx = ret.size()-1; idx>0; idx--) //key idx >0
             if( ret[idx] !='0')
                 break;
        ret = ret.substr( 0, idx + 1 );
        
        reverse( ret.begin(), ret.end() );
        return ret;        
    }
    
};

int main()
{
    Solution s;
    cout<<s.multiply( "98", "9")<<endl;
    cin.get();
}
