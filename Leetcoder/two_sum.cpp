class Node
{
public:
	int value;
	int index;
	Node( int v, int i )
		:value(v),index(i){}
	bool operator<( const Node & it )const
	{return value < it.value;}
};


class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		//first sort it
		vector<Node> numbers_with_idx;
		for( int i = 0; i < numbers.size();i++ )
			numbers_with_idx.push_back( Node( numbers[i], i+1 ) );

		//the index matter
		sort( numbers_with_idx.begin(), numbers_with_idx.end() );
		vector<int> result;
		int l = 0;
		int r = numbers.size() - 1;
		while( l < r )
		{
            int & lvalue = numbers_with_idx[l].value;
            int & rvalue = numbers_with_idx[r].value;
			if(  lvalue + rvalue  == target ) 
			{
				result.push_back( numbers_with_idx[l].index );
				result.push_back( numbers_with_idx[r].index );
				break;
			}
			else if( lvalue + rvalue < target )
				l++;
			else //bigger than
				r--;
		}

		return result;
	}
};
