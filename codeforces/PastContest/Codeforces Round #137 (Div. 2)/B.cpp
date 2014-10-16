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

int C[1002];
int R[1002];
int A[1002][1002];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   string cmd;
   int n, m, k, x, y;
   cin >> n >> m >> k;
   
   for(int i = 0; i < n; ++i) R[i] = i;
   for(int i = 0; i < m; ++i) C[i] = i;
   
   for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
         cin >> A[i][j];
      }
   }
   while(k-- > 0) {
      cin >> cmd >> x >> y;
      --x; --y;
      if(cmd[0] == 'c') 
         swap(C[x], C[y]);
      else if(cmd[0] == 'r')
         swap(R[x], R[y]);
      else
         printf("%d\n",A[R[x]][C[y]]);
   }
   return 0;
}

