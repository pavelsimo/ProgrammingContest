/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10683  C++  "Ad Hoc, Math" */
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

char buf[256];

int toint(char ch) {
   return ch - '0';
}

int main(int argc, char *argv[]) {
   int H, M, S, C, t;
   int h, m, s, c;
   while(gets(buf)) {
      H = toint(buf[0])*10 + toint(buf[1]);
      M = toint(buf[2])*10 + toint(buf[3]);
      S = toint(buf[4])*10 + toint(buf[5]);
      C = toint(buf[6])*10 + toint(buf[7]);
      t = H*360000 + M*6000 + S*100 + C;
      h = t/864000;
      m = (t/8640)%100;
      s = t*1000/86400;
      c = t*1000/864;
      DEBUG(h);
      DEBUG(m);
      DEBUG(s);
      DEBUG(c);
      printf("%d%02d%02d%02d\n",h,m,s,c);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
