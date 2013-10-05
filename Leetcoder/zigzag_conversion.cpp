class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        //the first row and the last row are special
        if( nRows == 1 )
            return s;
        
        string result( s.size(), '\0');
        int idx = 0;
        //get the first row
        for( int i = 0; i < s.size(); i+= 2 * (nRows - 1 ) )
            result[idx++] = s[i];
            
        //all other except the last    
        for( int i =1;  i < nRows - 1 ; i++ )
        {
            //now to get the next until 
            int type1_gap = 2 * ( nRows - i - 1 );
            int type2_gap = 2 * i;
            bool is_type1 = true;
            int next = i;
            while( next < s.size() )
            {
                //get the char
               result[idx++] = s[next];
                //move to the next
                next += is_type1 * type1_gap + (!is_type1) * type2_gap;
                //toggole the type
                is_type1 = !is_type1;
            }
        }
        
        for( int i = nRows-1;  i < s.size(); i+= 2 * (nRows - 1 ) )
            result[idx++] = s[i];
        
        return result;
    }
};
