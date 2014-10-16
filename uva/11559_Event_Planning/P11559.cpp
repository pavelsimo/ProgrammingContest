/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11559  C++  "Ad Hoc" */
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

int main(int argc, char *argv[]) {
   int N, B, H, W, h_price, w_beds;
   while(scanf("%d%d%d%d",&N,&B,&H,&W) == 4) {
      int res = INF;
      for(int i = 0; i < H; ++i) {
         scanf("%d",&h_price);
         for(int j = 0; j < W; ++j) {
            scanf("%d",&w_beds);
            if(w_beds >= N && h_price * N <= B && h_price * N < res)
               res = h_price*N;
         }
      }
      if(res >= INF) puts("stay home");
      else printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
