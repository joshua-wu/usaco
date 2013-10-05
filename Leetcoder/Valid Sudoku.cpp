class Solution {
public:  
    //fill using dfs
    bool dfs( int x, int y , vector<vector<char>> & board )
    {
         //test end
         if( x == 9 && y == 9 )
             return true;
         //now to generate the next
         //to find the next
         //to fill to generate the next
         
         //bug here, can not break from inside
         int nx= 9 ,ny = 9;
         for( int i  = x; i < 9 && nx == 9; i++ )
              for( int j = 0; j < 9 && nx == 9; j++ )
                   if( !(x == i && y == j) && board[i][j] == '.' ) //bug here, the condition error, wrong:nx!=x && ny != y
                   {
                       nx = i; ny = j;
                   }

         
         for( int i = 0; i < 9; i++ )
         {
              //to test if it is correct
              board[x][y] = i + '1';
              //test if this row or this col has found
              bool found = false;
              for( int j = 0; j < 9 && !found; j++ )
              {
                   if( j != y && board[x][j] == board[x][y] 
                   || j != x && board[j][y] == board[x][y] )
                      found = true;
              } 
              
              //test the smallbox
              for( int j = x /3 * 3; !found && j < x/3 * 3 + 3; j++ )
                   for( int k = y/3 * 3; !found && k < y/3 * 3 + 3; k++ )
                        if( !( x == j && y == k ) && board[x][y] == board[j][k] )
                            found = true;
              if( found )
                  continue;           
             
              bool result = dfs( nx,ny, board );
              if( result )
                  return true;
         }    
         
         board[x][y] = '.'; //bug here, lost it
         return false;                  
    }       
    
    
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         int nx= 9 ,ny = 9;
         for( int i  = 0; i < 9 && nx == 9; i++ )
              for( int j = 0; j < 9 && nx == 9; j++ )
                   if(  board[i][j] == '.' ) //bug here, the condition error, wrong:nx!=x && ny != y
                   {
                       nx = i; ny = j;
                   }
                        
        dfs( nx, ny, board);  
    } 
       
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //valid offline
        bool valid = true;
        for( int x = 0; x < 9 && valid; x++ )
             for( int y = 0; y < 9 && valid  ;y++ )
        {
              if( board[x][y] == '.' )
                  continue;
              for( int j = 0; j < 9 && valid; j++ )
              {
                   if( j != y && board[x][j] == board[x][y] 
                   || j != x && board[j][y] == board[x][y] )
                      valid = false;
              } 
              
              //test the smallbox
              for( int j = x /3 * 3; valid && j < x/3 * 3 + 3; j++ )
                   for( int k = y/3 * 3; valid && k < y/3 * 3 + 3; k++ )
                        if( !(x == j && y == k) && board[x][y] == board[j][k] )
                            valid = false;    
        }
        
        if( !valid )
            return false;        
        
         int nx= 9 ,ny = 9;
         for( int i  = 0; i < 9 && nx == 9; i++ )
              for( int j = 0; j < 9 && nx == 9; j++ )
                   if(  board[i][j] == '.' ) //bug here, the condition error, wrong:nx!=x && ny != y
                   {
                       nx = i; ny = j;
                   }
        return dfs( nx, ny, board);        
    }
};
