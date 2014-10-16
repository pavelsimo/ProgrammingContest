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


class PointErasingTwo {
public:
   int getMaximum( vector <int> y ) {
      int res = 0;
      for(int x1 = 0; x1 < sz(y); ++x1) {
         int y1 = y[x1];
         for(int x2 = x1 + 1; x2 < sz(y); ++x2) {
            int y2 = y[x2];
            int cnt = 0;
            for(int x3 = 0; x3 < sz(y); ++x3) {
               if(x3 == x1 || x3 == x2) continue;
               int y3 = y[x3];
               int xmin = min(x1,x2);
               int xmax = max(x1,x2);
               int ymin = min(y1,y2);
               int ymax = max(y1,y2);  
               if(x3 > xmin && x3 < xmax && y3 > ymin && y3 < ymax) {
                  cnt++;
               }
            }
            res = max(res,cnt);
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
         int y[]                   = { 1, 2, 1, 1, 0, 4, 3 };
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, PointErasingTwo().getMaximum( vector <int>( y, y + ( sizeof y / sizeof(int) ) ) ) );
      }
      case 1: {
         int y[]                   = { 0, 1 };
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, PointErasingTwo().getMaximum( vector <int>( y, y + ( sizeof y / sizeof(int) ) ) ) );
      }
      case 2: {
         int y[]                   = { 0, 1, 2, 3, 4 };
         int expected__            = 3;

         return verify_case( casenum__, starttime__, expected__, PointErasingTwo().getMaximum( vector <int>( y, y + ( sizeof y / sizeof(int) ) ) ) );
      }
      case 3: {
         int y[]                   = { 10, 19, 10, 19 };
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, PointErasingTwo().getMaximum( vector <int>( y, y + ( sizeof y / sizeof(int) ) ) ) );
      }
      case 4: {
         int y[]                   = { 0, 23, 49, 50, 32, 0, 18, 50, 0, 28, 50, 27, 49, 0 };
         int expected__            = 5;

         return verify_case( casenum__, starttime__, expected__, PointErasingTwo().getMaximum( vector <int>( y, y + ( sizeof y / sizeof(int) ) ) ) );
      }

      // custom cases

/*
      case 5: {
         int y[]                   = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, PointErasingTwo().getMaximum( vector <int>( y, y + ( sizeof y / sizeof(int) ) ) ) );
      }
*/
/*
      case 6: {
         int y[]                   = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, PointErasingTwo().getMaximum( vector <int>( y, y + ( sizeof y / sizeof(int) ) ) ) );
      }
*/
/*
      case 7: {
         int y[]                   = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, PointErasingTwo().getMaximum( vector <int>( y, y + ( sizeof y / sizeof(int) ) ) ) );
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
