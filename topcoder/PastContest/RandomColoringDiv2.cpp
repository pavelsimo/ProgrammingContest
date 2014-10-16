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


class RandomColoringDiv2 {
public:
   int getCount( int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2 ) {
      int res = 0;     
      for(int r = 0; r < maxR; ++r) {
         for(int g = 0; g < maxG; ++g) {
            for(int b = 0; b < maxB; ++b) {
               int dr = abs(startR - r);
               int db = abs(startB - b);
               int dg = abs(startG - g);
               bool c1 = (dr >= d1 || db >= d1 || dg >= d1);
               bool c2 = (dr <= d2 && db <= d2 && dg <= d2);
               if(c1 && c2) res++;
            }            
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
         int maxR                  = 5;
         int maxG                  = 1;
         int maxB                  = 1;
         int startR                = 2;
         int startG                = 0;
         int startB                = 0;
         int d1                    = 0;
         int d2                    = 1;
         int expected__            = 3;

         return verify_case( casenum__, starttime__, expected__, RandomColoringDiv2().getCount( maxR, maxG, maxB, startR, startG, startB, d1, d2 ) );
      }
      case 1: {
         int maxR                  = 4;
         int maxG                  = 2;
         int maxB                  = 2;
         int startR                = 0;
         int startG                = 0;
         int startB                = 0;
         int d1                    = 3;
         int d2                    = 3;
         int expected__            = 4;

         return verify_case( casenum__, starttime__, expected__, RandomColoringDiv2().getCount( maxR, maxG, maxB, startR, startG, startB, d1, d2 ) );
      }
      case 2: {
         int maxR                  = 4;
         int maxG                  = 2;
         int maxB                  = 2;
         int startR                = 0;
         int startG                = 0;
         int startB                = 0;
         int d1                    = 5;
         int d2                    = 5;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, RandomColoringDiv2().getCount( maxR, maxG, maxB, startR, startG, startB, d1, d2 ) );
      }
      case 3: {
         int maxR                  = 6;
         int maxG                  = 9;
         int maxB                  = 10;
         int startR                = 1;
         int startG                = 2;
         int startB                = 3;
         int d1                    = 0;
         int d2                    = 10;
         int expected__            = 540;

         return verify_case( casenum__, starttime__, expected__, RandomColoringDiv2().getCount( maxR, maxG, maxB, startR, startG, startB, d1, d2 ) );
      }
      case 4: {
         int maxR                  = 6;
         int maxG                  = 9;
         int maxB                  = 10;
         int startR                = 1;
         int startG                = 2;
         int startB                = 3;
         int d1                    = 4;
         int d2                    = 10;
         int expected__            = 330;

         return verify_case( casenum__, starttime__, expected__, RandomColoringDiv2().getCount( maxR, maxG, maxB, startR, startG, startB, d1, d2 ) );
      }
      case 5: {
         int maxR                  = 49;
         int maxG                  = 59;
         int maxB                  = 53;
         int startR                = 12;
         int startG                = 23;
         int startB                = 13;
         int d1                    = 11;
         int d2                    = 22;
         int expected__            = 47439;

         return verify_case( casenum__, starttime__, expected__, RandomColoringDiv2().getCount( maxR, maxG, maxB, startR, startG, startB, d1, d2 ) );
      }

      // custom cases

/*
      case 6: {
         int maxR                  = ;
         int maxG                  = ;
         int maxB                  = ;
         int startR                = ;
         int startG                = ;
         int startB                = ;
         int d1                    = ;
         int d2                    = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, RandomColoringDiv2().getCount( maxR, maxG, maxB, startR, startG, startB, d1, d2 ) );
      }
*/
/*
      case 7: {
         int maxR                  = ;
         int maxG                  = ;
         int maxB                  = ;
         int startR                = ;
         int startG                = ;
         int startB                = ;
         int d1                    = ;
         int d2                    = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, RandomColoringDiv2().getCount( maxR, maxG, maxB, startR, startG, startB, d1, d2 ) );
      }
*/
/*
      case 8: {
         int maxR                  = ;
         int maxG                  = ;
         int maxB                  = ;
         int startR                = ;
         int startG                = ;
         int startB                = ;
         int d1                    = ;
         int d2                    = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, RandomColoringDiv2().getCount( maxR, maxG, maxB, startR, startG, startB, d1, d2 ) );
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
