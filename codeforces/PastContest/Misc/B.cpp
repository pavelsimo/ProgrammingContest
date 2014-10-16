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

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;

#define DEBUG(x) cout << #x << ": " << x << endl
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define sz(a) int((a).size())


vector<int> A;

int main() {
   int N, x;
   llong res = 0LL;
   cin >> N;
   for(int i = 0; i < N; ++i) {
      cin >> x;
      A.push_back(x);
   }
   int j;
   for(int i = 0; i < N; ++i) {
      llong k = 1LL;
      for(j = i + 1; j < N && A[j] == A[i]; ++j, ++k);
      res+=(k+1LL)*(k)/2LL;
      i = j-1;
   }
   cout << res << endl;
   return 0;
}
