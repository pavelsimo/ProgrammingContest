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
   int N, res = 0, lo = 0, hi = 0;
   cin >> N;
   for(int i = 0; i < N; ++i)
      cin >> A[i];
   for(int i = 1; i < N; ++i) {
      if(A[i] < A[lo]) res++, lo = i;
      if(A[i] > A[hi]) res++, hi = i;
   }
   cout << res << endl;
   return 0;
}

