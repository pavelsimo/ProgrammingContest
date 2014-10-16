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

#define MOD 1000000009LL
typedef long long llong;

class YetAnotherIncredibleMachine {
public:
   int countWays( vector <int> platformMount, vector <int> platformLength, vector <int> balls ) {
      llong res = 1;
      int N = sz(platformMount);
      int M = sz(balls);
      sort(all(balls));
      for(int i = 0; i < N; ++i) {
         llong cnt = 0;
         for(int x = platformMount[i] - platformLength[i]; x <= platformMount[i]; ++x) {
            int j = lower_bound(all(balls),x) - balls.begin();
            if(j < M && balls[j] >= x && balls[j] <= x + platformLength[i])
               continue;
            cnt++;
         }
         res = (res * cnt) % MOD;
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
         int platformMount[]       = {7};
         int platformLength[]      = {10};
         int balls[]               = {3,4};
         int expected__            = 3;

         return verify_case( casenum__, starttime__, expected__, YetAnotherIncredibleMachine().countWays( vector <int>( platformMount, platformMount + ( sizeof platformMount / sizeof(int) ) ), vector <int>( platformLength, platformLength + ( sizeof platformLength / sizeof(int) ) ), vector <int>( balls, balls + ( sizeof balls / sizeof(int) ) ) ) );
      }
      case 1: {
         int platformMount[]       = {1,4};
         int platformLength[]      = {3,3};
         int balls[]               = {2,7};
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, YetAnotherIncredibleMachine().countWays( vector <int>( platformMount, platformMount + ( sizeof platformMount / sizeof(int) ) ), vector <int>( platformLength, platformLength + ( sizeof platformLength / sizeof(int) ) ), vector <int>( balls, balls + ( sizeof balls / sizeof(int) ) ) ) );
      }
      case 2: {
         int platformMount[]       = {4,4,4};
         int platformLength[]      = {10,9,8};
         int balls[]               = {1,100};
         int expected__            = 27;

         return verify_case( casenum__, starttime__, expected__, YetAnotherIncredibleMachine().countWays( vector <int>( platformMount, platformMount + ( sizeof platformMount / sizeof(int) ) ), vector <int>( platformLength, platformLength + ( sizeof platformLength / sizeof(int) ) ), vector <int>( balls, balls + ( sizeof balls / sizeof(int) ) ) ) );
      }
      case 3: {
         int platformMount[]       = {0};
         int platformLength[]      = {1};
         int balls[]               = {0};
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, YetAnotherIncredibleMachine().countWays( vector <int>( platformMount, platformMount + ( sizeof platformMount / sizeof(int) ) ), vector <int>( platformLength, platformLength + ( sizeof platformLength / sizeof(int) ) ), vector <int>( balls, balls + ( sizeof balls / sizeof(int) ) ) ) );
      }
      case 4: {
         int platformMount[]       = {100, -4215, 251};
         int platformLength[]      = {400, 10000, 2121};
         int balls[]               = {5000, 2270, 8512, 6122};
         int expected__            = 250379170;

         return verify_case( casenum__, starttime__, expected__, YetAnotherIncredibleMachine().countWays( vector <int>( platformMount, platformMount + ( sizeof platformMount / sizeof(int) ) ), vector <int>( platformLength, platformLength + ( sizeof platformLength / sizeof(int) ) ), vector <int>( balls, balls + ( sizeof balls / sizeof(int) ) ) ) );
      }

      // custom cases

/*
      case 5: {
         int platformMount[]       = ;
         int platformLength[]      = ;
         int balls[]               = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, YetAnotherIncredibleMachine().countWays( vector <int>( platformMount, platformMount + ( sizeof platformMount / sizeof(int) ) ), vector <int>( platformLength, platformLength + ( sizeof platformLength / sizeof(int) ) ), vector <int>( balls, balls + ( sizeof balls / sizeof(int) ) ) ) );
      }
*/
/*
      case 6: {
         int platformMount[]       = ;
         int platformLength[]      = ;
         int balls[]               = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, YetAnotherIncredibleMachine().countWays( vector <int>( platformMount, platformMount + ( sizeof platformMount / sizeof(int) ) ), vector <int>( platformLength, platformLength + ( sizeof platformLength / sizeof(int) ) ), vector <int>( balls, balls + ( sizeof balls / sizeof(int) ) ) ) );
      }
*/
/*
      case 7: {
         int platformMount[]       = ;
         int platformLength[]      = ;
         int balls[]               = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, YetAnotherIncredibleMachine().countWays( vector <int>( platformMount, platformMount + ( sizeof platformMount / sizeof(int) ) ), vector <int>( platformLength, platformLength + ( sizeof platformLength / sizeof(int) ) ), vector <int>( balls, balls + ( sizeof balls / sizeof(int) ) ) ) );
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
