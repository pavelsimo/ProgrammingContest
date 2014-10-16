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


class NumberLabyrinthDiv2 {
public:
   int getMinimumNumberOfMoves( vector <string> board, int r1, int c1, int r2, int c2, int K ) {

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
         string board[]            = {"...2",  "....",  "3..."};
         int r1                    = 0;
         int c1                    = 0;
         int r2                    = 2;
         int c2                    = 3;
         int K                     = 0;
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, NumberLabyrinthDiv2().getMinimumNumberOfMoves( vector <string>( board, board + ( sizeof board / sizeof(string) ) ), r1, c1, r2, c2, K ) );
      }
      case 1: {
         string board[]            = {"...2",  "....",  "3..."};
         int r1                    = 0;
         int c1                    = 0;
         int r2                    = 2;
         int c2                    = 3;
         int K                     = 1;
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, NumberLabyrinthDiv2().getMinimumNumberOfMoves( vector <string>( board, board + ( sizeof board / sizeof(string) ) ), r1, c1, r2, c2, K ) );
      }
      case 2: {
         string board[]            = {"...3",  "....",  "2..."};
         int r1                    = 0;
         int c1                    = 0;
         int r2                    = 2;
         int c2                    = 3;
         int K                     = 3;
         int expected__            = 3;

         return verify_case( casenum__, starttime__, expected__, NumberLabyrinthDiv2().getMinimumNumberOfMoves( vector <string>( board, board + ( sizeof board / sizeof(string) ) ), r1, c1, r2, c2, K ) );
      }
      case 3: {
         string board[]            = {"55255",  ".0.0.",  "..9..",  "..3..",  "3.9.3",  "44.44"};
         int r1                    = 3;
         int c1                    = 2;
         int r2                    = 4;
         int c2                    = 2;
         int K                     = 10;
         int expected__            = 6;

         return verify_case( casenum__, starttime__, expected__, NumberLabyrinthDiv2().getMinimumNumberOfMoves( vector <string>( board, board + ( sizeof board / sizeof(string) ) ), r1, c1, r2, c2, K ) );
      }
      case 4: {
         string board[]            = {"920909949",  "900020000",  "009019039",  "190299149",  "999990319",  "940229120",  "000409399",  "999119320",  "009939999"};
         int r1                    = 7;
         int c1                    = 3;
         int r2                    = 1;
         int c2                    = 1;
         int K                     = 50;
         int expected__            = 10;

         return verify_case( casenum__, starttime__, expected__, NumberLabyrinthDiv2().getMinimumNumberOfMoves( vector <string>( board, board + ( sizeof board / sizeof(string) ) ), r1, c1, r2, c2, K ) );
      }

      // custom cases

/*
      case 5: {
         string board[]            = ;
         int r1                    = ;
         int c1                    = ;
         int r2                    = ;
         int c2                    = ;
         int K                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, NumberLabyrinthDiv2().getMinimumNumberOfMoves( vector <string>( board, board + ( sizeof board / sizeof(string) ) ), r1, c1, r2, c2, K ) );
      }
*/
/*
      case 6: {
         string board[]            = ;
         int r1                    = ;
         int c1                    = ;
         int r2                    = ;
         int c2                    = ;
         int K                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, NumberLabyrinthDiv2().getMinimumNumberOfMoves( vector <string>( board, board + ( sizeof board / sizeof(string) ) ), r1, c1, r2, c2, K ) );
      }
*/
/*
      case 7: {
         string board[]            = ;
         int r1                    = ;
         int c1                    = ;
         int r2                    = ;
         int c2                    = ;
         int K                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, NumberLabyrinthDiv2().getMinimumNumberOfMoves( vector <string>( board, board + ( sizeof board / sizeof(string) ) ), r1, c1, r2, c2, K ) );
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
