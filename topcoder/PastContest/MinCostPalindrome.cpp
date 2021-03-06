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


class MinCostPalindrome {
public:
   int getMinimum( string s, int oCost, int xCost ) {
      int res = 0;
      int lo = 0;
      int hi = sz(s) - 1;
      while(lo < hi) {
         if(s[lo]=='?' && s[hi] == '?')
            res+=2*min(oCost,xCost);
         else if(s[lo]=='?')
            res+=(s[hi]=='x')?xCost:oCost;
         else if(s[hi]=='?')
            res+=(s[lo]=='x')?xCost:oCost;
         else if(s[lo] != s[hi]) 
            return -1;
         lo++;
         hi--;
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
         string s                  = "oxo?xox?";
         int oCost                 = 3;
         int xCost                 = 5;
         int expected__            = 8;

         return verify_case( casenum__, starttime__, expected__, MinCostPalindrome().getMinimum( s, oCost, xCost ) );
      }
      case 1: {
         string s                  = "x??x";
         int oCost                 = 9;
         int xCost                 = 4;
         int expected__            = 8;

         return verify_case( casenum__, starttime__, expected__, MinCostPalindrome().getMinimum( s, oCost, xCost ) );
      }
      case 2: {
         string s                  = "ooooxxxx";
         int oCost                 = 12;
         int xCost                 = 34;
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, MinCostPalindrome().getMinimum( s, oCost, xCost ) );
      }
      case 3: {
         string s                  = "oxoxooxxxxooxoxo";
         int oCost                 = 7;
         int xCost                 = 4;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, MinCostPalindrome().getMinimum( s, oCost, xCost ) );
      }
      case 4: {
         string s                  = "?o";
         int oCost                 = 6;
         int xCost                 = 2;
         int expected__            = 6;

         return verify_case( casenum__, starttime__, expected__, MinCostPalindrome().getMinimum( s, oCost, xCost ) );
      }
      case 5: {
         string s                  = "????????????????????";
         int oCost                 = 50;
         int xCost                 = 49;
         int expected__            = 980;

         return verify_case( casenum__, starttime__, expected__, MinCostPalindrome().getMinimum( s, oCost, xCost ) );
      }
      case 6: {
         string s                  = "o??oxxo?xoox?ox??x??" ;
         int oCost                 = 3;
         int xCost                 = 10;
         int expected__            = 38;

         return verify_case( casenum__, starttime__, expected__, MinCostPalindrome().getMinimum( s, oCost, xCost ) );
      }

      // custom cases

/*
      case 7: {
         string s                  = ;
         int oCost                 = ;
         int xCost                 = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, MinCostPalindrome().getMinimum( s, oCost, xCost ) );
      }
*/
/*
      case 8: {
         string s                  = ;
         int oCost                 = ;
         int xCost                 = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, MinCostPalindrome().getMinimum( s, oCost, xCost ) );
      }
*/
/*
      case 9: {
         string s                  = ;
         int oCost                 = ;
         int xCost                 = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, MinCostPalindrome().getMinimum( s, oCost, xCost ) );
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
