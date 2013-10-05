class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( strs.size() == 0 )
            return "";
        
        //based on the first str
        for( int i = 0; i< strs[0].size(); i++ )
        {
            //test others
            for( int j = 1; j < strs.size(); j++ )
            {
                if( strs[j][i] != strs[0][i] )
                    return strs[0].substr( 0, i );        
            }
            
            //ass passed
        }

        
        return strs[0];
    }
};
