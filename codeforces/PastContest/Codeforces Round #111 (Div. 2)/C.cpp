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

typedef long long llong;

const int MAXN = 100010;
llong A[MAXN], unq[MAXN], freq[MAXN];
int main(int argc, char *argv[]) {
   llong N, K, ind;
   cin >> N >> K;
   for(int i = 0; i < N; ++i)
      cin >> A[i];
   sort(A, A + N);
   ind = -1;
   for(int i = 0; i < N; ++i) {
      if(i == 0 || A[i] != unq[ind])
         unq[++ind] = A[i];
      freq[ind]++;
   }
   for(int i = 0; i <= ind; ++i) {
      if(freq[i] * N >= K) {
         cout << unq[i] << ' ' << A[(K-1)/freq[i]] << endl;
         break;
      } else {
         K-=freq[i]*N;
      }
   }
   return 0;
}
// END CUT HERE
