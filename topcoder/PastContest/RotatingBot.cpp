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


int di[] = {+0,-1,+0,+1};
int dj[] = {+1,+0,-1,+0};

class RotatingBot {
public:
   int minArea( vector <int> moves ) {

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
         int moves[]               = {15};
         int expected__            = 16;

         return verify_case( casenum__, starttime__, expected__, RotatingBot().minArea( vector <int>( moves, moves + ( sizeof moves / sizeof(int) ) ) ) );
      }
      case 1: {
         int moves[]               = {3,10};
         int expected__            = 44;

         return verify_case( casenum__, starttime__, expected__, RotatingBot().minArea( vector <int>( moves, moves + ( sizeof moves / sizeof(int) ) ) ) );
      }
      case 2: {
         int moves[]               = {1,1,1,1};
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, RotatingBot().minArea( vector <int>( moves, moves + ( sizeof moves / sizeof(int) ) ) ) );
      }
      case 3: {
         int moves[]               = {9,5,11,10,11,4,10};
         int expected__            = 132;

         return verify_case( casenum__, starttime__, expected__, RotatingBot().minArea( vector <int>( moves, moves + ( sizeof moves / sizeof(int) ) ) ) );
      }
      case 4: {
         int moves[]               = {12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15};
         int expected__            = 420;

         return verify_case( casenum__, starttime__, expected__, RotatingBot().minArea( vector <int>( moves, moves + ( sizeof moves / sizeof(int) ) ) ) );
      }
      case 5: {
         int moves[]               = {8,6,6,1};
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, RotatingBot().minArea( vector <int>( moves, moves + ( sizeof moves / sizeof(int) ) ) ) );
      }
      case 6: {
         int moves[]               = {8,6,6};
         int expected__            = 63;

         return verify_case( casenum__, starttime__, expected__, RotatingBot().minArea( vector <int>( moves, moves + ( sizeof moves / sizeof(int) ) ) ) );
      }
      case 7: {
         int moves[]               = {5,4,5,3,3};
         int expected__            = 30;

         return verify_case( casenum__, starttime__, expected__, RotatingBot().minArea( vector <int>( moves, moves + ( sizeof moves / sizeof(int) ) ) ) );
      }

      // custom cases

/*
      case 8: {
         int moves[]               = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, RotatingBot().minArea( vector <int>( moves, moves + ( sizeof moves / sizeof(int) ) ) ) );
      }
*/
/*
      case 9: {
         int moves[]               = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, RotatingBot().minArea( vector <int>( moves, moves + ( sizeof moves / sizeof(int) ) ) ) );
      }
*/
/*
      case 10: {
         int moves[]               = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, RotatingBot().minArea( vector <int>( moves, moves + ( sizeof moves / sizeof(int) ) ) ) );
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
