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



class TheBrickTowerEasyDivTwo {
public:

   int find(int RC, int RH, int BC, int BH) {
      int rc, bc, h;
      set<int> S;
      S.insert(0);
      for(int t = 0; t < 2; ++t) {
         int x = t;
         h = rc = bc = 0;
         while(rc < RC && bc < BC) {
            if(x) ++rc, h+=RH;
            else ++bc, h+=BH;
            S.insert(h);
            x^=1;
         }         
      }
      return S.size();
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
         int redCount              = 1;
         int redHeight             = 2;
         int blueCount             = 3;
         int blueHeight            = 4;
         int expected__            = 4;

         return verify_case( casenum__, starttime__, expected__, TheBrickTowerEasyDivTwo().find( redCount, redHeight, blueCount, blueHeight ) );
      }
      case 1: {
         int redCount              = 4;
         int redHeight             = 4;
         int blueCount             = 4;
         int blueHeight            = 7;
         int expected__            = 12;

         return verify_case( casenum__, starttime__, expected__, TheBrickTowerEasyDivTwo().find( redCount, redHeight, blueCount, blueHeight ) );
      }
      case 2: {
         int redCount              = 7;
         int redHeight             = 7;
         int blueCount             = 4;
         int blueHeight            = 4;
         int expected__            = 13;

         return verify_case( casenum__, starttime__, expected__, TheBrickTowerEasyDivTwo().find( redCount, redHeight, blueCount, blueHeight ) );
      }
      case 3: {
         int redCount              = 47;
         int redHeight             = 47;
         int blueCount             = 47;
         int blueHeight            = 47;
         int expected__            = 94;

         return verify_case( casenum__, starttime__, expected__, TheBrickTowerEasyDivTwo().find( redCount, redHeight, blueCount, blueHeight ) );
      }

      // custom cases

/*
      case 4: {
         int redCount              = ;
         int redHeight             = ;
         int blueCount             = ;
         int blueHeight            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, TheBrickTowerEasyDivTwo().find( redCount, redHeight, blueCount, blueHeight ) );
      }
*/
/*
      case 5: {
         int redCount              = ;
         int redHeight             = ;
         int blueCount             = ;
         int blueHeight            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, TheBrickTowerEasyDivTwo().find( redCount, redHeight, blueCount, blueHeight ) );
      }
*/
/*
      case 6: {
         int redCount              = ;
         int redHeight             = ;
         int blueCount             = ;
         int blueHeight            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, TheBrickTowerEasyDivTwo().find( redCount, redHeight, blueCount, blueHeight ) );
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
