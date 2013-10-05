//amazone test 2

int differ(string string1, string string2) {
//split the string to word
        vector<string> strvct1;
        vector<string> strvct2;
        istringstream iss1( string1 );
        istringstream iss2( string2 );
        string temp;
        while( iss1>>temp )
                strvct1.push_back( temp );
        while( iss2>>temp )
               strvct2.push_back( temp );
        
        //get a vector
        vector<vector<int>> diff( vct1.size() + 1, vector<int>(vct2.size() + 1, 0 );
        //row vct 1
        //col vct 2
        //set the fence
        for( int i = 0; i < vct1.size() + 1; i++ )
               diff[i][vct2.size()] = vct1.size() - i;
        for( int i = 0; i < vct2.size() + 1; i++ )
             diff[vct1.size()][i] = vct2.size() - i;
        
        //now to get the num
        for( int i = vct1.size() - 1; i >= 0; i-- )
             for( int j = vct2.size() - 1; j>=0; j--)      
                 diff[i][j] = min( diff[i+1][j] + 1 , 
                                   min( diff[i][j+1] + 1, diff[ i+1][j+1] + strvct1[i] != strvct2[j] ) ); 
      return diff[0][0];  
}

