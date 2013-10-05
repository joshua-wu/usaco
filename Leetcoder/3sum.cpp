 class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        vector<vector<int> > return_result;
        //sort the array
        sort( num.begin(), num.end());
        for( int cur = 0; cur < num.size(); cur++ )
        {
            //to skip the dump like [-1,0,0,1,1]
            if( cur != 0 && num[cur] == num[cur-1])
                continue;
            
             //here is the key, or you will calculated it multi times( 3 times )            
            int begin = cur + 1;
            int end = num.size() - 1;
            while( begin < end )
            {
                if( num[begin] + num[end] < -num[cur])
                {
                    begin++;
                }
                else if(  num[begin] + num[end] > -num[cur] )
                {
                    end--;
                }
                else
                {
                    //reach here, meanings equal
                    result.push_back( num[cur] );
                    result.push_back( num[begin] );
                    result.push_back( num[end] );
                
                    sort( result.begin(), result.end() );
                    return_result.push_back( result );
                    result.clear();
                
                    //here is for: [ -2,1,1,1,1]
                    //we only want -2,1,1
                    begin++;
                    while( begin < num.size() &&  num[begin] == num[begin-1] )
                           begin++;
                    end--;
                    while( end > begin && num[end+1] == num[end ] )
                           end--;
                }
            }
        }
        
        return return_result;
        
    }
};
