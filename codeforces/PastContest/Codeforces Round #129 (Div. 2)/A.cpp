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
   int n, ai;
   cin >> n;
   for(int i = 0; i < n; ++i) {
      cin >> ai;
      X.push_back(make_pair(ai, i));
   }
   sort(all(X));
   if(sz(X) >= 2) {
      if(X[0].first == X[1].first) cout << "Still Rozdil" << endl;
      else cout << X[0].second + 1 << endl;
   } else {
      cout << X[0].second + 1 << endl;
   }
   return 0;
}

