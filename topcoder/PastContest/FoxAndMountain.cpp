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

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

typedef long long llong;

int N;
llong memo[52];
llong MOD = 1000000009LL;

llong go(int n, int x) {
   DEBUG(n);
   DEBUG(x);
   if(x < 0) return 0;
   if(n == N) return x == 0 ? 1LL: 0LL;
   if(memo[n] != -1) return memo[n];
   llong res = 0;
   res = (res + go(n + 1, x - 1)) % MOD;
   res = (res + go(n + 1, x + 1)) % MOD;
   return memo[n] = res % MOD;
}

class FoxAndMountain {
public:
   int count( int n, string history ) {
      N = n;
      memset(memo, -1, sizeof(memo));
      if(n & 1) return 0;
      int res = 0;
      int x = 0;
      for(int i = 0; i < n; ++i) {
         if(history[i] == 'U') ++x;
         else --x;
         if(x < 0) return 0;
      }
      res = go(n + 1, x);
      return res;
   }
};

// BEGIN CUT HERE
namespace moj_harness {
   int run_test_case(int);
   void run_test( int casenum = -1 ) {
      if ( casenum != -1 ) {
         if ( run_test_case( casenum ) == -1 )
            cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
         return;
      }
      
      int correct = 0, total = 0;
      for ( int i=0;; ++i ) {
         int x = run_test_case(i);
         if ( x == -1 ) {
            if ( i >= 100 ) break;
            continue;
         }
         correct += x;
         ++total;
      }
      
      if ( total == 0 ) {
         cerr << "No test cases run." << endl;
      } else if ( correct < total ) {
         cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
      } else {
         cerr << "All " << total << " tests passed!" << endl;
      }
   }
   
   long long get_time() {
#if defined(_SYS_TIME_H_) || defined(_SYS_TIME_H)
      struct timeval tv;
      gettimeofday(&tv, NULL);
      return tv.tv_sec * 1000000LL + tv.tv_usec;
#else
      return 0;
#endif
   }
   int verify_case( int casenum, long long starttime, const int &expected, const int &received ) {
      cerr << "Example " << casenum << "... "; 
      if ( expected == received ) {
         cerr << "PASSED";
#if defined(_SYS_TIME_H_) || defined(_SYS_TIME_H)
         cerr << "  " << (get_time()-starttime)/1000 << "ms";
#endif
         cerr << endl;
         return 1;
      } else {
         cerr << "FAILED";
#if defined(_SYS_TIME_H_) || defined(_SYS_TIME_H)
         cerr << "  " << (get_time()-starttime)/1000 << "ms";
#endif
         cerr << endl;
         cerr << "    Expected: " << expected << endl; 
         cerr << "    Received: " << received << endl; 
         return 0;
      }
   }

   int run_test_case( int casenum__ ) {
      long long starttime__ = get_time();
      switch( casenum__ ) {
      case 0: {
         int n                     = 4;
         string history            = "UUDD";
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, FoxAndMountain().count( n, history ) );
      }
      case 1: {
         int n                     = 4;
         string history            = "DUUD";
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, FoxAndMountain().count( n, history ) );
      }
      case 2: {
         int n                     = 4;
         string history            = "UU";
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, FoxAndMountain().count( n, history ) );
      }
      case 3: {
         int n                     = 49;
         string history            = "U";
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, FoxAndMountain().count( n, history ) );
      }
      case 4: {
         int n                     = 20;
         string history            = "UUUDUUU";
         int expected__            = 990;

         return verify_case( casenum__, starttime__, expected__, FoxAndMountain().count( n, history ) );
      }
      case 5: {
         int n                     = 30;
         string history            = "DUDUDUDUDUDUDUDU";
         int expected__            = 3718;

         return verify_case( casenum__, starttime__, expected__, FoxAndMountain().count( n, history ) );
      }
      case 6: {
         int n                     = 50;
         string history            = "U";
         int expected__            = 946357703;

         return verify_case( casenum__, starttime__, expected__, FoxAndMountain().count( n, history ) );
      }

      // custom cases

/*
      case 7: {
         int n                     = ;
         string history            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, FoxAndMountain().count( n, history ) );
      }
*/
/*
      case 8: {
         int n                     = ;
         string history            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, FoxAndMountain().count( n, history ) );
      }
*/
/*
      case 9: {
         int n                     = ;
         string history            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, FoxAndMountain().count( n, history ) );
      }
*/
      default:
         return -1;
      }
   }
}

// END CUT HERE

// BEGIN CUT HERE
int main(int argc, char *argv[]) {
   if (argc > 1) {
      for (int i = 1; i < argc; ++i)
         moj_harness::run_test(atoi(argv[i]));
   }
   else {
      moj_harness::run_test();
   }
   return 0;
}
// END CUT HERE
