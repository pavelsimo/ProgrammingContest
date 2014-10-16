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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

// n - items
// W - knapsack capacity
// v[i] - value of the i-th item
// w[i] - weigth of the i-th item
// DP[i] - maximum valuable achievable with a knapsack of capacity W.

const int MAXN = 1002;
int n, W, DP[MAXN], v[MAXN], w[MAXN], P[MAXN];

int main(int argc, char *argv[]) {
   scanf("%d%d",&n,&W);
   for(int i = 0; i < n; ++i)
      scanf("%d",&w[i]);
   for(int i = 0; i < n; ++i)
      scanf("%d",&v[i]);
   memset(DP, 0, sizeof(DP));
   memset(P, -1, sizeof(P));
   for(int i = 0; i <= W; ++i) {
      for(int j = 0; j < n; ++j) {
         if(i >= w[j]) {
            if(DP[i-w[j]] + v[j] > DP[i]) {
               DP[i] = DP[i-w[j]] + v[j];
               P[i] = i-w[j];
            }
         }
      }
   }
   for(int i = W; i > 0; i = P[i]) {
      int ind = find(w, w + n, i - P[i]) - w;
      printf("%d $%d.00\n",w[ind],v[ind]);
   }
   printf("total profit = $%d.00\n",DP[W]);
   return 0;
}

