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

typedef long long llong;

class LCMSetEasy {
public:

  llong gcd(llong a, llong b) {
     if (a < 0) a = -a;
     if (b < 0) b = -b;
     if (a < b) swap(a, b);
     while (b > 0) {
        llong t = b;
        b = a % b;
        a = t;
     }
     return a > 0 ? a : 1;
  }

  llong lcm(llong a, llong b) {
     return a / gcd(a,b) * b;
  }

  string include( vector <int> S, int x ) {
    llong l = 1LL;
    for(int i = 0; i < SZ(S); ++i) {
      if(x % S[i] == 0) {
        l = lcm(l, S[i]);
        if(l == x) return "Possible";
      }
    }
    return "Impossible";
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
   int verify_case( int casenum, long long starttime, const string &expected, const string &received ) {
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
         cerr << "    Expected: \"" << expected << "\"" << endl; 
         cerr << "    Received: \"" << received << "\"" << endl; 
         return 0;
      }
   }

   int run_test_case( int casenum__ ) {
      long long starttime__ = get_time();
      switch( casenum__ ) {
      case 0: {
         int S[]                   = {2,3,4,5};
         int x                     = 20;
         string expected__         = "Possible";

         return verify_case( casenum__, starttime__, expected__, LCMSetEasy().include( vector <int>( S, S + ( sizeof S / sizeof(int) ) ), x ) );
      }
      case 1: {
         int S[]                   = {2,3,4};
         int x                     = 611;
         string expected__         = "Impossible";

         return verify_case( casenum__, starttime__, expected__, LCMSetEasy().include( vector <int>( S, S + ( sizeof S / sizeof(int) ) ), x ) );
      }
      case 2: {
         int S[]                   = {2,3,4};
         int x                     = 12;
         string expected__         = "Possible";

         return verify_case( casenum__, starttime__, expected__, LCMSetEasy().include( vector <int>( S, S + ( sizeof S / sizeof(int) ) ), x ) );
      }
      case 3: {
         int S[]                   = {1,2,3,4,5,6,7,8,9,10};
         int x                     = 24;
         string expected__         = "Possible";

         return verify_case( casenum__, starttime__, expected__, LCMSetEasy().include( vector <int>( S, S + ( sizeof S / sizeof(int) ) ), x ) );
      }
      case 4: {
         int S[]                   = {100,200,300,400,500,600};
         int x                     = 2000;
         string expected__         = "Possible";

         return verify_case( casenum__, starttime__, expected__, LCMSetEasy().include( vector <int>( S, S + ( sizeof S / sizeof(int) ) ), x ) );
      }
      case 5: {
         int S[]                   = {100,200,300,400,500,600};
         int x                     = 8000;
         string expected__         = "Impossible";

         return verify_case( casenum__, starttime__, expected__, LCMSetEasy().include( vector <int>( S, S + ( sizeof S / sizeof(int) ) ), x ) );
      }
      case 6: {
         int S[]                   = {1000000000,999999999,999999998};
         int x                     = 999999999;
         string expected__         = "Possible";

         return verify_case( casenum__, starttime__, expected__, LCMSetEasy().include( vector <int>( S, S + ( sizeof S / sizeof(int) ) ), x ) );
      }

      // custom cases

/*
      case 7: {
         int S[]                   = ;
         int x                     = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, LCMSetEasy().include( vector <int>( S, S + ( sizeof S / sizeof(int) ) ), x ) );
      }
*/
/*
      case 8: {
         int S[]                   = ;
         int x                     = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, LCMSetEasy().include( vector <int>( S, S + ( sizeof S / sizeof(int) ) ), x ) );
      }
*/
/*
      case 9: {
         int S[]                   = ;
         int x                     = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, LCMSetEasy().include( vector <int>( S, S + ( sizeof S / sizeof(int) ) ), x ) );
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
