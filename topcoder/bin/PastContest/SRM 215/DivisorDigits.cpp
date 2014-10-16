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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl

#define SZ(a) int((a).size())
#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)


class DivisorDigits {
public:
   int howMany( int number ) {
      int res = 0;
      int x = number;
      while(x > 0) {
         int d = x%10;
         if(d!=0 && number%d==0) res++;
         x/=10;
      }
      return res;
   }
};




// Powered by FileEdit
// Powered by moj 4 beta 2 [modified TZTester]
// Powered by CodeProcessor
