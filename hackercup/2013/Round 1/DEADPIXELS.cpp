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


const int MAXN = 1000002;

struct Point {
   int x, y;
};

bool cmpYX(const Point &a, const Point &b) {
   if(a.y != b.y) return a.y < b.y;
   return a.x < b.x;
}

Point dead_px[MAXN];
int A[40002];

int main(int argc, char *argv[]) { 
   int TC, W, H, P, Q, N, X, Y, a, b, c, d;
   cin >> TC;
   for(int tc = 1; tc <= TC; ++tc) {
      cin >> W >> H >> P >> Q >> N >> X >> Y >> a >> b >> c >> d;
      dead_px[0].x = X;
      dead_px[0].y = Y;
      for(int i = 1; i < N; ++i) {
         dead_px[i].x = (dead_px[i-1].x * a + dead_px[i-1].y * b + 1) % W;
         dead_px[i].y = (dead_px[i-1].x * c + dead_px[i-1].y * d + 1) % H;         
      }
      memset(A, 0, sizeof(A));
      sort(dead_px, dead_px + N, cmpYX);
      int k = 0;
      int res = 0;
      for(int i = 0; i < H; ++i) {
         int cols = 0;
         for(int j = 0; j < W; ++j) {
            if(k < N && dead_px[k].y == i && dead_px[k].x == j) {
               A[j] = 0;
               k++;
            } else {
               A[j]++;
            }
            if(A[j] >= Q) cols++;
            else cols = 0;
            if(cols >= P) res++;
         }
      }
      cout << "Case #" << tc << ": " << res << endl;
   }
   return 0;
}
