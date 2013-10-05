class Solution {
public:
    string get_next( string str )
    {
       int count;
       int begin = 0;
       int i ;
       string ret;
       while( begin != str.size() )
       {
              //go to next, until you reach the end or the next is different
              count = 0;
              for( i = begin; i < str.size(); i++ )
              {
                   if( i ==begin || str[i-1] == str[i] )
                       count++;
                   else
                       break;                     
              }
              begin = i;
              ret += to_string( count ) + str[i-1];                    
       }
       
       return ret;
    }   
       
       
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ret = "1" ;
        for( int i = 1; i < n; i++ )
             ret = get_next( ret );
             
        return ret;
    }
};

