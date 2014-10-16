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


int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   int n, m, ai;
   priority_queue<int> q1; 
   priority_queue<int, vector<int>, greater<int> > q2;
   int ma, mi;
   cin >> n >> m;
   for(int i = 0; i < m; ++i) {
      cin >> ai;
      q1.push(ai); q2.push(ai);
   }
   ma = mi = 0;
   for(int i = 0; i < n; ++i) {
      if(q1.empty()) break;
      int x = q1.top();
      q1.pop();
      ma += x;
      --x;
      if(x > 0) q1.push(x);
   }
   for(int i = 0; i < n; ++i) {
      if(q2.empty()) break;
      int x = q2.top();
      q2.pop();
      mi += x;
      --x;
      if(x > 0) q2.push(x);
   }
   cout << ma << " " << mi << endl;
   return 0;
}

