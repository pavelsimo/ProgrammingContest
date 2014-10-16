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

vector<int> ans;
pair<int,int> A[1002];

int main(int argc, char *argv[]) { 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
   int n, k, X = 0;
   cin >> n >> k;
   for(int i = 0; i < n; ++i) {
      cin >> A[i].first;
      A[i].second = i;
      X = max(X, A[i].first);
   }
   sort(A, A + n);
   for(int i = n - 1; i >= 0 && k-- > 0; --i) {
      ans.push_back(A[i].second + 1);
      X = min(A[i].first, X);
   }
   sort(all(ans));
   cout << X << endl;
   for(int i = 0; i < sz(ans); ++i)
      cout << ans[i] << ' ';
   cout << endl;
   return 0;
}

