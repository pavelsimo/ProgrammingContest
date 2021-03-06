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

class RadarFinder {
public:
   int possibleLocations( llong x1, llong y1, llong r1, llong x2, llong y2, llong r2 ) {
      llong d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
      llong rs = (r1+r2)*(r1+r2);
      llong rd = (r1-r2)*(r1-r2);
      if(x1==x2 && y1 == y2 && r1 == r2) return -1;
      if(d < rs && d > rd) return 2;
      if(d == rs || d == rd) return 1;
      return 0;
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
         int x1                    = 0;
         int y1                    = 0;
         int r1                    = 13;
         int x2                    = 40;
         int y2                    = 0;
         int r2                    = 37;
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, RadarFinder().possibleLocations( x1, y1, r1, x2, y2, r2 ) );
      }
      case 1: {
         int x1                    = 0;
         int y1                    = 0;
         int r1                    = 3;
         int x2                    = 0;
         int y2                    = 7;
         int r2                    = 4;
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, RadarFinder().possibleLocations( x1, y1, r1, x2, y2, r2 ) );
      }
      case 2: {
         int x1                    = 0;
         int y1                    = 0;
         int r1                    = 5;
         int x2                    = 10;
         int y2                    = 10;
         int r2                    = 3;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, RadarFinder().possibleLocations( x1, y1, r1, x2, y2, r2 ) );
      }
      case 3: {
         int x1                    = 0;
         int y1                    = 0;
         int r1                    = 1;
         int x2                    = 0;
         int y2                    = 0;
         int r2                    = 1;
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, RadarFinder().possibleLocations( x1, y1, r1, x2, y2, r2 ) );
      }

      // custom cases

      case 4: {
         int x1                    = 0;
         int y1                    = 0;
         int r1                    = 5;
         int x2                    = 1;
         int y2                    = 0;
         int r2                    = 4;
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, RadarFinder().possibleLocations( x1, y1, r1, x2, y2, r2 ) );
      }

/*
      case 5: {
         int x1                    = ;
         int y1                    = ;
         int r1                    = ;
         int x2                    = ;
         int y2                    = ;
         int r2                    = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, RadarFinder().possibleLocations( x1, y1, r1, x2, y2, r2 ) );
      }
*/
/*
      case 6: {
         int x1                    = ;
         int y1                    = ;
         int r1                    = ;
         int x2                    = ;
         int y2                    = ;
         int r2                    = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, RadarFinder().possibleLocations( x1, y1, r1, x2, y2, r2 ) );
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
