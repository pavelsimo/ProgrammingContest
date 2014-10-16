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

int check(llong n, llong l) {
   int res = 0;
   llong k = n;
   while(n <= l) {
      if(n == l) 
         return res;
      res++;
      n*=k;
   }
   return -1;
}

int main(int argc, char *argv[]) {
   llong k, l;
   cin >> k >> l;
   int res = check(k,l);
   if(res >= 0) {
      puts("YES");
      printf("%d\n",res);
   } else {
      puts("NO");
   }
   return 0;
}

