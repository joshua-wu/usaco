class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //using a stack to find the max len
        stack<int> lefts;
        int longest = -1;
        int last = -1;
        for( int i = 0; i < s.size(); i++ )
        {
             if( s[i] == '(' )
             {
                     lefts.push( i );
                     continue;
             }
             //if it it right
             // s[i] == ')')
             if( lefts.size() == 0 )
             {
                 last = i;
                 continue;
             }

             //matched
             lefts.pop();
             if( lefts.emtpy() )
                 longest = max( longest, i - last );
             else
                 longest = max( longest , i - lefts.top() );

        }
        
        return longest;        
    }
}; 

/*
Find from left to right by a forward iterator and right to left by a reverse iterator. 
Using template to avoid duplicate code since a reverse iterator overloads the operator +.
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        return max( helper(s.begin(), s.end(), '('), helper(s.rbegin(), s.rend(), ')') );
    }

    template<class Iter>
    int helper(Iter beg, Iter end, char ch) {
        int ret = 0;
        int left = 0, right = 0;
        for ( ; beg != end; ++beg) {
            if (*beg == ch) {
                ++left;
            }
            else if (left > right) {
                ++right;
                if (left == right) {
                    ret = max(ret, left<<1);
                }
            }
            else {
                left = right = 0;
            }
        }
        return ret;
    }
};
