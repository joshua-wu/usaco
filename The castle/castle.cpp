
/*
ID: wujian.1
PROG: castle
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAX_ELEM 100
int color[MAX_ELEM][MAX_ELEM];
int castle[MAX_ELEM][MAX_ELEM];
int room_count[MAX_ELEM*MAX_ELEM]; //to recore how many room each color
int color_count; // to get how many color used

int dx[]= {0, -1,0, 1};
int dy[] = {-1,0,1, 0 };

void dfs( int x, int y, int m, int n, int color_idx )
{
    if( color[x][y] != 0 || x < 0 || y < 0 || x >=m || y>=n)
        return;
    color[x][y] = color_idx;
    //for each dir to do the dfs
    for( int i = 0; i < 4; i++ )
        if( !(castle[x][y] & (1<<i)) )
            dfs( x + dx[i], y+dy[i], m,n, color_idx );    
}

int main() {
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");
    int m,n;
    fin>>n>>m; //bug here, switched the n and the m
    for( int i = 0; i < m ; i++ )
        for( int j = 0; j < n; j++ )
            fin>>castle[i][j];
    //now to do dfs to get it color
    int color_idx = 1;
    for( int i = 0; i < m; i++ )
        for( int j = 0; j < n;j++ )
        {
            if(color[i][j]  == 0 )
            {
                 dfs( i,j, m,n, color_idx );
                 color_idx++;
            }
        }
    //now to find the max room, and count the max num of room
    for( int i = 0; i < m; i++ )
        for( int j = 0; j < n; j++ )
            room_count[ color[i][j] ]++;
    int max_room_size = 0;
    for( int i = 1;i < color_idx; i++ )
        max_room_size = max( max_room_size, room_count[i] );
    fout<<color_idx-1<<endl
        <<max_room_size<<endl;
    //now try to remove wall to see if can get a bigger room 
    int rx,ry;
    char dir;
    int max_room_combine_size = 0;

  for( int j = 0; j < n; j++ )
    for( int i = m - 1; i >= 0; i--)
        {
            //test N
            // get the north module's color
            int ncolor = 0;
            if( i != 0 && (castle[i][j] & 2 ) )
                ncolor = color[i-1][j];
            int combine_size = ncolor==color[i][j]?0: room_count[ncolor]+room_count[color[i][j]] ;
            if( combine_size > max_room_combine_size )
            {
                max_room_combine_size = combine_size;//bug lost it
                rx = i+1;
                ry = j+1;
                dir = 'N';
            }
            //test 
            int ecolor = 0;
            if( j != n - 1  && (castle[i][j] & 4 ) )
                ecolor = color[i][j+1];
            
            combine_size = ecolor==color[i][j]?0: room_count[ecolor]+room_count[color[i][j]] ;
            if( combine_size > max_room_combine_size )
            {
                max_room_combine_size = combine_size; //bug lost it
                rx = i+1;
                ry = j+1;
                dir = 'E';
            }
                                         
        }

    fout<<max_room_combine_size<<endl
        <<rx<<" "<<ry<<" "<<dir<<endl;

    return 0;
}


