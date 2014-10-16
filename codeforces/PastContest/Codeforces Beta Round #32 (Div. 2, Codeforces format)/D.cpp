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

struct Star {
   int r, i, j;
   Star(int _r = 0, int _i = 0, int _j = 0) :
      r(_r), i(_i), j(_j) {}
   bool operator<(const Star &T) const {
      if(r != T.r) return r < T.r;
      if(i != T.i) return i < T.i;
      return j < T.j;
   }
};

vector<Star> X;
int di[] = {-1,+1,+0,+0};
int dj[] = {+0,+0,-1,+1};
string board[402];

int n, m, k;

bool check(int i, int j) {
   return i < n && i >= 0 && j < m && j >= 0 && board[i][j] == '*';
}

int main(int argc, char *argv[]) {	
   cin >> n >> m >> k;
   for(int i = 0; i < n; ++i)
      cin >> board[i];
   for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
         if(board[i][j] == '*') {
            for(int r = 1; r <= max(n,m); ++r) {
               int d;
               for(d = 0; d < 4; ++d) {
                  int ni = i + r * di[d];
                  int nj = j + r * dj[d];
                  if(!check(ni,nj)) break;
               }
               if(d == 4) X.push_back(Star(r, i, j));
            }                        
         }
      }
   }
   sort(all(X));
   if(k > sz(X)) {
      cout << -1 << endl;
   } else {
      int r = X[k-1].r;
      int ci = X[k-1].i + 1;
      int cj = X[k-1].j + 1;
      cout << ci  << " " << cj << endl;
      for(int d = 0; d < 4; ++d)
         cout << ci + r * di[d]  << " " << cj + r * dj[d] << endl;
   }   
   return 0;
}

