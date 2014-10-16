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

int R[1024], C[1024];
bool c_bad[1024];
string board[1024];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   int n, m, x, y;
   cin >> n >> m >> x >> y;
   for(int i = 0; i < n; ++i) {
      cin >> board[i];
   }
   for(int i = 0; i < n; ++i) {
      R[i] = 0;
      for(int j = 0; j < m; ++j) {
         R[i] += (board[i][j] == '#');
      }
   }
   for(int j = 0; j < m; ++j) {
      C[j] = 0;
      c_bad[j] = false;
      for(int i = 0; i < n; ++i) {
         if(i - 1 >= 0 && board[i - 1][j] != board[i][j]) 
            c_bad[j] = true;
         C[j] += (board[i][j] == '#');
      }
   }
   DEBUG("ROW");
   printf("cols at least x=%d\n",x);
   printf("rows at most  y=%d\n",y);
   for(int i = 0; i < n; ++i) {
      printf("%d - %d\n",R[i], m - R[i]);
   }
   DEBUG("COL");
   for(int i = 0; i < m; ++i) {
      printf("%d - %d bad? %s\n", C[i], n - C[i], c_bad[i] ? "YES" : "NO");
   }   
   return 0;
}

