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

class Pathfinding {
public:
   int getDirections( int x, int y ) {
      int ax = abs(x); 
      int ay = abs(y);
      if(x>=0 && y>=0) {
         if(x%2==0 || y%2==0) {//++
            return ax + ay;
         } else {
            return ax + ay + 2;
         }
      } else if(x > 0 && y < 0) {//+-
         if(x%2==1 || y%2==0) {
            return ax + ay;
         } else {
            return ax + ay + 2;
         }
      } else if(x < 0 && y > 0) {//-+
         if(x%2==0 || y%2==1) {
            return ax + ay;
         } else {
            return ax + ay + 2;
         }
      }
      if(x%2==-1 || y%2==-1)
         return ax + ay + 2;
      return ax + ay + 4;
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
         int x                     = 0; // E
         int y                     = -4; // E
         int expected__            = 8;

         return verify_case( casenum__, starttime__, expected__, Pathfinding().getDirections( x, y ) );
      }
      case 1: {
         int x                     = 5; // O
         int y                     = -4; // -E
         int expected__            = 9;

         return verify_case( casenum__, starttime__, expected__, Pathfinding().getDirections( x, y ) );
      }
      case 2: {
         int x                     = 5;
         int y                     = 4;
         int expected__            = 9;

         return verify_case( casenum__, starttime__, expected__, Pathfinding().getDirections( x, y ) );
      }
      case 3: {
         int x                     = -1;
         int y                     = -4;
         int expected__            = 7;

         return verify_case( casenum__, starttime__, expected__, Pathfinding().getDirections( x, y ) );
      }
      case 4: {
         int x                     = 0;
         int y                     = 0;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, Pathfinding().getDirections( x, y ) );
      }

      // custom cases

/*
      case 5: {
         int x                     = ;
         int y                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, Pathfinding().getDirections( x, y ) );
      }
*/
/*
      case 6: {
         int x                     = ;
         int y                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, Pathfinding().getDirections( x, y ) );
      }
*/
/*
      case 7: {
         int x                     = ;
         int y                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, Pathfinding().getDirections( x, y ) );
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
