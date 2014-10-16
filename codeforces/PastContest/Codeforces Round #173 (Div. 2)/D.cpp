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

// 27,543,608
int memo[302][302][302];
int cnt = 0;

int get_min(int a, int b, int c) {
   if(cnt == 1) return a;
   else if(cnt == 2) return min(a,b);
   return min(a,min(b,c));
}

int rec(int a, int b, int c) {
   if(a == 0 && b == 0 && c == 0) return 0;
   int &res = memo[a][b][c];
   if(res != -1) return res;
   res = 0;
   for(int aa = 1; aa <= a; ++aa) res |= !rec(a - aa, b, c);
   for(int bb = 1; bb <= b; ++bb) res |= !rec(a, b - bb, c);
   for(int cc = 1; cc <= c; ++cc) res |= !rec(a, b, c - cc);
   for(int t = 1; t <= get_min(a,b,c); ++t) 
      res |= !rec(max(0, a - t), max(0, b - t), max(0, c - t));
   return res;
}

int main(int argc, char *argv[]) { 
   memset(memo, -1, sizeof(memo));
   int N, a, b, c;
   cin >> N;
   a = b = c = cnt = 0;
   if(N >= 1) cin >> a, ++cnt;
   if(N >= 2) cin >> b, ++cnt;
   if(N >= 3) cin >> c, ++cnt;
   cout << (rec(a, b, c) ? "BitLGM" : "BitAryo") << endl;
   return 0;
}
