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

vector<int> heavyPos, metalPos;

vector<int> findAll(const string &str, const string &pattern) {
   vector<int> res; 
   size_t pos = str.find(pattern, 0);
   while(pos != string::npos) {
       res.push_back(pos);
       pos = str.find(pattern,pos + 1);
   }
   return res;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   string S;
   cin >> S;
   heavyPos = findAll(S, "heavy");
   metalPos = findAll(S, "metal");
   llong res = 0LL;
   for(int i = 0; i < sz(metalPos); ++i) {
      llong cnt = lower_bound(all(heavyPos), metalPos[i]) - heavyPos.begin();
      res += cnt;
   }
   cout << res << endl;
   return 0;
}
