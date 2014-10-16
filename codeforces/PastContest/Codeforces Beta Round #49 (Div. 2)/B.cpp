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

const double EPS = 1e-10;

int main(int argc, char *argv[]) {
   // 0.8 <= h/w <= 1.25
   // w*0.8 <= h <= w*1.25
   // h/1.25 <= w <= h/0.8
   llong H, W, ah, aw, besta;
   cin >> H >> W;
   ah = aw = 1;
   besta = 0;
   for(llong h = 1LL; h <= H; h<<=1LL) {
      llong w = W;
      llong wlo = ceil(h / 1.25 - EPS);
      llong whi = floor(h / 0.8 + EPS);
      if(w >= wlo)
         w = min(w, whi);
      else continue;
      if(h * w > besta) {
         besta = h * w;
         ah = h; aw = w;
      } else if(h * w == besta && h > ah) {
         ah = h; aw = w;
      }
   }
   for(llong w = 1LL; w <= W; w<<=1LL) {
      llong h = H;
      llong hlo = ceil(w * 0.8 - EPS);
      llong hhi = floor(w * 1.25 + EPS);
      if(h >= hlo)
         h = min(h, hhi);
      else continue;
      if(h * w > besta) {
         besta = h * w;
         ah = h; aw = w;
      } else if(h * w == besta && h > ah) {
         ah = h; aw = w;
      }
   }
   cout << ah << " " << aw << endl;
   return 0;
}
