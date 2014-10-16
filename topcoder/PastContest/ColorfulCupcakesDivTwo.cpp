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

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }


const int MOD = 1000000007;
const int A_lbl = 1, B_lbl = 2, C_lbl = 3;
int memo[4][4][55][55][55];

int N;

class ColorfulCupcakesDivTwo {
public:

   int go(int first, int prev, int A, int B, int C) {
      if(A == 0 && B == 0 && C == 0)
         return prev == first ? 0: 1;
      int res = 0;
      if(memo[first][prev][A][B][C] >= 0) return memo[first][prev][A][B][C];
      if(A >= 1 && prev != A_lbl) res = (res +  go(first, A_lbl, A - 1, B, C)) % MOD;
      if(B >= 1 && prev != B_lbl) res = (res +  go(first, B_lbl, A, B - 1, C)) % MOD;
      if(C >= 1 && prev != C_lbl) res = (res +  go(first, C_lbl, A, B, C - 1)) % MOD;
      return memo[first][prev][A][B][C] = res % MOD;
   }
   
   int countArrangements( string cupcakes ) {
      int cntA, cntB, cntC;
      int res = 0;
      N = sz(cupcakes);
      cntA = cntB = cntC = 0;
      for(int i = 0; i < sz(cupcakes); ++i) {
         if(cupcakes[i] == 'A') cntA++;
         else if(cupcakes[i] == 'B') cntB++;
         else cntC++;
      }
      if(cntA >= 1) {
         memset(memo, -1, sizeof(memo));
         res = (res + go(A_lbl, A_lbl, cntA - 1, cntB, cntC)) % MOD;
      }
      if(cntB >= 1) {
         memset(memo, -1, sizeof(memo));
         res = (res + go(B_lbl, B_lbl, cntA, cntB - 1, cntC)) % MOD;
      }
      if(cntC >= 1) {
         memset(memo, -1, sizeof(memo));
         res = (res + go(C_lbl, C_lbl, cntA, cntB, cntC - 1)) % MOD;
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
         string cupcakes           = "ABAB";
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, ColorfulCupcakesDivTwo().countArrangements( cupcakes ) );
      }
      case 1: {
         string cupcakes           = "ABABA";
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, ColorfulCupcakesDivTwo().countArrangements( cupcakes ) );
      }
      case 2: {
         string cupcakes           = "ABC";
         int expected__            = 6;

         return verify_case( casenum__, starttime__, expected__, ColorfulCupcakesDivTwo().countArrangements( cupcakes ) );
      }
      case 3: {
         string cupcakes           = "ABABABABABABABABABABABABABABABABABABABABABABABABAB";
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, ColorfulCupcakesDivTwo().countArrangements( cupcakes ) );
      }
      case 4: {
         string cupcakes           = "BCBABBACBABABCCCCCAABBAACBBBBCBCAAA";
         int expected__            = 741380640;

         return verify_case( casenum__, starttime__, expected__, ColorfulCupcakesDivTwo().countArrangements( cupcakes ) );
      }

      // custom cases

/*
      case 5: {
         string cupcakes           = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, ColorfulCupcakesDivTwo().countArrangements( cupcakes ) );
      }
*/
/*
      case 6: {
         string cupcakes           = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, ColorfulCupcakesDivTwo().countArrangements( cupcakes ) );
      }
*/
/*
      case 7: {
         string cupcakes           = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, ColorfulCupcakesDivTwo().countArrangements( cupcakes ) );
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
