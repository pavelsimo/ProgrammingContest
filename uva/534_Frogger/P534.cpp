/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  534  C++  "Graph Theory, MST" */
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

const int MAXN = 202, INF = 0x3f3f3f3f;
int X[MAXN], Y[MAXN], path[MAXN][MAXN];

int main(int argc, char *argv[]) {
   int N, tc = 1;
   while(1==scanf("%d",&N)) {
      if(N==0) break;
      for(int i = 0; i < N; ++i)
         scanf("%d%d",&X[i],&Y[i]);
      for(int i = 0; i < N - 1; ++i) {
         for(int j = i + 1; j < N; ++j) {
            path[i][j] = path[j][i] = (X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]);
         }
      }
      for(int k = 0; k < N; ++k) {
         for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
               path[i][j] = min(path[i][j], max(path[i][k],path[k][j]));
            }  
         }
      }
      printf("Scenario #%d\nFrog Distance = %.3lf\n\n",tc++,sqrt(path[0][1]));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
