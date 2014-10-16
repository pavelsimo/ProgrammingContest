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

int todec(char *s, int base) {
   int res = 0;
   int n = strlen(s);
   for(int i = 0; i < n; ++i)
      res = res*base + s[i]-'0';
   return res;
}

int main() {
    freopen("digits.in", "r", stdin);
    freopen("digits.out", "w", stdout);
    int n, m;
    char A[128], B[128], prevA, prevB;
    scanf("%s%s",A,B);
    n = strlen(A);
    m = strlen(B);
    for(int i = 0; i < n; ++i) {
       for(int j = 0; j < m; ++j) {
          for(int k = 1; k <= 2; ++k) {
             prevA = A[i]; prevB = B[j];
             A[i] = (A[i] - '0' + 1) % 2 + '0';
             B[j] = (B[j] - '0' + k) % 3 + '0';
             if(todec(A, 2) == todec(B, 3)) {
                printf("%d\n",todec(A, 2));
                return 0;
             }
             A[i] = prevA;
             B[j] = prevB;
          }
       }
    }
    return 0;
}
