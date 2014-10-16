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
#define FOREACH(it,c) for(__typeof__((c).begin()) it=(c).begin();it!=(c).end();++it)


class LittleElephantAndBallsAgain {
public:
   int getNumber2( string S ) {
      int res = SZ(S) + 2;
      for(int i = 0; i < SZ(S); ++i) {
         for(int j = i; j < SZ(S); ++j) {
            set<char> X;
            for(int k = i; k <= j; ++k) X.insert(S[k]);            
            if(X.size() == 1) res = min(res, i + SZ(S) - j - 1);
         }
      }
      return res;
   }
   
   int getNumber( string S ) {
      int ma = 0;
      int cnt = 0;
      for(int i = 0; i < SZ(S); ++i) {
         if(i > 0 && S[i-1] != S[i]) cnt = 0;
         cnt++;
         ma = max(ma, cnt);
      }
      return SZ(S) - ma;
   }
};




// Powered by FileEdit
// Powered by moj 4 beta 2 [modified TZTester]
// Powered by CodeProcessor
