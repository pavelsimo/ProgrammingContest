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

vector<llong> X;

void dfs(llong n, int c4, int c7) {
   if(c4 >= 6 || c7 >= 6) return;
   if(n && c4 == c7) X.push_back(n);
   dfs(n * 10 + 4, c4 + 1, c7);
   dfs(n * 10 + 7, c4, c7 + 1);
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   dfs(0,0,0);
   sort(all(X));
   llong n;
   cin >> n;
   int ind = int(lower_bound(all(X), n) - X.begin());
   cout << X[ind] << endl;
   return 0;
}

