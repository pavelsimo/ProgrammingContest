/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12506  C++  "Tries, Prefix" */
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

const int MAXN = 1028;
string movies[MAXN], clips[MAXN];
int D[MAXN][MAXN];

inline int hamming_distance(const string &a, const string &b) {
   if(sz(a) < sz(b)) return MAXN;
   int res = MAXN;
   for(int i = 0; i < sz(a); ++i) {
      if(i + sz(b) - 1 >= sz(a)) continue;
      int cnt = 0;
      for(int j = 0; j < sz(b); ++j)
         if(a[i + j] != b[j]) cnt++;
      res = min(res, cnt);
   }
   return res;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int M, Q;
   cin >> M >> Q;
   for(int i = 0; i < M; ++i)
      cin >> movies[i];
   for(int i = 0; i < Q; ++i)
      cin >> clips[i];
   for(int i = 0; i < (1<<10); ++i) {
      for(int j = 0; j < (1<<10); ++j) {
         D[i][j] = i ^ j;
         printf("%d ~= %d = %d\n",i,j,D[i][j]);
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
