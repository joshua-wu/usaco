//template

/*
ID: wujian.1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

using namespace std;

struct Interval
{ int begin;
  int end;
  
  bool operator<( const Interval & it )const
  { return this->begin < it.begin || (this->begin == it.begin && this->end < it.end); }
};

#define N 5000
Interval feed_interval[N];

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");

    //get the num of beads
    int n; 
    fin>>n;
    for( int i = 0; i < n; i++ )
         fin>>feed_interval[i].begin>>feed_interval[i].end;
    //sort it by the begin time
    sort( feed_interval, feed_interval + n );
    
    //now to merage
    int cur_merged = 0; // point to the merged
    for( int i = 1; i < n; i++ )
    {
         if( feed_interval[i].begin <= feed_interval[cur_merged].end  )
         {
             //intersect, then merge, update the end
             if(feed_interval[i].end > feed_interval[cur_merged].end )
                 feed_interval[cur_merged].end = feed_interval[i].end;
         }
         else//( feed_interval[i].begin > feed_interval[cur].end
         {
             cur_merged++;    
             feed_interval[cur_merged] = feed_interval[i]; 
         }
    }
    
    //now to find the max feed interval
    //and the max not feed interval
    int longest_feed, longest_not_feed;
    longest_feed = feed_interval[cur_merged].end - feed_interval[cur_merged].begin;
    longest_not_feed = 0;
    //attention here ,we drop the last one
    for( int i = 0; i < cur_merged ; i++ )
    {
        int durition = feed_interval[i].end - feed_interval[i].begin; 
        longest_feed = durition > longest_feed ? durition:longest_feed;
        durition = feed_interval[i+1].begin - feed_interval[i].end;
        longest_not_feed = durition > longest_not_feed ? durition:longest_not_feed;
    }
    
    fout<<longest_feed<<" "<<longest_not_feed<<endl;
    fin.close();
    fout.close();

    return 0;
}
