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

typedef long long llong;

const int MAXN = 54;
const int MOD = 1000000007;

int M;

struct Matrix {
   int mat[MAXN][MAXN];
};

Matrix multiply(const Matrix a, const Matrix b) {
   Matrix res;
   memset(res.mat, 0, sizeof(res.mat));
   for (int i = 0; i < M; ++i)
      for (int j = 0; j < M; ++j)
         for (int k = 0; k < M; ++k)
            res.mat[i][j] = (res.mat[i][j] + 
               llong(a.mat[i][k]) * b.mat[k][j]) % MOD;
   return res;
}

Matrix mpow(Matrix X, llong N) {
   Matrix res;
   memset(res.mat, 0, sizeof(res.mat));
   for (int i = 0; i < M; i++)
      res.mat[i][i] = 1;
   while (N > 0LL) {
      if (N & 1LL)
         res = multiply(res, X);
      X = multiply(X, X);
      N >>= 1LL;
   }
   return res;
}

int toint(char ch) {
   if(islower(ch)) return ch - 'a';
   else return ch - 'A' + 26;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   int u, v;
   llong N, K, res = 0LL;
   Matrix adj, A;
   string s;
   cin >> N >> M >> K;
   memset(adj.mat, 0, sizeof(adj.mat));
   for(int i = 0; i < M; ++i) {
      for(int j = 0; j < M; ++j) {
         adj.mat[i][j] = 1;
      }
   }
   while(K-- > 0) {
      cin >> s;
      u = toint(s[0]), v = toint(s[1]);
      adj.mat[u][v] = 0;
   }
   A = mpow(adj, N - 1);
   res = 0;
   for(int i = 0; i < M; ++i) {
      for(int j = 0; j < M; ++j) {
         res = (res +  A.mat[i][j]) % MOD;
      }
   }
   cout << res << endl;
   return 0;
}

