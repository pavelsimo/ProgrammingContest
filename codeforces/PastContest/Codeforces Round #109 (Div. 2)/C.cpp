#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

const int INF = 10000000;
const int MAXN = 100020;
bool F[30][30];
int N, K, memo[MAXN][30];
string S;

int rec(int cur, int last) {
   if(cur == N) return 0;
   if(memo[cur][last] >= 0) 
      return memo[cur][last];
   int res = INF;
   res = min(res, rec(cur + 1, last) + 1);
   if(!F[S[cur]-'a'][last])
      res = min(res, rec(cur + 1, S[cur] - 'a'));
   return memo[cur][last] = res;
}

int main(int argc, char *argv[]) {
   memset(memo, -1, sizeof(memo));
   memset(F, false, sizeof(F));
   char u, v;
   cin >> S >> K;
   N = sz(S);
   for(int i = 0; i < K; ++i) {
      cin >> u >> v;
      F[u-'a'][v-'a'] = F[v-'a'][u-'a'] = true;
   }
   cout << rec(0,26) << endl;
   return 0;
}

