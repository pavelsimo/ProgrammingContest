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

vector<pair<int, int> > games;

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int x, y, a, b;
   cin >> x >> y >> a >> b;
   for(int i = a; i <= x; ++i) {
      for(int j = b; j <= y; ++j) {
         if(i <= j) continue;
         games.push_back(make_pair(i, j));
      }
   }
   cout << sz(games) << endl;
   for(int i = 0; i < sz(games); ++i)
      cout << games[i].first << " " << games[i].second << endl;
   return 0;
}
