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


class EllysFractions {
public:

   long long getCount( int N ) {
      llong res = 0LL;
      set<int> PF;
      for(int i = 2; i <= N; ++i) {
        int X = i;
        for(int j = 2; j * j <= X; ++j) {
          while(X % j == 0) {
            PF.insert(j);
            X/=j;
          }
        }
        if(X > 1) PF.insert(X);
        res+=1LL << (PF.size() - 1LL);
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
         int N                     = 1;
         long long expected__      = 0LL;

         return verify_case( casenum__, starttime__, expected__, EllysFractions().getCount( N ) );
      }
      case 1: {
         int N                     = 2;
         long long expected__      = 1LL;

         return verify_case( casenum__, starttime__, expected__, EllysFractions().getCount( N ) );
      }
      case 2: {
         int N                     = 3;
         long long expected__      = 3LL;

         return verify_case( casenum__, starttime__, expected__, EllysFractions().getCount( N ) );
      }
      case 3: {
         int N                     = 5;
         long long expected__      = 9LL;

         return verify_case( casenum__, starttime__, expected__, EllysFractions().getCount( N ) );
      }
      case 4: {
         int N                     = 100;
         long long expected__      = 177431885LL;

         return verify_case( casenum__, starttime__, expected__, EllysFractions().getCount( N ) );
      }

      // custom cases

/*
      case 5: {
         int N                     = ;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, EllysFractions().getCount( N ) );
      }
*/
/*
      case 6: {
         int N                     = ;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, EllysFractions().getCount( N ) );
      }
*/
/*
      case 7: {
         int N                     = ;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, EllysFractions().getCount( N ) );
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
