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


class CoinsExchange {
public:
   int countExchanges( int G1, int S1, int B1, int G2, int S2, int B2 ) {
      int res = 0;
      while(G1 < G2) {
         if(S1>=11) {
            G1++;
            S1-=11;
            res++;
         } else if(B1>=11) {
            S1++;
            B1-=11;
            res++;
         } else {
            return -1;
         }
      }
      while(S1 < S2) {
         if(G1>G2) {
            G1--;
            S1+=9;
            res++;
         } else if(B1>=11) {
            S1++;
            B1-=11;
            res++;
         } else {
            return -1;
         }
      }
      while(B1 < B2) {
         if(S1 > S2) {
            S1--;
            B1+=9;
            res++;
         } else if(G1 > G2) {
            G1--;
            S1+=9;
            res++;
         } else {
            return -1;
         }
      }
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
         int G1                    = 1;
         int S1                    = 0;
         int B1                    = 0;
         int G2                    = 0;
         int S2                    = 0;
         int B2                    = 81;
         int expected__            = 10;

         return verify_case( casenum__, starttime__, expected__, CoinsExchange().countExchanges( G1, S1, B1, G2, S2, B2 ) );
      }
      case 1: {
         int G1                    = 1;
         int S1                    = 100;
         int B1                    = 12;
         int G2                    = 5;
         int S2                    = 53;
         int B2                    = 33;
         int expected__            = 7;

         return verify_case( casenum__, starttime__, expected__, CoinsExchange().countExchanges( G1, S1, B1, G2, S2, B2 ) );
      }
      case 2: {
         int G1                    = 1;
         int S1                    = 100;
         int B1                    = 12;
         int G2                    = 5;
         int S2                    = 63;
         int B2                    = 33;
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, CoinsExchange().countExchanges( G1, S1, B1, G2, S2, B2 ) );
      }
      case 3: {
         int G1                    = 5;
         int S1                    = 10;
         int B1                    = 12;
         int G2                    = 3;
         int S2                    = 7;
         int B2                    = 9;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, CoinsExchange().countExchanges( G1, S1, B1, G2, S2, B2 ) );
      }

      // custom cases

/*
      case 4: {
         int G1                    = ;
         int S1                    = ;
         int B1                    = ;
         int G2                    = ;
         int S2                    = ;
         int B2                    = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, CoinsExchange().countExchanges( G1, S1, B1, G2, S2, B2 ) );
      }
*/
/*
      case 5: {
         int G1                    = ;
         int S1                    = ;
         int B1                    = ;
         int G2                    = ;
         int S2                    = ;
         int B2                    = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, CoinsExchange().countExchanges( G1, S1, B1, G2, S2, B2 ) );
      }
*/
/*
      case 6: {
         int G1                    = ;
         int S1                    = ;
         int B1                    = ;
         int G2                    = ;
         int S2                    = ;
         int B2                    = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, CoinsExchange().countExchanges( G1, S1, B1, G2, S2, B2 ) );
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
