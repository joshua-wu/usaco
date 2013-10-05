//template

/*
ID: wujian.1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string go = "GO";
    string stay = "STAY";
    const int gole = 47;
    string group_name,comet_name;
    while( fin>>group_name>>comet_name)
    {
     int mode_group = 1, mode_comet = 1;
     for( int i =0; i < group_name.size(); i++ )
          mode_group = (mode_group * (group_name[i] - 'A' + 1))%gole;
     
     for( int i =0; i < comet_name.size(); i++ )
          mode_comet = (mode_comet * (comet_name[i] - 'A' + 1))%gole;     
     
     if( mode_group == mode_comet )
         fout<<go<<endl;
     else
         fout<<stay<<endl;
    }
    fin.close();
    fout.close();

    return 0;
}
