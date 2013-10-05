
class Solution {
public:
    int find_2sum( vector<int> &num, int begin, int end , int target )
    {
        int front = begin;
        int rear = end - 1;
        

        int min_sum = num[front] + num[rear];
        while( front < rear )
        {
               int sum_value = num[front] + num[rear];
               if( abs( target - min_sum ) > abs( target - sum_value ) )
                   min_sum = sum_value;
               
               if(  sum_value < target )
                    front++;
               else if( sum_value > target )
                    rear--;
               else //equal
                    return target;
        }   
        
        return min_sum;
    }   
       
    int threeSumClosest( vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //sort first
       sort( num.begin(), num.end() );
       int min_value = num[0] + num[1] + num[2];
       for( int i = 0; i < num.size() - 2; i++ )
       {
            int result_2sum = find_2sum( num, i + 1, num.size(), target - num[i] );
            if( abs( target - min_value ) > abs( target - ( result_2sum + num[i] ) ) )
                min_value = result_2sum + num[i];
       }
       
       return min_value;
    }
};
