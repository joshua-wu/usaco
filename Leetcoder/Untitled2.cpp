#include<iostream>
#include<stack>
#include<string>
using namespace std;


struct BinNode 
{
       int data;
       BinNode *left, *right;
       int color;
};

void post_order( struct BinNode * root )
{
     //default all node in tree's color is 0
     stack<struct BinNode*> s;
     s.push( root );
     while( !s.empty() )
     {
            root = s.top(); s.pop();
            if( NULL==root)
                continue;
            
            if( root->color == 0 )
            {
                root->color = 1;
                s.push( root );
                s.push( root->right );
                s.push( root->left );
            }
            else
            {
                //print( root->data );
            }            
     }
} 


    //find the k-th
    int get_the_num( int k, int A[], int m, int B[], int n )
    {
        if( m == 0 )
            return B[k];
        
        if( n ==  0 )
            return A[k];
        
        //now both array are not zero and need to find the kth
        int mid_a = m / 2;
        int mid_b = n / 2;
        if( A[mid_a] >= B[mid_b] )
        {
            // A: ---mid_a----
            // B: ----mid_b----
            //so this is ---mid_b...mid_a...
            if( k >= n + m/2  )
            {  
                return get_the_num( k - (n+m/2), A + m /2, m - m /2, B, 0 );               
            }
            else if( k < n/ 2 )
            {
                return get_the_num( k, A, 0, B, n / 2 );
            }
            else
            {
                return get_the_num( k - n / 2, A,  m /2 , B + n/2 , n - n/2 ); 
            }    
        }
        else
        {
            // A: ---mid_a----
            // B: ----mid_b----
            //so this is ---mid_b...mid_a...
            if( k >= m + n/2  )
            {  
                return get_the_num( k - (n+m/2), A , 0, B + n / 2, n - n/ 2 );               
            }
            else if( k < m/ 2 )
            {
                return get_the_num( k, A, m/2 , B, 0 );
            }
            else
            {
                return get_the_num( k - m / 2, A + m /2 ,m - m /2 , B  ,  n/2 ); 
            }    
        }
    }

int main()
{
    int k = 4;
    //int * a[k] = new int[3][k];
    string att;
    cout<<to_string(3333)<<endl;
    //int  a[] = {1,2,3,4,5,6,7,8,9};
    //int b[] = {1,2,3,4,5,6,7,8};
    //strncpy( b, a, 3 );
    //cout<<get_the_num( 3, a, 9, b, 8 )<<endl;
    cin.get();
}
