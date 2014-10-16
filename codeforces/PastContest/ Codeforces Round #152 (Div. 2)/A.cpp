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

const int MAXN = 10004;
int L[MAXN], R[MAXN];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int N;
   cin >> N;
   for(int i = 0; i < N; ++i)
      cin >> L[i] >> R[i];
   int res = 2 * N + 2;
   for(int i = 0; i < 2; ++i) {
      for(int j = 0; j < 2; ++j) {
         int t = 0;
         for(int k = 0; k < N; ++k) {
            if(L[k] != i) t++;
            if(R[k] != j) t++;
         }
         res = min(res, t);
      }
   }
   cout << res << endl;
   return 0;
}
