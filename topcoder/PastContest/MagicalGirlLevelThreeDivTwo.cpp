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


class MagicalGirlLevelThreeDivTwo {
public:
   int theCount( vector <string> first, int n, long long lo, long long hi ) {

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
         string first[]            = {"101", "01"};
         int n                     = 4;
         long long lo              = 2LL;
         long long hi              = 5LL;
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelThreeDivTwo().theCount( vector <string>( first, first + ( sizeof first / sizeof(string) ) ), n, lo, hi ) );
      }
      case 1: {
         string first[]            = {"01", "10"};
         int n                     = 5;
         long long lo              = 4LL;
         long long hi              = 5LL;
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelThreeDivTwo().theCount( vector <string>( first, first + ( sizeof first / sizeof(string) ) ), n, lo, hi ) );
      }
      case 2: {
         string first[]            = {"1", "11", "111"};
         int n                     = 46;
         long long lo              = 10000LL;
         long long hi              = 11000LL;
         int expected__            = 1001;

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelThreeDivTwo().theCount( vector <string>( first, first + ( sizeof first / sizeof(string) ) ), n, lo, hi ) );
      }
      case 3: {
         string first[]            = {"0", "00", "000"};
         int n                     = 46;
         long long lo              = 10000LL;
         long long hi              = 11000LL;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelThreeDivTwo().theCount( vector <string>( first, first + ( sizeof first / sizeof(string) ) ), n, lo, hi ) );
      }
      case 4: {
         string first[]            = {"00110110101101001111101101001011010011111011010010"};
         int n                     = 100;
         long long lo              = 999999999999915LL;
         long long hi              = 1000000000000000LL;
         int expected__            = 50;

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelThreeDivTwo().theCount( vector <string>( first, first + ( sizeof first / sizeof(string) ) ), n, lo, hi ) );
      }
      case 5: {
         string first[]            = {"10000", "011011001011000001101000010100000111000110110",  "000001010001011000001101110", "100100000110100001010000",  "011011010", "01100000010101101110000011100011001000", "0001010", "010011000", "000101001", "00", "1"};
         int n                     = 91;
         long long lo              = 123456LL;
         long long hi              = 123654LL;
         int expected__            = 76;

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelThreeDivTwo().theCount( vector <string>( first, first + ( sizeof first / sizeof(string) ) ), n, lo, hi ) );
      }

      // custom cases

/*
      case 6: {
         string first[]            = ;
         int n                     = ;
         long long lo              = LL;
         long long hi              = LL;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelThreeDivTwo().theCount( vector <string>( first, first + ( sizeof first / sizeof(string) ) ), n, lo, hi ) );
      }
*/
/*
      case 7: {
         string first[]            = ;
         int n                     = ;
         long long lo              = LL;
         long long hi              = LL;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelThreeDivTwo().theCount( vector <string>( first, first + ( sizeof first / sizeof(string) ) ), n, lo, hi ) );
      }
*/
/*
      case 8: {
         string first[]            = ;
         int n                     = ;
         long long lo              = LL;
         long long hi              = LL;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelThreeDivTwo().theCount( vector <string>( first, first + ( sizeof first / sizeof(string) ) ), n, lo, hi ) );
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
