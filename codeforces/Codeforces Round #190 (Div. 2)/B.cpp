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

llong memo[302][302][302];

llong rec(llong a, llong b, llong c) {
   if(memo[a][b][c] != -1) return memo[a][b][c];
   llong res = 0LL;
   if(a >= 3) 
      res = max(res, rec(a - 3, b, c) + 1);
   if(b >= 3) 
      res = max(res, rec(a, b - 3, c) + 1);
   if(c >= 3) 
      res = max(res, rec(a, b, c - 3) + 1);
   if(a >= 1 && b >= 1 && c >= 1) 
      res = max(res, rec(a - 1, b - 1, c - 1) + 1);
   return memo[a][b][c] = res;
}



llong solve(llong r, llong g, llong b) {
   llong res = 0LL;
   
   
   return res;
}

void test() {
   memset(memo, -1, sizeof(memo));
   rec(300,300,300);
   for(llong r = 0; r <= 300; ++r) {
      for(llong g = 0; g <= 300; ++g) {
         for(llong b = 0; b <= 300; ++b) {
            if(solve(r,g,b) != rec(r,g,b)) {
               DEBUG(r);
               DEBUG(g);
               DEBUG(b);
               DEBUG(solve(r,g,b));
               DEBUG(rec(r,g,b));
               return;
            }
         }
      }
   }
}


int main(int argc, char *argv[]) { 
   //test();
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   llong r, g, b;
   cin >> r >> g >> b;
   cout << solve(r,g,b) << endl;
   return 0;
}
