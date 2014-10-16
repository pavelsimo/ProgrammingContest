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


const int INF = 1000000;
const int zero_lbl = 1, one_lbl = 2, none = 0;

int N, a[1002], memo[1002][4];

int go(int n, int prev) {
   if(n == N) return 0;
   int &res = memo[n][prev];
   if(res >= 0) 
      return res;
   res = INF;
   if(prev == none) {
      res = min(res, go(n + 1, zero_lbl) + (a[n] == 0));
      res = min(res, go(n + 1, one_lbl)  + (a[n] == 1));
   } else if(prev == zero_lbl) {
      res = min(res, go(n + 1, one_lbl)  + (a[n] == 1));
   } else {
      res = min(res, go(n + 1, zero_lbl) + (a[n] == 0));
   }
   return res;
}

int main(int argc, char *argv[]) {
   string S;
   while(cin >> N >> S) {
      memset(memo, -1, sizeof(memo));      
      for(int i = 0; i < N; ++i) a[i] = S[i] - '0';
      cout << go(0, none) << endl;
   }
   return 0;
}

