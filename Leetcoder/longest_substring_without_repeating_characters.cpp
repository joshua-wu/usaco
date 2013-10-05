class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int idx_of_last[256];
		memset( idx_of_last, -1, sizeof( idx_of_last ) );

		//to loop to find the max
		int max_len = 0;
		int begin = 0;
		for( int i = 0; i < s.size(); i++ )
		{
			//1.first to check that i exist or not
			if( idx_of_last[ s[i] ] == -1 )
			{
				//first find this char
				idx_of_last[ s[i] ] = i;
				continue;
			}

			if( idx_of_last[ s[i] ] >= begin )
			{
				//the second find this char
				//to get the length
				max_len = max( max_len, i - begin );
				//now to updata the begin
				begin = idx_of_last[ s[i] ] + 1;
			}
			idx_of_last[ s[i] ] = i;
		}

		max_len = max( max_len, (int)s.size() - begin );
		return max_len;
	}
};
