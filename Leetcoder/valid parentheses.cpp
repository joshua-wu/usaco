class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> charstack;
        for( int i = 0; i < s.size(); i++ )
        {
            if( s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                charstack.push( s[i] );
                continue;
            }
            //now is the others
            if( charstack.size() == 0 ||
                (s[i] - 1 != charstack.top() && s[i]-2 != charstack.top() )
                )
                return false;
            charstack.pop();
        }
        
        return charstack.size() == 0;
    }
};
