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


class FormatAmt {
public:

   string tostr(int n) {
      string res;
      stringstream ss;
      ss << n;
      ss >> res;
      return res;
   }

   string amount( int dollars, int cents ) {
      string res = "";
      string num = tostr(dollars);
      for(int i = SZ(num)-1, j = 0; i >= 0; --i, ++j) {
         if(j>0 && j%3==0) res=','+res;
         res=num[i]+res;
      }
      res = "$" + res;
      if(cents>=10) res+="."+tostr(cents);
      else res+=".0"+tostr(cents);
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
         int dollars               = 123456;
         int cents                 = 0;
         string expected__         = "$123,456.00";

         return verify_case( casenum__, starttime__, expected__, FormatAmt().amount( dollars, cents ) );
      }
      case 1: {
         int dollars               = 49734321;
         int cents                 = 9;
         string expected__         = "$49,734,321.09";

         return verify_case( casenum__, starttime__, expected__, FormatAmt().amount( dollars, cents ) );
      }
      case 2: {
         int dollars               = 0;
         int cents                 = 99;
         string expected__         = "$0.99";

         return verify_case( casenum__, starttime__, expected__, FormatAmt().amount( dollars, cents ) );
      }
      case 3: {
         int dollars               = 249;
         int cents                 = 30;
         string expected__         = "$249.30";

         return verify_case( casenum__, starttime__, expected__, FormatAmt().amount( dollars, cents ) );
      }
      case 4: {
         int dollars               = 1000;
         int cents                 = 1;
         string expected__         = "$1,000.01";

         return verify_case( casenum__, starttime__, expected__, FormatAmt().amount( dollars, cents ) );
      }

      // custom cases

/*
      case 5: {
         int dollars               = ;
         int cents                 = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, FormatAmt().amount( dollars, cents ) );
      }
*/
/*
      case 6: {
         int dollars               = ;
         int cents                 = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, FormatAmt().amount( dollars, cents ) );
      }
*/
/*
      case 7: {
         int dollars               = ;
         int cents                 = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, FormatAmt().amount( dollars, cents ) );
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
