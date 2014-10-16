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

class Suminator {
public:

   llong solve(vector<int> &a, int pos, int val) {
      stack<llong> s;
      a[pos] = val;
      for(int i = 0; i < sz(a); ++i) {
         if(!a[i]) {
            if(sz(s) >= 2) {
               llong x = s.top(); s.pop();
               llong y = s.top(); s.pop();
               s.push(x+y);
            } else if(sz(s) == 0) {
               s.push(0LL);
            }
         } else {
            s.push(a[i]);
         }
      }
      a[pos] = -1;
      return sz(s) >= 1 ? s.top() : 0;
   }

   int findMissing( vector <int> a, int wantedResult ) {
      int pos = find(all(a), -1) - a.begin();
      if(solve(a, pos, 0) == wantedResult) return 0;
      llong lo = 1, hi = 1000000000LL;
      while(lo < hi) {
         llong mid = lo + (hi - lo) / 2;
         if(solve(a, pos, mid) < wantedResult)
            lo = mid + 1;
         else 
            hi = mid;
      }
      return solve(a, pos, lo) == wantedResult ? lo : -1;
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
         int program[]             = {7,-1,0};
         int wantedResult          = 10;
         int expected__            = 3;

         return verify_case( casenum__, starttime__, expected__, Suminator().findMissing( vector <int>( program, program + ( sizeof program / sizeof(int) ) ), wantedResult ) );
      }
      case 1: {
         int program[]             = {100, 200, 300, 0, 100, -1};
         int wantedResult          = 600;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, Suminator().findMissing( vector <int>( program, program + ( sizeof program / sizeof(int) ) ), wantedResult ) );
      }
      case 2: {
         int program[]             = {-1, 7, 3, 0, 1, 2, 0, 0};
         int wantedResult          = 13;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, Suminator().findMissing( vector <int>( program, program + ( sizeof program / sizeof(int) ) ), wantedResult ) );
      }
      case 3: {
         int program[]             = {-1, 8, 4, 0, 1, 2, 0, 0};
         int wantedResult          = 16;
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, Suminator().findMissing( vector <int>( program, program + ( sizeof program / sizeof(int) ) ), wantedResult ) );
      }
      case 4: {
         int program[]             = {1000000000, 1000000000, 1000000000,  1000000000, -1, 0, 0, 0, 0};
         int wantedResult          = 1000000000;
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, Suminator().findMissing( vector <int>( program, program + ( sizeof program / sizeof(int) ) ), wantedResult ) );
      }
      case 5: {
         int program[]             = {7, -1, 3, 0};
         int wantedResult          = 3;
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, Suminator().findMissing( vector <int>( program, program + ( sizeof program / sizeof(int) ) ), wantedResult ) );
      }

      // custom cases


      case 6: {
         int program[]             = {845151429, 60888921, 349419441, 452722179, 698157266, 589688000, 0, 0, 614020210, 917738413, 0, 0, 984300555, 785675697, 623438381, 865773912, -1, 0, 0, 202538864, 576905676, 0, 320406658, 0, 634482942, 379832022, 241814338, 0, 0, 0, 0, 0, 815856524, 588150990, 672632541, 704357226, 0, 0, 205398249, 0, 0, 0, 0};
         int wantedResult          = 122233108;
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, Suminator().findMissing( vector <int>( program, program + ( sizeof program / sizeof(int) ) ), wantedResult ) );
      }


      case 7: {
         int program[]             = {789654684, 566364589, 132807813, 954342599, 35537713, 167014159, 0, 0, 527502165, 863260323, 0, 62519272, 0, 109943112, 515518880, 438991295, 0, 0, 0, 388935264, 172607760, 489587296, 486148885, 485583952, 0, 0, 0, 0, 0, 0, 0, 43897666, -1, 0, 686446611, 0, 610840718, 45645333, 0, 0, 0, 913613509, 612042210, 0, 0};
         int wantedResult          = 238208598;
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, Suminator().findMissing( vector <int>( program, program + ( sizeof program / sizeof(int) ) ), wantedResult ) );
      }

/*
      case 8: {
         int program[]             = ;
         int wantedResult          = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, Suminator().findMissing( vector <int>( program, program + ( sizeof program / sizeof(int) ) ), wantedResult ) );
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
