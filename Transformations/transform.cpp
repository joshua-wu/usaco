//template

/*
ID: wujian.1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <assert.h>     /* assert */

using namespace std;

class Board;


//#define __DEBUG__

class Board
{
      friend void operator<<( ostream & ofs, const Board & board );
public:
    Board( const char * matrix, int row, int col )
    {
      m_row = row;
      m_col = col;
      m_matrix = new char[m_row * m_col];
      memcpy( m_matrix, matrix, m_row * m_col );
    }
    
    Board( const Board & board )
    {
       m_matrix = NULL;
      *this = board;  
    }
    
    Board & operator=( const Board & board )
    {
          m_row = board.m_row;
          m_col = board.m_col;
          
          if( NULL != m_matrix )
              delete[] m_matrix;
          
          m_matrix = new char[ m_row * m_col ];
          memcpy( m_matrix, board.m_matrix, m_row * m_col );
    }
    
    
    ~Board()
      {
	delete[] m_matrix;
	m_matrix = NULL;
      }
      
    
    bool operator==(  const Board & board )const
    {
      for( int i = 0; i < m_row * m_col; i++ )
	       if( m_matrix[i] != board.m_matrix[i] )
	           return false;
      return true;
    }
    
    Board Rotate90()const
    {
#ifdef __DEBUG__
      cout<<"before rotation"<<endl;
      cout<<*this;
#endif
      char * matrix = new char[ m_row * m_col ];
      memcpy( matrix, m_matrix, m_row * m_col );
      //inplace rotation for the matrix
      for( int i = 0; i < m_row / 2; i++ )
	for( int j = i; j < m_col - i - 1; j++ )
	  {
	    //assume that the matrix is square
	    //rotate the 4 element
	    char tmp = matrix[sub2idx( i,j  )];
	    matrix[ sub2idx(i,j)] = matrix[ sub2idx( m_col - j - 1, i ) ];
	    matrix[ sub2idx( m_col - j - 1, i)] = matrix[ sub2idx( m_col - i - 1, m_col - j - 1 ) ];
	    matrix[ sub2idx( m_col - i - 1, m_col - j - 1 )] = matrix[ sub2idx( j , m_col - i - 1 ) ];
	    matrix[ sub2idx( j , m_col -  i - 1 )] = tmp; //matrix[ sub2idx( i,j  ) ];
	  }
	  
	  Board new_board( matrix, m_row, m_col );
#ifdef __DEBUG__
      cout<<"after rotation"<<endl;
      cout<<new_board;
#endif
      return new_board;
    }


    
    Board Reflect(  )const
    {
#ifdef __DEBUG__
      cout<<"before reflection:"<<endl;
      cout<<*this;
#endif
      char * matrix = new char[ m_row * m_col ];
      memcpy( matrix, m_matrix, m_row * m_col );
        //for each element, find its target
        for( int i = 0; i < m_row; i++)
            for( int j = 0; j < m_col / 2 ; j++ )
            {
                //swap the a[i,j], a[i, j] + col / 2 
                swap( matrix[ sub2idx(i, j)], matrix[ sub2idx( i, m_col - j - 1 )]);
            }
            
        Board new_board( matrix, m_row, m_col );
#ifdef __DEBUG__
        //output the matrix after
        cout<<"after reflection:"<<endl;
        cout<<new_board;
#endif
	return new_board;
    }

    int sub2idx( int sub_row, int sub_col)const
    {
        assert( sub_row >= 0 && sub_col >= 0 && sub_row < m_row && sub_col < m_col );
        return sub_row * m_col + sub_col;
    }

private:
   char * m_matrix;
   int m_row;
   int m_col;    
};

//#define __DEBUG__
void operator<<( ostream & ofs, const Board & board )
{
        for( int i = 0; i < board.m_row; i++ )
        {
            for( int j = 0; j < board.m_col; j++)
                ofs<<board.m_matrix[board.sub2idx(i,j)]<<' ';
            ofs<<endl;
        }
}

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    
    int n ;
    fin>>n;
    char * matrix = new char[ n*n];
    for( int i = 0; i < n*n; i++ )
         fin>>matrix[i];
    Board bd( matrix, n, n );
    
    for( int i = 0; i < n*n; i++ )
         fin>>matrix[i];
    Board target( matrix, n, n);
    
    int change = 0;

      if( bd.Rotate90() == target  ) change = 1;
      else if ( bd.Rotate90().Rotate90() == target ) change = 2;
      else if ( bd.Rotate90().Rotate90().Rotate90() == target ) change = 3;
      else if ( bd.Reflect() == target ) change = 4;
      else if ( bd.Reflect().Rotate90() == target 
              || bd.Reflect().Rotate90().Rotate90() == target 
              || bd.Reflect().Rotate90().Rotate90() == target  )
              change = 5;
      else if( bd == target ) change = 6;
      else change = 7;

    fout<< change <<endl;
#ifdef __DEBUG__
    cin.get();
#endif
    return 0;
}

