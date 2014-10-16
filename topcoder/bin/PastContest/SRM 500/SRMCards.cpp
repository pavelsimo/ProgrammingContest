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
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define pb push_back


class SRMCards {
public:
   int maxTurns( vector <int> c ) {
      int N = sz(c);
      int res = N;
      sort(c.begin(),c.end());
      for(int i = 0; i < N-1; ++i) {
         if(c[i]==c[i+1]-1) {
            res--;
            ++i;
         }
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
         int cards[]               = {498, 499};
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, SRMCards().maxTurns( vector <int>( cards, cards + ( sizeof cards / sizeof(int) ) ) ) );
      }
      case 1: {
         int cards[]               = {491, 492, 495, 497, 498, 499};
         int expected__            = 4;

         return verify_case( casenum__, starttime__, expected__, SRMCards().maxTurns( vector <int>( cards, cards + ( sizeof cards / sizeof(int) ) ) ) );
      }
      case 2: {
         int cards[]               = {100, 200, 300, 400};
         int expected__            = 4;

         return verify_case( casenum__, starttime__, expected__, SRMCards().maxTurns( vector <int>( cards, cards + ( sizeof cards / sizeof(int) ) ) ) );
      }
      case 3: {
         int cards[]               = {11, 12, 102, 13, 100, 101, 99, 9, 8, 1};
         int expected__            = 6;

         return verify_case( casenum__, starttime__, expected__, SRMCards().maxTurns( vector <int>( cards, cards + ( sizeof cards / sizeof(int) ) ) ) );
      }
      case 4: {
         int cards[]               = {118, 321, 322, 119, 120, 320};
         int expected__            = 4;

         return verify_case( casenum__, starttime__, expected__, SRMCards().maxTurns( vector <int>( cards, cards + ( sizeof cards / sizeof(int) ) ) ) );
      }
      case 5: {
         int cards[]               = {10, 11, 12, 13, 14, 1, 2, 3, 4, 5, 6, 7, 8, 9};
         int expected__            = 7;

         return verify_case( casenum__, starttime__, expected__, SRMCards().maxTurns( vector <int>( cards, cards + ( sizeof cards / sizeof(int) ) ) ) );
      }

      // custom cases

/*
      case 6: {
         int cards[]               = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, SRMCards().maxTurns( vector <int>( cards, cards + ( sizeof cards / sizeof(int) ) ) ) );
      }
*/
/*
      case 7: {
         int cards[]               = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, SRMCards().maxTurns( vector <int>( cards, cards + ( sizeof cards / sizeof(int) ) ) ) );
      }
*/
/*
      case 8: {
         int cards[]               = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, SRMCards().maxTurns( vector <int>( cards, cards + ( sizeof cards / sizeof(int) ) ) ) );
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
