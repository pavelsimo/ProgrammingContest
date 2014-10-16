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


class PlatypusDuckAndBeaver {
public:
   int minimumAnimals( int WF, int DB, int BT ) {
      int res = 0;
      for(int d = 0; d <= 1000; ++d) {
         for(int b = 0; b <= 1000; ++b) {
            int wf = WF, db = DB, bt = BT;
            if(wf >= 2*d + 4*b && db >= d && bt >= b) {
               wf -= 2*d + 4*b; 
               db -= d; 
               bt -= b;
               if(wf == 0 && db == 0 && bt == 0) {
                  return d + b;
               } else if(wf % 4 == 0) {
                  wf /= 4;
                  if(wf == db && wf == bt && db == bt) {                
                     return d + b + wf;
                  }                                    
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
         int webbedFeet            = 4;
         int duckBills             = 1;
         int beaverTails           = 1;
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, PlatypusDuckAndBeaver().minimumAnimals( webbedFeet, duckBills, beaverTails ) );
      }
      case 1: {
         int webbedFeet            = 0;
         int duckBills             = 0;
         int beaverTails           = 0;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, PlatypusDuckAndBeaver().minimumAnimals( webbedFeet, duckBills, beaverTails ) );
      }
      case 2: {
         int webbedFeet            = 10;
         int duckBills             = 2;
         int beaverTails           = 2;
         int expected__            = 3;

         return verify_case( casenum__, starttime__, expected__, PlatypusDuckAndBeaver().minimumAnimals( webbedFeet, duckBills, beaverTails ) );
      }
      case 3: {
         int webbedFeet            = 60;
         int duckBills             = 10;
         int beaverTails           = 10;
         int expected__            = 20;

         return verify_case( casenum__, starttime__, expected__, PlatypusDuckAndBeaver().minimumAnimals( webbedFeet, duckBills, beaverTails ) );
      }
      case 4: {
         int webbedFeet            = 1000;
         int duckBills             = 200;
         int beaverTails           = 200;
         int expected__            = 300;

         return verify_case( casenum__, starttime__, expected__, PlatypusDuckAndBeaver().minimumAnimals( webbedFeet, duckBills, beaverTails ) );
      }

      // custom cases

/*
      case 5: {
         int webbedFeet            = ;
         int duckBills             = ;
         int beaverTails           = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, PlatypusDuckAndBeaver().minimumAnimals( webbedFeet, duckBills, beaverTails ) );
      }
*/
/*
      case 6: {
         int webbedFeet            = ;
         int duckBills             = ;
         int beaverTails           = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, PlatypusDuckAndBeaver().minimumAnimals( webbedFeet, duckBills, beaverTails ) );
      }
*/
/*
      case 7: {
         int webbedFeet            = ;
         int duckBills             = ;
         int beaverTails           = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, PlatypusDuckAndBeaver().minimumAnimals( webbedFeet, duckBills, beaverTails ) );
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
