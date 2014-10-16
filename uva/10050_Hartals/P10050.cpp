/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10050  C++  "Ad Hoc, Simulation" */
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef long long llong;

int cal[4002];

int main(int argc, char *argv[]) {
   int TC, N, P, t, res;
   scanf("%d",&TC);
   while(TC-- > 0) {
      memset(cal, 0, sizeof(cal));
      scanf("%d%d",&N, &P);
      for(int i = 0; i < P; ++i) {
         scanf("%d",&t);
         for(int j = t; j <= N; j += t)
            cal[j]++;
      }
      res = 0;
      for(int i = 1, j = 1; i <= N; ++i, ++j) {
         if(j >= 8) j = 1;
         if(cal[i] && (j != 6 && j != 7)) res++;
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
