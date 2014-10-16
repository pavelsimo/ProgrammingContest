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


class EasyConversionMachine {
public:
   string isItPossible( string originalWord, string finalWord, int k ) {
      int cnt = 0;
      for(int i = 0; i < sz(originalWord); ++i)
         if(originalWord[i] != finalWord[i]) cnt++;
      if(cnt > k) return "IMPOSSIBLE";
      return (k - cnt) % 2 == 0 ? "POSSIBLE" : "IMPOSSIBLE";
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
   int verify_case( int casenum, long long starttime, const string &expected, const string &received ) {
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
         cerr << "    Expected: \"" << expected << "\"" << endl; 
         cerr << "    Received: \"" << received << "\"" << endl; 
         return 0;
      }
   }

   int run_test_case( int casenum__ ) {
      long long starttime__ = get_time();
      switch( casenum__ ) {
      case 0: {
         string originalWord       = "aababba";
         string finalWord          = "bbbbbbb";
         int k                     = 2;
         string expected__         = "IMPOSSIBLE";

         return verify_case( casenum__, starttime__, expected__, EasyConversionMachine().isItPossible( originalWord, finalWord, k ) );
      }
      case 1: {
         string originalWord       = "aabb";
         string finalWord          = "aabb";
         int k                     = 1;
         string expected__         = "IMPOSSIBLE";

         return verify_case( casenum__, starttime__, expected__, EasyConversionMachine().isItPossible( originalWord, finalWord, k ) );
      }
      case 2: {
         string originalWord       = "aaaaabaa";
         string finalWord          = "bbbbbabb";
         int k                     = 8;
         string expected__         = "POSSIBLE";

         return verify_case( casenum__, starttime__, expected__, EasyConversionMachine().isItPossible( originalWord, finalWord, k ) );
      }
      case 3: {
         string originalWord       = "aaa";
         string finalWord          = "bab";
         int k                     = 4;
         string expected__         = "POSSIBLE";

         return verify_case( casenum__, starttime__, expected__, EasyConversionMachine().isItPossible( originalWord, finalWord, k ) );
      }
      case 4: {
         string originalWord       = "aababbabaa";
         string finalWord          = "abbbbaabab";
         int k                     = 9;
         string expected__         = "IMPOSSIBLE";

         return verify_case( casenum__, starttime__, expected__, EasyConversionMachine().isItPossible( originalWord, finalWord, k ) );
      }

      // custom cases

/*
      case 5: {
         string originalWord       = ;
         string finalWord          = ;
         int k                     = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, EasyConversionMachine().isItPossible( originalWord, finalWord, k ) );
      }
*/
/*
      case 6: {
         string originalWord       = ;
         string finalWord          = ;
         int k                     = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, EasyConversionMachine().isItPossible( originalWord, finalWord, k ) );
      }
*/
/*
      case 7: {
         string originalWord       = ;
         string finalWord          = ;
         int k                     = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, EasyConversionMachine().isItPossible( originalWord, finalWord, k ) );
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
