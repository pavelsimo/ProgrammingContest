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

bool seen[5000002];
vector<int> a;
typedef long long llong;

class SumsOfPerfectPowers {
public:
   int howMany( int lowerBound, int upperBound ) {
      int res = 0;
      memset(seen,false,sizeof(seen));
      a.clear();
      a.push_back(0); a.push_back(1);
      seen[0] = seen[1] = true;
      for(int i = 2; i < 2500; ++i) {
         llong x = i;
         while(x <= 5000000) {
            x*=i;
            if(x <= 5000000 && !seen[x]) {
               seen[x] = true;
               a.push_back(x);
            }
         }
      }
      for(int i = 0; i < sz(a); ++i) {
         for(int j = 0; j < sz(a); ++j) {
            if(a[i] + a[j] > 5000000) continue;
            seen[a[i] + a[j]] = true;
         }   
      }     
      for(int i = lowerBound; i <= upperBound; ++i)
         if(seen[i]) res++;
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
         int lowerBound            = 0;
         int upperBound            = 1;
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, SumsOfPerfectPowers().howMany( lowerBound, upperBound ) );
      }
      case 1: {
         int lowerBound            = 5;
         int upperBound            = 6;
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, SumsOfPerfectPowers().howMany( lowerBound, upperBound ) );
      }
      case 2: {
         int lowerBound            = 25;
         int upperBound            = 30;
         int expected__            = 5;

         return verify_case( casenum__, starttime__, expected__, SumsOfPerfectPowers().howMany( lowerBound, upperBound ) );
      }
      case 3: {
         int lowerBound            = 103;
         int upperBound            = 103;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, SumsOfPerfectPowers().howMany( lowerBound, upperBound ) );
      }
      case 4: {
         int lowerBound            = 1;
         int upperBound            = 100000;
         int expected__            = 33604;

         return verify_case( casenum__, starttime__, expected__, SumsOfPerfectPowers().howMany( lowerBound, upperBound ) );
      }

      // custom cases

/*
      case 5: {
         int lowerBound            = ;
         int upperBound            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, SumsOfPerfectPowers().howMany( lowerBound, upperBound ) );
      }
*/
/*
      case 6: {
         int lowerBound            = ;
         int upperBound            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, SumsOfPerfectPowers().howMany( lowerBound, upperBound ) );
      }
*/
/*
      case 7: {
         int lowerBound            = ;
         int upperBound            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, SumsOfPerfectPowers().howMany( lowerBound, upperBound ) );
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
