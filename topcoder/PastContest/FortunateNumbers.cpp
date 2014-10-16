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

bool seen[100000];

class FortunateNumbers {
public:
   bool isFortunate(int n) {
      int x = n;
      while(x > 0) {
         int d = x%10;
         if(d == 5 || d == 8) {
            x/=10;
            continue;
         }
         return false;
      }
      return true;
   }

   int getFortunate( vector <int> a, vector <int> b, vector <int> c ) {
      int res = 0;
      memset(seen,false,sizeof(seen));
      for(int i = 0; i < sz(a); ++i) {
         for(int j = 0; j < sz(b); ++j) {
            for(int k = 0; k < sz(c); ++k) {
               int nxt = a[i] + b[j] + c[k];
               if(isFortunate(nxt) && !seen[nxt]) {
                  res++;
                  seen[nxt] = true;
               }
            }
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
         int a[]                   = { 1, 10, 100 };
         int b[]                   = { 3, 53 };
         int c[]                   = { 4, 54 };
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, FortunateNumbers().getFortunate( vector <int>( a, a + ( sizeof a / sizeof(int) ) ), vector <int>( b, b + ( sizeof b / sizeof(int) ) ), vector <int>( c, c + ( sizeof c / sizeof(int) ) ) ) );
      }
      case 1: {
         int a[]                   = { 47 };
         int b[]                   = { 500 };
         int c[]                   = { 33 };
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, FortunateNumbers().getFortunate( vector <int>( a, a + ( sizeof a / sizeof(int) ) ), vector <int>( b, b + ( sizeof b / sizeof(int) ) ), vector <int>( c, c + ( sizeof c / sizeof(int) ) ) ) );
      }
      case 2: {
         int a[]                   = { 100, 1, 10, 100, 1, 1 };
         int b[]                   = { 3, 53, 53, 53, 53, 53, 53 };
         int c[]                   = { 4, 54, 4, 54, 4, 54 };
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, FortunateNumbers().getFortunate( vector <int>( a, a + ( sizeof a / sizeof(int) ) ), vector <int>( b, b + ( sizeof b / sizeof(int) ) ), vector <int>( c, c + ( sizeof c / sizeof(int) ) ) ) );
      }
      case 3: {
         int a[]                   = { 500, 800 };
         int b[]                   = { 50, 80 };
         int c[]                   = { 5, 8 };
         int expected__            = 8;

         return verify_case( casenum__, starttime__, expected__, FortunateNumbers().getFortunate( vector <int>( a, a + ( sizeof a / sizeof(int) ) ), vector <int>( b, b + ( sizeof b / sizeof(int) ) ), vector <int>( c, c + ( sizeof c / sizeof(int) ) ) ) );
      }
      case 4: {
         int a[]                   = { 30000, 26264 };
         int b[]                   = { 30000, 29294 };
         int c[]                   = { 30000, 29594 };
         int expected__            = 3;

         return verify_case( casenum__, starttime__, expected__, FortunateNumbers().getFortunate( vector <int>( a, a + ( sizeof a / sizeof(int) ) ), vector <int>( b, b + ( sizeof b / sizeof(int) ) ), vector <int>( c, c + ( sizeof c / sizeof(int) ) ) ) );
      }

      // custom cases

/*
      case 5: {
         int a[]                   = ;
         int b[]                   = ;
         int c[]                   = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, FortunateNumbers().getFortunate( vector <int>( a, a + ( sizeof a / sizeof(int) ) ), vector <int>( b, b + ( sizeof b / sizeof(int) ) ), vector <int>( c, c + ( sizeof c / sizeof(int) ) ) ) );
      }
*/
/*
      case 6: {
         int a[]                   = ;
         int b[]                   = ;
         int c[]                   = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, FortunateNumbers().getFortunate( vector <int>( a, a + ( sizeof a / sizeof(int) ) ), vector <int>( b, b + ( sizeof b / sizeof(int) ) ), vector <int>( c, c + ( sizeof c / sizeof(int) ) ) ) );
      }
*/
/*
      case 7: {
         int a[]                   = ;
         int b[]                   = ;
         int c[]                   = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, FortunateNumbers().getFortunate( vector <int>( a, a + ( sizeof a / sizeof(int) ) ), vector <int>( b, b + ( sizeof b / sizeof(int) ) ), vector <int>( c, c + ( sizeof c / sizeof(int) ) ) ) );
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