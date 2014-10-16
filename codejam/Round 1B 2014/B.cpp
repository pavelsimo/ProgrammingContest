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

int main(int argc, char *argv[]) { 
  int TC;
  cin >> TC;
  for(int tc = 1; tc <= TC; ++tc) {
    int A, B, K;
    cin >> A >> B >> K;
    int res = 0;
    for(int a = 0; a < A; ++a) {
       for(int b = 0; b < B; ++b) {
          if((a & b) < K) res++;
       }
    }
    printf("Case #%d: %d\n", tc, res);
  }
  return 0;
}