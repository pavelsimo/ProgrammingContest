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
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef long long llong;
llong hi;

class TheAlmostLuckyNumbersDivOne {
public:
   llong doit(llong cur, bool used = false) {
        if(cur > hi) return 0;
        if(used) {
           return 1 + doit(cur*10LL + 4LL, used) + doit(cur*10LL + 7LL, used);
        } else {
           llong res = 1;
           for(int d = 0; d <= 9; ++d) {
               llong nxt = doit(cur*10LL + d, d!=4 && d!=7);
               res+=nxt;
           }
           return res;
        }
   }
   
   llong solve(llong cur) {
      llong res = 0LL;
      hi = cur;
      for(int d = 1; d <= 9; ++d)
         res+=doit(d, d!=4 && d!=7);
      return res;
   }

   long long find( long long a, long long b ) {
      llong res = solve(b) - solve(a-1);
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
   int verify_case( int casenum, long long starttime, const long long &expected, const long long &received ) {
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
         long long a               = 4LL;
         long long b               = 7LL;
         long long expected__      = 4LL;

         return verify_case( casenum__, starttime__, expected__, TheAlmostLuckyNumbersDivOne().find( a, b ) );
      }
      case 1: {
         long long a               = 8LL;
         long long b               = 19LL;
         long long expected__      = 4LL;

         return verify_case( casenum__, starttime__, expected__, TheAlmostLuckyNumbersDivOne().find( a, b ) );
      }
      case 2: {
         long long a               = 28LL;
         long long b               = 33LL;
         long long expected__      = 0LL;

         return verify_case( casenum__, starttime__, expected__, TheAlmostLuckyNumbersDivOne().find( a, b ) );
      }
      case 3: {
         long long a               = 12345678900LL;
         long long b               = 98765432100LL;
         long long expected__      = 91136LL;

         return verify_case( casenum__, starttime__, expected__, TheAlmostLuckyNumbersDivOne().find( a, b ) );
      }

      // custom cases

/*
      case 4: {
         long long a               = LL;
         long long b               = LL;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, TheAlmostLuckyNumbersDivOne().find( a, b ) );
      }
*/
/*
      case 5: {
         long long a               = LL;
         long long b               = LL;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, TheAlmostLuckyNumbersDivOne().find( a, b ) );
      }
*/
/*
      case 6: {
         long long a               = LL;
         long long b               = LL;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, TheAlmostLuckyNumbersDivOne().find( a, b ) );
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
