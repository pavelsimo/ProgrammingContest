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

template<typename INT>
INT gcd(INT a, INT b) {
   if (a < 0) a = -a;
   if (b < 0) b = -b;
   if (a < b) swap(a, b);
   while (b > 0) {
      INT t = b;
      b = a % b;
      a = t;
   }
   return a > 0 ? a : 1;
}

// Recursive GCD
template<typename INT>
INT rgcd(INT a, INT b) {
   return b == 0 ? a : rgcd(b, a % b);
}

// LCM
template<typename INT>
INT lcm(INT a, INT b) {
// a*b/gcd(a,b) overflows !!!
   return a / gcd(a,b) * b;
}



class KingXNewCurrency {
public:
   
   vector<int> fact(int N) {
      vector<int> res;
      for(int i = 2; i * i <= N; ++i) {
         while(N % i == 0) {
            res.push_back(i);
            N/=i;
         }
      }
      if(N > 1) res.push_back(N);
      return res;
   }

   int howMany( int A, int B, int X ) {
      int gcd_ax = gcd(A, X);
      int gcd_bx = gcd(B, X);
      if(gcd_ax == 1 && gcd_bx == 1) return 1;
      if(gcd_ax > 1 && gcd_bx > 1) return -1;
      
      
      vector<int> PA = fact(A);
      vector<int> PB = fact(B);
      vector<int> PX = fact(X);
      cout << "A: ";
      for(int i = 0; i < sz(PA); ++i)
         cout << PA[i] << ' ';
      cout << endl;
      cout << "B: ";
      for(int i = 0; i < sz(PB); ++i)
         cout << PB[i] << ' ';
      cout << endl;
      cout << "X: ";
      for(int i = 0; i < sz(PX); ++i)
         cout << PX[i] << ' ';
      cout << endl << endl;         
         
      //int lcm_ax = lcm(A, X);
      //int lcm_bx = lcm(B, X);
      
      if(gcd_ax == 1) {
         
      } else {
         
         
      }
      DEBUG(A);
      DEBUG(B);
      DEBUG(X);
      DEBUG(gcd(A, B));
      DEBUG(lcm(A, B));
      DEBUG(gcd(A, X));
      DEBUG(gcd(B, X));
      DEBUG(lcm(A,X));
      DEBUG(lcm(B, X));
      return 0;
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
         int A                     = 5;
         int B                     = 8;
         int X                     = 5;
         int expected__            = 5;

         return verify_case( casenum__, starttime__, expected__, KingXNewCurrency().howMany( A, B, X ) );
      }
      case 1: {
         int A                     = 8;
         int B                     = 4;
         int X                     = 2;
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, KingXNewCurrency().howMany( A, B, X ) );
      }
      case 2: {
         int A                     = 7;
         int B                     = 4;
         int X                     = 13;
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, KingXNewCurrency().howMany( A, B, X ) );
      }
      case 3: {
         int A                     = 47;
         int B                     = 74;
         int X                     = 44;
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, KingXNewCurrency().howMany( A, B, X ) );
      }
      case 4: {
         int A                     = 128;
         int B                     = 96;
         int X                     = 3;
         int expected__            = 65;

         return verify_case( casenum__, starttime__, expected__, KingXNewCurrency().howMany( A, B, X ) );
      }

      // custom cases

/*
      case 5: {
         int A                     = ;
         int B                     = ;
         int X                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, KingXNewCurrency().howMany( A, B, X ) );
      }
*/
/*
      case 6: {
         int A                     = ;
         int B                     = ;
         int X                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, KingXNewCurrency().howMany( A, B, X ) );
      }
*/
/*
      case 7: {
         int A                     = ;
         int B                     = ;
         int X                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, KingXNewCurrency().howMany( A, B, X ) );
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
