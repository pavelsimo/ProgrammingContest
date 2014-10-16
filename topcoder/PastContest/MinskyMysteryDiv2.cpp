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


class MinskyMysteryDiv2 {
public:
   long long computeAnswer( long long N ) {
      long long b[5];
      memset(b,0,sizeof(b));
      b[0] = N;
      b[1]++;
      if(N == 0) 
         return -1;
      while(true) {
         b[1]++;
         b[4]=0;
         while(b[0] > 0) {
            int x = min(b[0],b[1]);
            b[0]-=x; b[1]-=x;
            b[2]+=x; b[3]+=x;
            b[4]++;
            if(b[0] <= 0 && b[1] <= 0) {
               b[4]+=b[3];
               return b[4];
            }
            b[1]+=b[3];
            b[3]=0;
         }
         b[0]+=b[2];
         b[2]=0;
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
   int verify_case( int casenum, long long starttime, const long long &expected, const long long &received ) {
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
         long long N               = 2L;
         long long expected__      = 3LL;

         return verify_case( casenum__, starttime__, expected__, MinskyMysteryDiv2().computeAnswer( N ) );
      }
      case 1: {
         long long N               = 3LL;
         long long expected__      = 4LL;

         return verify_case( casenum__, starttime__, expected__, MinskyMysteryDiv2().computeAnswer( N ) );
      }
      case 2: {
         long long N               = 4LL;
         long long expected__      = 4LL;

         return verify_case( casenum__, starttime__, expected__, MinskyMysteryDiv2().computeAnswer( N ) );
      }
      case 3: {
         long long N               = 15LL;
         long long expected__      = 8LL;

         return verify_case( casenum__, starttime__, expected__, MinskyMysteryDiv2().computeAnswer( N ) );
      }
      case 4: {
         long long N               = 24LL;
         long long expected__      = 14LL;

         return verify_case( casenum__, starttime__, expected__, MinskyMysteryDiv2().computeAnswer( N ) );
      }

      // custom cases


      case 5: {
         long long N               = 100000000000LL;
         long long expected__      = 1LL;

         return verify_case( casenum__, starttime__, expected__, MinskyMysteryDiv2().computeAnswer( N ) );
      }

/*
      case 6: {
         long long N               = LL;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, MinskyMysteryDiv2().computeAnswer( N ) );
      }
*/
/*
      case 7: {
         long long N               = LL;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, MinskyMysteryDiv2().computeAnswer( N ) );
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
