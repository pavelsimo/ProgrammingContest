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

const int MAXN = 1002;
int A[MAXN];

int main(int argc, char *argv[]) {
   int n;
   scanf("%d",&n);
   for(int i = 0; i < n; ++i)
      scanf("%d",&A[i]);
   for(int j = 0; j <= MAXN; ++j) {
      for(int i = 0; i < n; ++i) {
         bool m = false;
         if(i + 1 < n) if(A[i + 1] > 0) m = true;
         if(i + 2 < n) if(A[i + 2] > 0) m = true;
         if((i != n - 1 && !m) || (i == 0 && A[i] <= 0)) {
            printf("%d\n",j);
            return 0;
         }
         A[i]--;
      }                  
   }
   printf("%d\n",0);
   return 0;
}

