/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11225  C++  "Ad Hoc, Cards" */
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <deque>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <sys/time.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

bool isoudler(string &s) {
   return s=="twenty-one of trumps" || s=="one of trumps" || s=="fool";
}

int main(int argc, char *argv[]) {
   string buf, rank;
   int TC, N, oudlers, pts;
   getline(cin,buf);
   sscanf(buf.c_str(),"%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      if(tc > 1) putchar('\n');
      getline(cin,buf);
      sscanf(buf.c_str(),"%d",&N);
      oudlers = pts = 0;
      for(int i = 0; i < N; ++i) {
         getline(cin,buf);
         if(isoudler(buf)) {
            pts+=45;
            oudlers++;
         } else {
            istringstream in(buf);
            in >> rank;
            if(rank=="king") pts+=45;
            else if(rank=="queen") pts+=35;
            else if(rank=="knight") pts+=25;
            else if(rank=="jack") pts+=15;
            else pts+=5;
         }
      }
      switch(oudlers) {
         case 1:  pts = pts - 510; break;
         case 2:  pts = pts - 410; break;
         case 3:  pts = pts - 360; break;
         default: pts = pts - 560;
      }
      printf("Hand #%d\n",tc);
      if(pts >= 0) printf("Game won by %d point(s).\n",pts/10);
      else printf("Game lost by %d point(s).\n",(-pts)/10);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
