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


typedef long long llong;

string S;
int N, memo[52][52][6];

class CuttingBitString {
public:

   
   int go(int n, int bit, int mod, llong x) {
      if(n == N) 
         return x > 0LL && (x % 5LL) == 0LL ? 0: 2 * N;
      int &res = memo[n][bit][mod];
      if(res != -1) return res;
      res = 2 * N;
      llong nx = x + ((S[n] - '0') ? 1LL << bit: 0);
      if(x % 5LL == 0 && x == 1) {
         res = min(res, go(n + 1, bit + 1, nx % 5LL, nx));
      }
      
      return res;
   }

   int getmin( string s ) {
      int res = 0;
      reverse(all(s));
      S = s;
      N = sz(s);
      memset(memo, -1, sizeof(memo));
      res = go(0, 0, 0, 0LL);
      
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
         string S                  = "101101101";
         int expected__            = 3;

         return verify_case( casenum__, starttime__, expected__, CuttingBitString().getmin( S ) );
      }
      case 1: {
         string S                  = "1111101";
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, CuttingBitString().getmin( S ) );
      }
      case 2: {
         string S                  = "00000";
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, CuttingBitString().getmin( S ) );
      }
      case 3: {
         string S                  = "110011011";
         int expected__            = 3;

         return verify_case( casenum__, starttime__, expected__, CuttingBitString().getmin( S ) );
      }
      case 4: {
         string S                  = "1000101011";
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, CuttingBitString().getmin( S ) );
      }
      case 5: {
         string S                  = "111011100110101100101110111";
         int expected__            = 5;

         return verify_case( casenum__, starttime__, expected__, CuttingBitString().getmin( S ) );
      }

      // custom cases

/*
      case 6: {
         string S                  = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, CuttingBitString().getmin( S ) );
      }
*/
/*
      case 7: {
         string S                  = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, CuttingBitString().getmin( S ) );
      }
*/
/*
      case 8: {
         string S                  = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, CuttingBitString().getmin( S ) );
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
