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

int X[1010], Y[1010], R[1010];
bool inside(int xa, int ya, int xb, int yb, int r) {
   return (xa-xb)*(xa-xb) + (ya-yb)*(ya-yb) <= r*r;
}

int main(int argc, char *argv[]) {
   int xa, ya, xb, yb, n, res = 0, cnt = 0;
   cin >> xa >> ya >> xb >> yb >> n;
   for(int i = 0; i < n; ++i)
      cin >> X[i] >> Y[i] >> R[i];
   int min_x = min(xa,xb);
   int min_y = min(ya,yb);
   int max_x = max(xa,xb);
   int max_y = max(ya,yb);
   for(int xi = min_x; xi <= max_x; ++xi) {
      cnt++;
      int yi = max_y;
      bool ok = false;
      for(int i = 0; i < n; ++i) {
         if(inside(xi,yi,X[i],Y[i],R[i])) {
            ok = true;
            break;
         }
      }
      if(ok) res++;
   }
   for(int yi = max_y - 1; yi >= min_y; --yi) {
      cnt++;
      int xi = max_x;
      bool ok = false;  
      for(int i = 0; i < n; ++i) {
         if(inside(xi,yi,X[i],Y[i],R[i])) {
            ok = true;
            break;
         }
      }
      if(ok) res++;
   }
   for(int xi = max_x - 1; xi >= min_x; --xi) {
      cnt++;
      int yi = min_y;
      bool ok = false;  
      for(int i = 0; i < n; ++i) {
         if(inside(xi,yi,X[i],Y[i],R[i])) {
            ok = true;
            break;
         }
      }
      if(ok) res++;
   }
   for(int yi = min_y + 1; yi <= max_y - 1; ++yi) {
      cnt++;
      int xi = min_x;
      bool ok = false;  
      for(int i = 0; i < n; ++i) {
         if(inside(xi,yi,X[i],Y[i],R[i])) {
            ok = true;
            break;
         }
      }
      if(ok) res++;
   }
   cout << cnt - res << endl;
   return 0;
}

