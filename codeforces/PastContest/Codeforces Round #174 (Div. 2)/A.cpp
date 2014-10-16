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

const int MAXN = 2002;

llong A[MAXN][MAXN];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int P;
   cin >> P;
   for(int xi = 0; xi < MAXN; ++xi) {
      int prod = 1;
      for(int pi = 0; pi < MAXN; ++pi) {
         A[xi][pi] = prod;
         prod = (prod * xi) % P;
      }      
   }
   int res = 0;
   for(int xi = 0; xi < P; ++xi) {
      bool ok = true;
      for(int pi = 1; pi <= P - 2; ++pi) {
         if((P + A[xi][pi] - 1) % P == 0) {
            ok = false;
            break;
         }
      }
      if((P + A[xi][P-1] - 1) % P != 0) ok = false;
      if(ok) res++;
   }
   cout << res << endl;
   return 0;
}
