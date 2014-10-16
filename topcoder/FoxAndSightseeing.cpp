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


class FoxAndSightseeing {
public:
   int getMin( vector <int> A ) {
      int res = 100000002;
      for(int i = 1; i < SZ(A) - 1; ++i) {
         vector<int> tmp;
         for(int j = 0; j < SZ(A); ++j) {
            if(j == i) continue;
            tmp.push_back(A[j]);
         }
         int sum = 0;
         for(int j = 1; j < SZ(tmp); ++j) {
            sum += abs(tmp[j-1] - tmp[j]);
         }
         res = min(res, sum);
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
         int position[]            = {1, 4, -1, 3};
         int expected__            = 4;

         return verify_case( casenum__, starttime__, expected__, FoxAndSightseeing().getMin( vector <int>( position, position + ( sizeof position / sizeof(int) ) ) ) );
      }
      case 1: {
         int position[]            = {-2, 4, 3};
         int expected__            = 5;

         return verify_case( casenum__, starttime__, expected__, FoxAndSightseeing().getMin( vector <int>( position, position + ( sizeof position / sizeof(int) ) ) ) );
      }
      case 2: {
         int position[]            = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
         int expected__            = 9;

         return verify_case( casenum__, starttime__, expected__, FoxAndSightseeing().getMin( vector <int>( position, position + ( sizeof position / sizeof(int) ) ) ) );
      }
      case 3: {
         int position[]            = {100, -100, 99, -99};
         int expected__            = 199;

         return verify_case( casenum__, starttime__, expected__, FoxAndSightseeing().getMin( vector <int>( position, position + ( sizeof position / sizeof(int) ) ) ) );
      }
      case 4: {
         int position[]            = {74,84,92,23,5,-70,-47,-59,24,-86,-39,99,85,-42,54,100,47,-3,42,38};
         int expected__            = 836;

         return verify_case( casenum__, starttime__, expected__, FoxAndSightseeing().getMin( vector <int>( position, position + ( sizeof position / sizeof(int) ) ) ) );
      }
      case 5: {
         int position[]            = {2,-3,5,7,-11,-13,17,-19,23,29,-31,-37,-41,43,-47,-53,-59,61,-67,71};
         int expected__            = 535;

         return verify_case( casenum__, starttime__, expected__, FoxAndSightseeing().getMin( vector <int>( position, position + ( sizeof position / sizeof(int) ) ) ) );
      }

      // custom cases

/*
      case 6: {
         int position[]            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, FoxAndSightseeing().getMin( vector <int>( position, position + ( sizeof position / sizeof(int) ) ) ) );
      }
*/
/*
      case 7: {
         int position[]            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, FoxAndSightseeing().getMin( vector <int>( position, position + ( sizeof position / sizeof(int) ) ) ) );
      }
*/
/*
      case 8: {
         int position[]            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, FoxAndSightseeing().getMin( vector <int>( position, position + ( sizeof position / sizeof(int) ) ) ) );
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
