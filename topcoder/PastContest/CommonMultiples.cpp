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

typedef long long llong;

template<typename INT>
INT gcd(INT a, INT b) {
   if (a < 0) a = -a;
   if (b < 0) b = -b;
   if (a < b) swap(a, b);
   while (b > 0) {
      INT t = b;
      b = a % b;
      a = t;
   }
   return a > 0 ? a : 1;
}

template<typename INT>
INT lcm(INT a, INT b) {
   return a / gcd(a,b) * b;
}

class CommonMultiples {
public:
   int countCommMult( vector <int> a, int lower, int upper ) {
      llong mult = a[0];
      for(int i = 1; i < sz(a); ++i)
         mult = lcm(mult,llong(a[i]));
      return upper/mult - (lower-1)/mult;
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
         int a[]                   = {1,2,3};
         int lower                 = 5;
         int upper                 = 15;
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, CommonMultiples().countCommMult( vector <int>( a, a + ( sizeof a / sizeof(int) ) ), lower, upper ) );
      }
      case 1: {
         int a[]                   = {1,2,4,8,16,32,64};
         int lower                 = 128;
         int upper                 = 128;
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, CommonMultiples().countCommMult( vector <int>( a, a + ( sizeof a / sizeof(int) ) ), lower, upper ) );
      }
      case 2: {
         int a[]                   = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,49};
         int lower                 = 1;
         int upper                 = 2000000000;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, CommonMultiples().countCommMult( vector <int>( a, a + ( sizeof a / sizeof(int) ) ), lower, upper ) );
      }
      case 3: {
         int a[]                   = {1,1,1};
         int lower                 = 1;
         int upper                 = 2000000000;
         int expected__            = 2000000000;

         return verify_case( casenum__, starttime__, expected__, CommonMultiples().countCommMult( vector <int>( a, a + ( sizeof a / sizeof(int) ) ), lower, upper ) );
      }

      // custom cases

/*
      case 4: {
         int a[]                   = ;
         int lower                 = ;
         int upper                 = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, CommonMultiples().countCommMult( vector <int>( a, a + ( sizeof a / sizeof(int) ) ), lower, upper ) );
      }
*/
/*
      case 5: {
         int a[]                   = ;
         int lower                 = ;
         int upper                 = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, CommonMultiples().countCommMult( vector <int>( a, a + ( sizeof a / sizeof(int) ) ), lower, upper ) );
      }
*/
/*
      case 6: {
         int a[]                   = ;
         int lower                 = ;
         int upper                 = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, CommonMultiples().countCommMult( vector <int>( a, a + ( sizeof a / sizeof(int) ) ), lower, upper ) );
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
