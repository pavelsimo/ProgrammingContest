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

struct Event {
  int start, end; 
  bool operator<(const Event &T) const {
     if(start != T.start) return start < T.start;
     return end > T.end;
  }
};

Event A[100020];
int main(int argc, char *argv[]) {
   int n, res = 0, hi = 0;;
   cin >> n;
   for(int i = 0; i < n; ++i)
      cin >> A[i].start >> A[i].end;
   sort(A,A+n);
   for(int i = 0; i < n - 1; ++i) {
      hi = max(hi,A[i].end);
      if(A[i + 1].end < hi) res++;
   }
   cout << res << endl;
   return 0;
}

