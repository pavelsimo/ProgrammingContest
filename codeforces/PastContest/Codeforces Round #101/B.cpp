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

int solve(int a, int x, int y) {
   if(y%a == 0) return -1;
   int sq = y/a + y/(2*a);
   if(y < a || (y/a)%2 != 0 ) {
      // one square
      if(2*x > -a && 2*x < a) return sq+1;
      else return -1;
   } 
   // two squares
   if(x == 0) return -1;
   else if(x > -a && x < a) {
      if(x > 0) return sq+1;
      else return sq;
   }
   return -1;
}

int main(int argc, char *argv[]) {
   int a, x, y;
   while(cin >> a >> x >> y)
      printf("%d\n",solve(a,x,y));   
   return 0;
}

