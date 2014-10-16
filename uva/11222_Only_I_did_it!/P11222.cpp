/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11222  C++  "Ad Hoc" */
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

const int MAXN = 10010;
bool F[3][MAXN];
vector<int> S[3];

int main(int argc, char *argv[]) {
   int TC, N, M, problem, best;
   scanf("%d",&TC);
   memset(F,false,sizeof(F));
   for(int tc = 1; tc <= TC; ++tc) {
      M = 0;
      for(int k = 0; k < 3; ++k) {
         S[k].clear();
         scanf("%d",&N);
         for(int i = 0; i < N; ++i) {
            scanf("%d",&problem);
            M = max(M, problem);
            F[k][problem] = true;
         }         
      }
      for(int i = 0; i <= M; ++i) {
         if(F[0][i] && !F[1][i] && !F[2][i]) S[0].push_back(i);
         else if(F[1][i] && !F[0][i] && !F[2][i]) S[1].push_back(i);
         else if(F[2][i] && !F[0][i] && !F[1][i]) S[2].push_back(i);
         F[0][i] = F[1][i] = F[2][i] = false;
      }
      printf("Case #%d:\n",tc);
      best = max(sz(S[0]), max(sz(S[1]),sz(S[2])));
      for(int k = 0; k < 3; ++k) {
         if(sz(S[k]) == best) {
            printf("%d %d",k + 1, best);
            for(int i = 0; i < best; ++i) {
               putchar(' ');
               printf("%d",S[k][i]);
            }
            putchar('\n');
         }
      }
   }  
   return 0;
}
/* @END_OF_SOURCE_CODE */
