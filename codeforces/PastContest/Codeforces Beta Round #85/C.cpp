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

int memo[1000002];
const int INF = 2000000000;

int rec(int n, int four, int seven) {
   if(n<0) return INF;
   if(n==0) return 1000002*four + seven;
   if(memo[n] >= 0)
      return memo[n];
   return memo[n] = min(rec(n-4, four + 1, seven), rec(n-7, four, seven + 1));
}

int main(int argc, char *argv[]) {
   int N;
   cin >> N;
   memset(memo,-1,sizeof(memo));
   int res = rec(N, 0, 0);      
   if(res==INF) { 
      puts("-1");
   } else {
      int four = res/1000002;
      int seven = res%1000002;
      cout << string(four,'4') << string(seven,'7') << endl;
   }
   return 0;
}

