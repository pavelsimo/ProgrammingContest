/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11958  C++  "Ad Hoc, Time, Date" */
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

const int INF = 0x3f3f3f3f;
char buf[16];

int main(int argc, char *argv[]) {
   int TC, N, h, m, m1, m2, tb;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%d%s",&N,buf);
      sscanf(buf,"%d:%d",&h,&m);
      m1 = h*60 + m;
      int res = INF;
      for(int i = 0; i < N; ++i) { 
         scanf("%s%d",buf,&tb);
         sscanf(buf,"%d:%d",&h,&m);
         m2 = h*60 + m;
         if(m2 < m1) 
            m2+=24*60;
         res = min(res, m2 - m1 + tb);
      }
      printf("Case %d: %d\n",tc,res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
