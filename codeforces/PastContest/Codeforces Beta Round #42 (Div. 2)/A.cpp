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

map<string, int> goals;

int main(int argc, char *argv[]) {
   string team;
   int n;
   cin >> n;
   for(int i = 0; i < n; ++i) {
      cin >> team;
      goals[team]++;
   }
   string res = "";
   int best = 0;
   foreach(it, goals) {
      if(it->second > best) {
         best = it->second;
         res = it->first;
      }
   }
   cout << res << endl;
   return 0;
}

 
