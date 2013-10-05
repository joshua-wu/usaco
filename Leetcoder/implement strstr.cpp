class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( NULL == haystack )
            return haystack;
        
        //test if needle is in haystack
        char * p, * q;
        while( haystack == 0 || *(haystack-1) != '\0')
        {
               p = needle;
               q = haystack;
               while( *p != '\0' && *q !='\0' && *p == *q )
               { p++; q++ }
               
               if( *p == '\0' && *q == '\0' )
                   return haystack;
               
               haystack++;
        }
        
        return NULL;
    }
};




class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( NULL == haystack || *needle =='\0' )
            return haystack;
        
        //test if needle is in haystack
            
        char * p, * q;
        char * quick_stop;
        quick_stop = haystack;
        p = needle + 1;
        while( *p )
        {    quick_stop++;
            p++;
        }
        
        while( *quick_stop )
        {
               p = needle;
               q = haystack;
               while( *p && *q && *p == *q )
               { p++; q++; }
               
               if( *p == '\0')
                   return haystack;
               
               haystack++;
               quick_stop++;
        }
        
        return NULL;
    }
};
