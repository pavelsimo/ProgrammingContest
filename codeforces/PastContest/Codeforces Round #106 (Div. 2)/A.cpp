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

const int MAXN = 12;
vector<int> A;
int main(int argc, char *argv[]) { 
   int k, x, res, sum = 0;
   cin >> k;
   for(int i = 0; i < MAXN; ++i) {
      cin >> x;
      A.push_back(x);
   }
   sort(A.rbegin(),A.rend());
   for(res = 0; res < MAXN; ++res) {
      if(sum >= k) break;
      sum+=A[res];
   }
   if(sum < k) puts("-1");
   else printf("%d\n",res);
   return 0;
}

