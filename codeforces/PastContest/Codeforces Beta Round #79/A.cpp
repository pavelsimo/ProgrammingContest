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

const int INF = 2000000000;
bool match[200][200];
int price[200];

int main(int argc, char *argv[]) {
   memset(match,false,sizeof(match));
   int N, M, u, v;
   cin >> N >> M;
   for(int i = 1; i <= N; ++i)
      cin >> price[i];
   for(int i = 0; i < M; ++i) {
      cin >> u >> v;
      match[u][v] = true;
      match[v][u] = true;
   }
   int res = INF;
   for(int i = 1; i <= N; ++i) {
      for(int j = i+1; j <= N; ++j) {
         for(int k = j+1; k <= N; ++k) {
            if(match[i][j] && match[j][k] && match[k][i]) {
               res = min(res,price[i]+price[j]+price[k]);
            }
         }
      }
   }
   if(res >= INF) cout << -1 << endl;
   else cout << res << endl;
   return 0;
}

