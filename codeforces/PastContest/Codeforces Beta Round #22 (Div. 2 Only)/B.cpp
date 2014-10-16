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

int DP[32][32];

int main(int argc, char *argv[]) {
   string board[32];
   int n, m;
   cin >> n >> m;
   for(int i = 0; i < n; ++i) 
      cin >> board[i];
   memset(DP, 0, sizeof(DP));
   for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
         DP[i][j] = (board[i][j] == '1');
         if(i >= 1) DP[i][j] += DP[i-1][j];
         if(j >= 1) DP[i][j] += DP[i][j-1];
         if(i >= 1 && j >= 1) DP[i][j]-=DP[i-1][j-1];
      }
   }
   int res = 4;
   for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
         if(board[i][j] == '0') {
            for(int ii = i; ii < n; ++ii) {
               for(int jj = j; jj < m; ++jj) {
                  int cntOne = DP[ii][jj];
                  if(i >= 1) cntOne -= DP[i-1][jj];
                  if(j >= 1) cntOne -= DP[ii][j-1];
                  if(i >= 1 && j >= 1) cntOne += DP[i-1][j-1];
                  if(cntOne == 0) {
                     int w = jj - j + 1;
                     int h = ii - i + 1;
                     res = max(res, 2*w + 2*h);
                  }  
               }
            }            
         }
      }
   }
   cout << res << endl;
   return 0;
}

