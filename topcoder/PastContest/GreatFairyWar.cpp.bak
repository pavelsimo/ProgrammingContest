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


class GreatFairyWar {
public:
   int minHP( vector <int> dps, vector <int> hp ) {
      int res = 0, sum = 0;
      for(int i = 0; i < sz(dps); ++i)
         sum+=dps[i];
      for(int i = 0; i < sz(dps); ++i) {
         res += hp[i] * sum;
         sum -= dps[i];
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
         int dps[]                 = {1,2};
         int hp[]                  = {3,4};
         int expected__            = 17;

         return verify_case( casenum__, starttime__, expected__, GreatFairyWar().minHP( vector <int>( dps, dps + ( sizeof dps / sizeof(int) ) ), vector <int>( hp, hp + ( sizeof hp / sizeof(int) ) ) ) );
      }
      case 1: {
         int dps[]                 = {1,1,1,1,1,1,1,1,1,1};
         int hp[]                  = {1,1,1,1,1,1,1,1,1,1};
         int expected__            = 55;

         return verify_case( casenum__, starttime__, expected__, GreatFairyWar().minHP( vector <int>( dps, dps + ( sizeof dps / sizeof(int) ) ), vector <int>( hp, hp + ( sizeof hp / sizeof(int) ) ) ) );
      }
      case 2: {
         int dps[]                 = {20,12,10,10,23,10};
         int hp[]                  = {5,7,7,5,7,7};
         int expected__            = 1767;

         return verify_case( casenum__, starttime__, expected__, GreatFairyWar().minHP( vector <int>( dps, dps + ( sizeof dps / sizeof(int) ) ), vector <int>( hp, hp + ( sizeof hp / sizeof(int) ) ) ) );
      }
      case 3: {
         int dps[]                 = {5,7,7,5,7,7};
         int hp[]                  = {20,12,10,10,23,10};
         int expected__            = 1998;

         return verify_case( casenum__, starttime__, expected__, GreatFairyWar().minHP( vector <int>( dps, dps + ( sizeof dps / sizeof(int) ) ), vector <int>( hp, hp + ( sizeof hp / sizeof(int) ) ) ) );
      }
      case 4: {
         int dps[]                 = {30,2,7,4,7,8,21,14,19,12};
         int hp[]                  = {2,27,18,19,14,8,25,13,21,30};
         int expected__            = 11029;

         return verify_case( casenum__, starttime__, expected__, GreatFairyWar().minHP( vector <int>( dps, dps + ( sizeof dps / sizeof(int) ) ), vector <int>( hp, hp + ( sizeof hp / sizeof(int) ) ) ) );
      }
      case 5: {
         int dps[]                 = {1};
         int hp[]                  = {1};
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, GreatFairyWar().minHP( vector <int>( dps, dps + ( sizeof dps / sizeof(int) ) ), vector <int>( hp, hp + ( sizeof hp / sizeof(int) ) ) ) );
      }

      // custom cases

/*
      case 6: {
         int dps[]                 = ;
         int hp[]                  = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, GreatFairyWar().minHP( vector <int>( dps, dps + ( sizeof dps / sizeof(int) ) ), vector <int>( hp, hp + ( sizeof hp / sizeof(int) ) ) ) );
      }
*/
/*
      case 7: {
         int dps[]                 = ;
         int hp[]                  = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, GreatFairyWar().minHP( vector <int>( dps, dps + ( sizeof dps / sizeof(int) ) ), vector <int>( hp, hp + ( sizeof hp / sizeof(int) ) ) ) );
      }
*/
/*
      case 8: {
         int dps[]                 = ;
         int hp[]                  = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, GreatFairyWar().minHP( vector <int>( dps, dps + ( sizeof dps / sizeof(int) ) ), vector <int>( hp, hp + ( sizeof hp / sizeof(int) ) ) ) );
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
