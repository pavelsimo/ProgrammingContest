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
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define pb push_back


class FoxProgression {
public:
   
   bool isArithmetic(vector<int> &a) {
      int n = sz(a);
      if(n==1) return false;
      int val = a[1]-a[0];
      for(int i = 2; i < n; ++i)
         if(a[i]-a[i-1]!=val) return false;
      return true;
   }
   
   bool isGeometry(vector<int> &a) {
      int n = sz(a);
      if(n==1) return false;
      int val = max(a[1],a[0])/min(a[1],a[0]);
      for(int i = 0; i < n-1; ++i)
         if(a[i]*val!=a[i+1]) return false;
      return true;
   }

   int theCount( vector <int> seq ) {
      int res = 0;
      if(sz(seq)==1) return -1;
      int t = seq[0];
      bool eq = true;
      for(int i = 0; i < sz(seq); ++i)
         if(t!=seq[i]) eq = false;
      if(eq) return 1;
      if(isArithmetic(seq)) res++;
      if(isGeometry(seq)) res++;
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
         int seq[]                 = {1, 2, 4, 8};
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, FoxProgression().theCount( vector <int>( seq, seq + ( sizeof seq / sizeof(int) ) ) ) );
      }
      case 1: {
         int seq[]                 = {5, 3, 1};
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, FoxProgression().theCount( vector <int>( seq, seq + ( sizeof seq / sizeof(int) ) ) ) );
      }
      case 2: {
         int seq[]                 = {1, 1};
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, FoxProgression().theCount( vector <int>( seq, seq + ( sizeof seq / sizeof(int) ) ) ) );
      }
      case 3: {
         int seq[]                 = {8, 4};
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, FoxProgression().theCount( vector <int>( seq, seq + ( sizeof seq / sizeof(int) ) ) ) );
      }
      case 4: {
         int seq[]                 = {1};
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, FoxProgression().theCount( vector <int>( seq, seq + ( sizeof seq / sizeof(int) ) ) ) );
      }
      case 5: {
         int seq[]                 = {4, 8};
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, FoxProgression().theCount( vector <int>( seq, seq + ( sizeof seq / sizeof(int) ) ) ) );
      }
      case 6: {
         int seq[]                 = {1, 3, 4};
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, FoxProgression().theCount( vector <int>( seq, seq + ( sizeof seq / sizeof(int) ) ) ) );
      }

      // custom cases

/*
      case 7: {
         int seq[]                 = {1, 4, 8};
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, FoxProgression().theCount( vector <int>( seq, seq + ( sizeof seq / sizeof(int) ) ) ) );
      }
*/
/*
      case 8: {
         int seq[]                 = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, FoxProgression().theCount( vector <int>( seq, seq + ( sizeof seq / sizeof(int) ) ) ) );
      }
*/
/*
      case 9: {
         int seq[]                 = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, FoxProgression().theCount( vector <int>( seq, seq + ( sizeof seq / sizeof(int) ) ) ) );
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
