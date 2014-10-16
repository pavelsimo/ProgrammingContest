/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  1237  C++  "Brute Force" */
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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

const int MAXN = 10002;
char buf[128], dict[MAXN][32];
int L[MAXN], H[MAXN];

int main(int argc, char *argv[]) {
   int TC, N, Q, P, res;
   gets(buf);
   sscanf(buf,"%d",&TC);
   for(int tc = 0; tc < TC; ++tc) {
      if(tc > 0) putchar('\n');
      gets(buf);
      sscanf(buf,"%d",&N);
      for(int i = 0; i < N; ++i) {
         gets(buf);
         sscanf(buf,"%s %d %d",dict[i],&L[i],&H[i]);  
      }
      gets(buf);
      sscanf(buf,"%d",&Q);
      while(Q-- > 0) {
         gets(buf);
         sscanf(buf,"%d",&P);   
         int cnt = 0;
         for(int i = 0; i < N; ++i) {
            if(P >= L[i] && P <= H[i]) {
               res = i;
               cnt++;
            }
            if(cnt > 1) break;
         }
         if(cnt == 1) puts(dict[res]);
         else puts("UNDETERMINED");
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
