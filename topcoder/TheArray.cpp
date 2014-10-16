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


class TheArray {
public:
   int find( int n, int d, int first, int last ) {
      int res = max(first, last);
      if(first > last) swap(first, last);
      int sum = first;
      for(int i = 1; i < n - 1; ++i) {
         int e_left = n - i - 1;
         int can = (sum + d) - (e_left * d);
         if(can <= last) { 
            sum += d;   
            res = max(res, sum);
         } else {
            for(int j = 0; j <= d; ++j)
               if((sum + j) - (e_left * d) <= last)
                  res = max(res, sum + j);
            break;
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
         int n                     = 3;
         int d                     = 5;
         int first                 = 2;
         int last                  = 4;
         int expected__            = 7;

         return verify_case( casenum__, starttime__, expected__, TheArray().find( n, d, first, last ) );
      }
      case 1: {
         int n                     = 10;
         int d                     = 100;
         int first                 = 999;
         int last                  = 100;
         int expected__            = 999;

         return verify_case( casenum__, starttime__, expected__, TheArray().find( n, d, first, last ) );
      }
      case 2: {
         int n                     = 1000000;
         int d                     = 0;
         int first                 = 474;
         int last                  = 474;
         int expected__            = 474;

         return verify_case( casenum__, starttime__, expected__, TheArray().find( n, d, first, last ) );
      }
      case 3: {
         int n                     = 97;
         int d                     = 53;
         int first                 = -92;
         int last                  = 441;
         int expected__            = 2717;

         return verify_case( casenum__, starttime__, expected__, TheArray().find( n, d, first, last ) );
      }
      case 4: {
         int n                     = 99;
         int d                     = 3;
         int first                 = -743;
         int last                  = -619;
         int expected__            = -535;

         return verify_case( casenum__, starttime__, expected__, TheArray().find( n, d, first, last ) );
      }

      // custom cases

/*
      case 5: {
         int n                     = ;
         int d                     = ;
         int first                 = ;
         int last                  = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, TheArray().find( n, d, first, last ) );
      }
*/
/*
      case 6: {
         int n                     = ;
         int d                     = ;
         int first                 = ;
         int last                  = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, TheArray().find( n, d, first, last ) );
      }
*/
/*
      case 7: {
         int n                     = ;
         int d                     = ;
         int first                 = ;
         int last                  = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, TheArray().find( n, d, first, last ) );
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
