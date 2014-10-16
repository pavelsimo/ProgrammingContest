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
#define pb push_back


class MathContest {
public:
   int countBlack( string ballSequence, int repetitions ) {
      int res = 0;
      string s = "";
      for(int i = 0; i < repetitions; ++i) 
         s+=ballSequence;
      int lo = 0;
      int hi = sz(s)-1;
      bool head = false;
      bool inverted = false;
      bool black = false;
      while(lo <= hi) {
         if(head) {
            black = (!inverted && s[hi]=='B') || (inverted && s[hi]=='W');
            --hi;
         } else {
            black = (!inverted && s[lo]=='B') || (inverted && s[lo]=='W');
            ++lo;
         } 
         if(black) {
            res++;
            inverted = !inverted;
         } else {
            head = !head;
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
         string ballSequence       = "BBWWB";
         int repetitions           = 1;
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, MathContest().countBlack( ballSequence, repetitions ) );
      }
      case 1: {
         string ballSequence       = "BBB";
         int repetitions           = 10;
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, MathContest().countBlack( ballSequence, repetitions ) );
      }
      case 2: {
         string ballSequence       = "BW";
         int repetitions           = 10;
         int expected__            = 20;

         return verify_case( casenum__, starttime__, expected__, MathContest().countBlack( ballSequence, repetitions ) );
      }
      case 3: {
         string ballSequence       = "WWWWWWWBWWWWWWWWWWWWWW";
         int repetitions           = 1;
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, MathContest().countBlack( ballSequence, repetitions ) );
      }

      // custom cases

/*
      case 4: {
         string ballSequence       = ;
         int repetitions           = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, MathContest().countBlack( ballSequence, repetitions ) );
      }
*/
/*
      case 5: {
         string ballSequence       = ;
         int repetitions           = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, MathContest().countBlack( ballSequence, repetitions ) );
      }
*/
/*
      case 6: {
         string ballSequence       = ;
         int repetitions           = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, MathContest().countBlack( ballSequence, repetitions ) );
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
