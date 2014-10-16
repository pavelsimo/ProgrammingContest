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

int a[102];
int main(int argc, char *argv[]) { 
   int n, res, a1, a2;
   cin >> n;
   for(int i = 0; i < n; ++i)
      cin >> a[i];
   res = 10002;
   for(int i = 0; i < n; ++i) {
      int j = (i + 1) % n;
      if(abs(a[i] - a[j]) < res) {
         res = abs(a[i] - a[j]);
         a1 = i;
         a2 = j;
      }
   }
   cout << a1 + 1 << " " << a2 + 1 << endl;
   return 0;
}

