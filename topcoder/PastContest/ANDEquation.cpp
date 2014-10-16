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


class ANDEquation {
public:
   int restoreY( vector <int> A ) {
      for(int i = 0; i < sz(A); ++i) {
         int val = 0;
         bool first = true;
         for(int j = 0; j < sz(A); ++j) {  
            if(i == j) continue;
            if(first) val = A[j];
            else val&=A[j];
            first = false;
         }
         if(val == A[i])
            return A[i];
      }
      return -1;
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
         int A[]                   = {1, 3, 5} ;
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, ANDEquation().restoreY( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
      }
      case 1: {
         int A[]                   = {31, 7} ;
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, ANDEquation().restoreY( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
      }
      case 2: {
         int A[]                   = {31, 7, 7} ;
         int expected__            = 7;

         return verify_case( casenum__, starttime__, expected__, ANDEquation().restoreY( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
      }
      case 3: {
         int A[]                   = {1,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,  0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,1};
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, ANDEquation().restoreY( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
      }
      case 4: {
         int A[]                   = {191411,256951,191411,191411,191411,256951,195507,191411,192435,191411,  191411,195511,191419,191411,256947,191415,191475,195579,191415,191411,  191483,191411,191419,191475,256947,191411,191411,191411,191419,256947,  191411,191411,191411};
         int expected__            = 191411;

         return verify_case( casenum__, starttime__, expected__, ANDEquation().restoreY( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
      }
      case 5: {
         int A[]                   = {1362,1066,1659,2010,1912,1720,1851,1593,1799,1805,1139,1493,1141,1163,1211};
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, ANDEquation().restoreY( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
      }
      case 6: {
         int A[]                   = {2, 3, 7, 19};
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, ANDEquation().restoreY( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
      }

      // custom cases

/*
      case 7: {
         int A[]                   = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, ANDEquation().restoreY( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
      }
*/
/*
      case 8: {
         int A[]                   = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, ANDEquation().restoreY( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
      }
*/
/*
      case 9: {
         int A[]                   = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, ANDEquation().restoreY( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
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
