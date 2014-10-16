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

vector<pair<int,int> > X;

int main(int argc, char *argv[]) {
   int n;
   cin >> n;
   for(int i = 1; i <= n; ++i) {
      for(int j = 1; i + j <= n; j+=2) {
         X.push_back(make_pair(i, i + j));
      }
   }
   cout << sz(X) << endl;
   for(int i = 0; i < sz(X); ++i) 
      cout << X[i].first << ' ' << X[i].second << '\n';
   return 0;
}

