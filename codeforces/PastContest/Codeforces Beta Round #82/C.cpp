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

int m, c0, d0;
int a[102],b[102],c[102],d[102];
int memo[12][1024];

int rec(int cur, int dough) {
   if(dough==0) return 0;
   if(cur >= m) return (dough/c0)*d0;
   if(memo[cur][dough] >= 0) 
      return memo[cur][dough];
   int res = 0;
   for(int i = 0; b[cur]*i <= a[cur]; ++i)
      if(dough >= i*c[cur])
         res = max(res,rec(cur+1,dough-i*c[cur]) + d[cur]*i);
   return memo[cur][dough] = res;
}

int main(int argc, char *argv[]) {
   int n;
   cin >> n >> m >> c0 >> d0;
   memset(memo,-1,sizeof(memo));
   for(int i = 0; i < m; ++i)
      cin >> a[i] >> b[i] >> c[i] >> d[i];
   printf("%d\n",rec(0,n));
   return 0;
}

