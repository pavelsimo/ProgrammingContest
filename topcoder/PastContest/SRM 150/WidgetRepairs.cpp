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


class WidgetRepairs {
public:
   int days( vector <int> a, int numPerDay ) {
      int res = 0;
      int cur = 0;
      for(int i = 0; i < SZ(a); ++i) {
         cur+=a[i];
         if(cur>0) res++;
         cur=max(0,cur-numPerDay);
      }
      res+=(cur+numPerDay-1)/numPerDay;
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
         int arrivals[]            = { 10, 0, 0, 4, 20 };
         int numPerDay             = 8;
         int expected__            = 6;

         return verify_case( casenum__, starttime__, expected__, WidgetRepairs().days( vector <int>( arrivals, arrivals + ( sizeof arrivals / sizeof(int) ) ), numPerDay ) );
      }
      case 1: {
         int arrivals[]            = { 0, 0, 0 };
         int numPerDay             = 10;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, WidgetRepairs().days( vector <int>( arrivals, arrivals + ( sizeof arrivals / sizeof(int) ) ), numPerDay ) );
      }
      case 2: {
         int arrivals[]            = { 100, 100 };
         int numPerDay             = 10;
         int expected__            = 20;

         return verify_case( casenum__, starttime__, expected__, WidgetRepairs().days( vector <int>( arrivals, arrivals + ( sizeof arrivals / sizeof(int) ) ), numPerDay ) );
      }
      case 3: {
         int arrivals[]            = { 27, 0, 0, 0, 0, 9 };
         int numPerDay             = 9;
         int expected__            = 4;

         return verify_case( casenum__, starttime__, expected__, WidgetRepairs().days( vector <int>( arrivals, arrivals + ( sizeof arrivals / sizeof(int) ) ), numPerDay ) );
      }
      case 4: {
         int arrivals[]            = { 6, 5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5, 6 };
         int numPerDay             = 3;
         int expected__            = 15;

         return verify_case( casenum__, starttime__, expected__, WidgetRepairs().days( vector <int>( arrivals, arrivals + ( sizeof arrivals / sizeof(int) ) ), numPerDay ) );
      }

      // custom cases

/*
      case 5: {
         int arrivals[]            = ;
         int numPerDay             = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, WidgetRepairs().days( vector <int>( arrivals, arrivals + ( sizeof arrivals / sizeof(int) ) ), numPerDay ) );
      }
*/
/*
      case 6: {
         int arrivals[]            = ;
         int numPerDay             = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, WidgetRepairs().days( vector <int>( arrivals, arrivals + ( sizeof arrivals / sizeof(int) ) ), numPerDay ) );
      }
*/
/*
      case 7: {
         int arrivals[]            = ;
         int numPerDay             = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, WidgetRepairs().days( vector <int>( arrivals, arrivals + ( sizeof arrivals / sizeof(int) ) ), numPerDay ) );
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
