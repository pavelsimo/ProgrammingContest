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


class GuessingNextElement {
public:
   int guess( vector <int> A ) {
      int res = 0;
      int N = A.size();
      if (A[1] + (A[1]-A[0]) == A[2])
         res = A[0] + (N * (A[1]-A[0]));
      else
         res = A[0] * int(pow(A[1] / A[0], N));
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
         int A[]                   = {364,843,1322,1801};
         int expected__            = 2280;

         return verify_case( casenum__, starttime__, expected__, GuessingNextElement().guess( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
      }
      case 1: {
         int A[]                   = {394,1172,1950,2728,3506,4284,5062,5840};
         int expected__            = 6618;

         return verify_case( casenum__, starttime__, expected__, GuessingNextElement().guess( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
      }
      case 2: {
         int A[]                   = {13,117,1053,9477,85293};
         int expected__            = 767637;

         return verify_case( casenum__, starttime__, expected__, GuessingNextElement().guess( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
      }
      case 3: {
         int A[]                   = {22,220,2200,22000};
         int expected__            = 220000;

         return verify_case( casenum__, starttime__, expected__, GuessingNextElement().guess( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
      }
      case 4: {
         int A[]                   = {250000, 500000, 1000000};
         int expected__            = 2000000;

         return verify_case( casenum__, starttime__, expected__, GuessingNextElement().guess( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
      }

      // custom cases

/*
      case 5: {
         int A[]                   = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, GuessingNextElement().guess( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
      }
*/
/*
      case 6: {
         int A[]                   = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, GuessingNextElement().guess( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
      }
*/
/*
      case 7: {
         int A[]                   = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, GuessingNextElement().guess( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
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
