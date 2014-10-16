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

int S[202], A, N;

int main(int argc, char *argv[]) { 
   int TC;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%d%d",&A, &N);
      for(int i = 0; i < N; ++i)
         scanf("%d",&S[i]);
      sort(S, S + N);
      int res = N;
      for(int k = N; k >= 0; --k) {
         int cnt = 0;
         llong s = A;
         for(int i = 0; i < k; ++i) {
            if(s > S[i]) {
               s += S[i];
               continue;
            }
            if(s - 1 <= 0) {
               cnt = N;
               break;
            }
            while(s <= S[i]) ++cnt, s += (s - 1);
            if(s > S[i]) s += S[i];
         }         
         res = min(res, cnt + (N - k));
      }
      printf("Case #%d: %d\n",tc,res);
   }
   return 0;
}
