class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        //recursive
        if(  *s == '\0' && *p == '\0'  )
            return true;
            
        if( *s != '\0' && *p == '\0' )
            return false;
        
        //now make it small
        if( *(p + 1 ) != '*')
        {
            if( *s == '\0' ||  *p != '.' && *p != *s )
                    return false;
            //reach here, 
            //one of the list must be true
            //1. *p == *s
            //2. *p === .
            return isMatch( s + 1, p + 1 );
                
        }
        else//p+1 point to *
        {

                bool matched;
                //* meaning 0
                matched = isMatch( s , p + 2 );
                if( matched ) return true;
                
                //match 1
                if( *s != '\0' && (*p == *s || *p == '.') )
                {
                
                    matched = isMatch( s + 1, p );
                    if( matched ) return true;
                }
                
                return false;
        }

    }
};
