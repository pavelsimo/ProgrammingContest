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

int N;
vector<double> R1, P1, P2;

int main(int argc, char *argv[]) {
   int n, m, q; 
   double A, B, _r1, _p1, _p2;
   cin >> n;
   for(int i = 0; i < n; ++i) {
      cin >> _r1;
      R1.push_back(_r1);
   }
   cin >> m;
   for(int i = 0; i < m; ++i) {
      cin >> _p1;
      P1.push_back(_p1);
   }
   cin >> q;
   for(int i = 0; i < q; ++i) {
      cin >> _p2;
      P2.push_back(_p2);
   }
   cin >> A >> B;
   
   return 0;
}

 
