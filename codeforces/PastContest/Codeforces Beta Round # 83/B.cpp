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
llong A[100010];

llong f(llong x) {
   return x==1LL? 1LL: 2LL*x;
}

int main(int argc, char *argv[]) {
   int N;
   cin >> N;
   for(int i = 0; i < N; ++i)
      cin >> A[i];
   sort(A,A+N);
   bool found = false;
   for(int i = 0; i < N-1; ++i) {
      if(A[i] == A[i+1]) continue;
      if(f(A[i]) > A[i+1]) {
         found = true;
         break;
      }
   }
   if(found) puts("YES");
   else puts("NO");
   return 0;
}

