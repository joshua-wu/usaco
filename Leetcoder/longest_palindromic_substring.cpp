class Solution {
public:
    
    pair<int,int> expand( int l, int r, const string & s )
        {
            //

            while( l >= 0 && r < s.size() && s[l] == s[r] )
            {
                l--;
                r++;
            }
        
            l++;
            r--;
            return make_pair( l, r );
        }

    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //assume the p as the middle of the string, to find the max string
        
        pair<int,int> max_range(0,0);
        pair<int,int> range;
        for( int i = 1; i < s.size(); i++ )
        {
            range = expand( i-1, i, s );
            if( range.second - range.first > max_range.second - max_range.first )
                max_range = range;

            range = expand(  i, i, s );
            if( range.second - range.first > max_range.second - max_range.first )
                max_range = range;
        }
        
        return s.substr( max_range.first, max_range.second - max_range.first + 1 );
    }
};
