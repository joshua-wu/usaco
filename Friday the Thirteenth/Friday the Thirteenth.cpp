//template

/*
ID: wujian.1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <string.h>
using namespace std;

using namespace std;

//day of month, the i-th month is at index i-1
int day_of_month_normal[] = {
    31,28,31,30,31,30,
    31,31,30,31,30,31 
     };
int day_of_month_leap[] = {
    31,29,31,30,31,30,
    31,31,30,31,30,31 
     };
int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    //input  the n
    int n;
    fin>>n;
    //this one is used to count 13 at each days, the monday is at index 0
    int thirteenth_at_days[7];
    //init all to zero
    memset( thirteenth_at_days, 0, sizeof( thirteenth_at_days) );
    
    //for each year, for each month, to calculate the 13 at 
    //init, 1900,1 is the monday,so the day before is sunday,6
    int cur_day = 6;
    for( int i = 0; i < n; i++ )
    {
         int cur_year = 1900 + i;
         bool is_leap_year = false;
         if( (cur_year % 100 != 0 && cur_year % 4 == 0)
           || ( cur_year %400 == 0) )
              is_leap_year = true;
         int * day_of_month = is_leap_year?day_of_month_leap:day_of_month_normal;
         for( int j = 0; j < 12; j++ )
         {
              //get the day of each 13
              thirteenth_at_days[ (cur_day + 13) % 7]++;
              //now deal with the end day of the month
              cur_day += day_of_month[j];
         }
    }
    
    
    for( int i = 0; i < 6; i++)
         fout<<thirteenth_at_days[(i+5)%7]<<" ";
    fout<<thirteenth_at_days[(6+5)%7]<<endl;

    
    fin.close();
    fout.close();

    return 0;
}
