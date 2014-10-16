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

const int MAXN = 7;
int A[MAXN];

int main(int argc, char *argv[]) {   
   int n, res = 0;
   cin >> n;
   for(int i = 0; i < MAXN; ++i)
      cin >> A[i];
   while(true) {
      n-=A[res];
      if(n <= 0) break;
      res = (res + 1) % 7;
   }
   cout << res + 1 << endl;
   return 0;
}

