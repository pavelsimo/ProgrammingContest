/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11946  C++  "Ad Hoc" */
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

char d[10], buf[128];

int main(int argc, char *argv[]) {
   d[0] = 'O';
   d[1] = 'I';
   d[2] = 'Z';
   d[3] = 'E';
   d[4] = 'A';
   d[5] = 'S';
   d[6] = 'G';
   d[7] = 'T';
   d[8] = 'B';
   d[9] = 'P';
   int TC, n;
   gets(buf);
   sscanf(buf,"%d",&TC);
   for(int tc = 0; tc < TC; ++tc) {
      if(tc > 0) putchar('\n');
      while(gets(buf)) {
         n = strlen(buf);
         if(n==0) break;
         for(int i = 0; i < n; ++i) {
            if(isdigit(buf[i])) putchar(d[buf[i]-'0']);
            else putchar(buf[i]);
         }         
         putchar('\n');
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
