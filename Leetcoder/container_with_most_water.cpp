class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0;
        int r = height.size() - 1;
        int max_value = 0;
        while( l < r )
        {
               //get the value
               max_value = max( min( height[l], height[r] ) * ( r - l ), max_value );
               if( height[l] < height[r] )
                   l++;
               else
                   r--; 
        }
        
        return max_value;
    }
};
