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


class FoxAndDoraemon {
public:
   int f(int N) {
      int res = 0;
      while(N > 0) {
         res++;
         N/=2;
      }
      return res;
   }

   int minTime( vector <int> workCost, int splitCost ) {
      int N = sz(workCost);
      sort(all(workCost));
      int splitCnt = f(N) - 1;
      int X = splitCnt * splitCost;
      int Z = (splitCnt * (splitCnt - 1)) / 2;
      int Y = workCost[N - 1];
      DEBUG(X);
      DEBUG(Z);
      DEBUG(Y);
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
         int workCost[]            = {1,2};
         int splitCost             = 1000;
         int expected__            = 1002;

         return verify_case( casenum__, starttime__, expected__, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof(int) ) ), splitCost ) );
      }
      case 1: {
         int workCost[]            = {3,6,9,12};
         int splitCost             = 1000;
         int expected__            = 2012;

         return verify_case( casenum__, starttime__, expected__, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof(int) ) ), splitCost ) );
      }
      case 2: {
         int workCost[]            = {1000,100,10,1};
         int splitCost             = 1;
         int expected__            = 1001;

         return verify_case( casenum__, starttime__, expected__, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof(int) ) ), splitCost ) );
      }
      case 3: {
         int workCost[]            = {1712,1911,1703,1610,1697,1612};
         int splitCost             = 100;
         int expected__            = 2012;

         return verify_case( casenum__, starttime__, expected__, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof(int) ) ), splitCost ) );
      }
      case 4: {
         int workCost[]            = {3000,3000,3000,3000,3000,3000,3000,3000,3000,3000};
         int splitCost             = 3000;
         int expected__            = 15000;

         return verify_case( casenum__, starttime__, expected__, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof(int) ) ), splitCost ) );
      }
      case 5: {
         int workCost[]            = {58};
         int splitCost             = 3600;
         int expected__            = 58;

         return verify_case( casenum__, starttime__, expected__, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof(int) ) ), splitCost ) );
      }

      // custom cases

/*
      case 6: {
         int workCost[]            = ;
         int splitCost             = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof(int) ) ), splitCost ) );
      }
*/
/*
      case 7: {
         int workCost[]            = ;
         int splitCost             = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof(int) ) ), splitCost ) );
      }
*/
/*
      case 8: {
         int workCost[]            = ;
         int splitCost             = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof(int) ) ), splitCost ) );
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
