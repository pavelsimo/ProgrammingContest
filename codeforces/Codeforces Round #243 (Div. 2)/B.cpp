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

const int MAXN = 128;
int A[MAXN][MAXN];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n, m; 
   while(cin >> n >> m) {
      if(n & 1) {
         cout << n << endl;
         return 0;
      }
      for(int i = 0; i < n; ++i) {
         for(int j = 0; j < m; ++j) {
            cin >> A[i][j];
         }
      }
      int b = n;
      while(b % 2 == 0) {
         bool ok = true;
         for(int i = 0; i < b/2; ++i) {
            int j;
            for(j = 0; j < m; ++j) {
               if(A[i][j] != A[b - i - 1][j]) break;
            }
            if(j != m) {
               ok = false;
            }
         }
         if(!ok) {
            break;
         }
         b/=2;
      }
      cout << b << endl;
   }
   
   return 0;
}
