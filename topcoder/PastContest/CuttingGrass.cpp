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


class CuttingGrass {
public:
   int theMin( vector <int> init, vector <int> grow, int H ) {

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
         int init[]                = {5, 8, 58};
         int grow[]                = {2, 1, 1};
         int H                     = 16;
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, CuttingGrass().theMin( vector <int>( init, init + ( sizeof init / sizeof(int) ) ), vector <int>( grow, grow + ( sizeof grow / sizeof(int) ) ), H ) );
      }
      case 1: {
         int init[]                = {5, 8};
         int grow[]                = {2, 1};
         int H                     = 58;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, CuttingGrass().theMin( vector <int>( init, init + ( sizeof init / sizeof(int) ) ), vector <int>( grow, grow + ( sizeof grow / sizeof(int) ) ), H ) );
      }
      case 2: {
         int init[]                = {5, 8};
         int grow[]                = {2, 1};
         int H                     = 0;
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, CuttingGrass().theMin( vector <int>( init, init + ( sizeof init / sizeof(int) ) ), vector <int>( grow, grow + ( sizeof grow / sizeof(int) ) ), H ) );
      }
      case 3: {
         int init[]                = {5, 1, 6, 5, 8, 4, 7};
         int grow[]                = {2, 1, 1, 1, 4, 3, 2};
         int H                     = 33;
         int expected__            = 5;

         return verify_case( casenum__, starttime__, expected__, CuttingGrass().theMin( vector <int>( init, init + ( sizeof init / sizeof(int) ) ), vector <int>( grow, grow + ( sizeof grow / sizeof(int) ) ), H ) );
      }
      case 4: {
         int init[]                = {49, 13, 62, 95, 69, 75, 62, 96, 97, 22, 69, 69, 52};
         int grow[]                = {7, 2, 4, 3, 6, 5, 7, 6, 5, 4, 7, 7, 4};
         int H                     = 517;
         int expected__            = 8;

         return verify_case( casenum__, starttime__, expected__, CuttingGrass().theMin( vector <int>( init, init + ( sizeof init / sizeof(int) ) ), vector <int>( grow, grow + ( sizeof grow / sizeof(int) ) ), H ) );
      }
      case 5: {
         int init[]                = {1231, 1536, 1519, 1940, 1539, 1385, 1599, 1613, 1394, 1803,  1763, 1706, 1863, 1452, 1818, 1914, 1386, 1954, 1496, 1722,  1616, 1862, 1755, 1215, 1233, 1078, 1448, 1241, 1732, 1561,  1633, 1307, 1844, 1911, 1371, 1338, 1989, 1789, 1656, 1413,  1929, 1182, 1815, 1474, 1540, 1797, 1586, 1427, 1996, 1202};
         int grow[]                = {86, 55, 2, 86, 96, 71, 81, 53, 79, 22,  23, 8, 69, 32, 35, 39, 30, 18, 92, 64,  88, 1, 48, 81, 91, 75, 44, 77, 3, 33,  9, 52, 56, 4, 19, 73, 52, 18, 8, 77,  91, 59, 50, 62, 42, 87, 89, 24, 71, 67};
         int H                     = 63601;
         int expected__            = 36;

         return verify_case( casenum__, starttime__, expected__, CuttingGrass().theMin( vector <int>( init, init + ( sizeof init / sizeof(int) ) ), vector <int>( grow, grow + ( sizeof grow / sizeof(int) ) ), H ) );
      }

      // custom cases

/*
      case 6: {
         int init[]                = ;
         int grow[]                = ;
         int H                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, CuttingGrass().theMin( vector <int>( init, init + ( sizeof init / sizeof(int) ) ), vector <int>( grow, grow + ( sizeof grow / sizeof(int) ) ), H ) );
      }
*/
/*
      case 7: {
         int init[]                = ;
         int grow[]                = ;
         int H                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, CuttingGrass().theMin( vector <int>( init, init + ( sizeof init / sizeof(int) ) ), vector <int>( grow, grow + ( sizeof grow / sizeof(int) ) ), H ) );
      }
*/
/*
      case 8: {
         int init[]                = ;
         int grow[]                = ;
         int H                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, CuttingGrass().theMin( vector <int>( init, init + ( sizeof init / sizeof(int) ) ), vector <int>( grow, grow + ( sizeof grow / sizeof(int) ) ), H ) );
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
