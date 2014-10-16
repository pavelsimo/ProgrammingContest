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

vector<int> W;
int X[20];
bool seen[20];

class CasketOfStarEasy {
public:

   int get_cost() {
      int res = 0;
      memset(seen, false, sizeof(seen));
      for(int i = 1; i < sz(W) - 1; ++i) {
          int j, k;
          seen[X[i]] = true;
          for(j = X[i] - 1; j >= 0; --j)
             if(!seen[j]) break;
          for(k = X[i] + 1; k < sz(W); ++k)
             if(!seen[k]) break;
          res+=W[j]*W[k];
      }
      return res;
   }

   int maxEnergy( vector <int> weight ) {
      int res = 0;
      W = weight;
      for(int i = 0; i < sz(W); ++i) 
         X[i] = i;
      do {
         res = max(res, get_cost());
      } while(next_permutation(X + 1, X + sz(W) - 1));
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
         int weight[]              = {1,2,3,4};
         int expected__            = 12;

         return verify_case( casenum__, starttime__, expected__, CasketOfStarEasy().maxEnergy( vector <int>( weight, weight + ( sizeof weight / sizeof(int) ) ) ) );
      }
      case 1: {
         int weight[]              = {100,2,1,3,100};
         int expected__            = 10400;

         return verify_case( casenum__, starttime__, expected__, CasketOfStarEasy().maxEnergy( vector <int>( weight, weight + ( sizeof weight / sizeof(int) ) ) ) );
      }
      case 2: {
         int weight[]              = {2,2,7,6,90,5,9};
         int expected__            = 1818;

         return verify_case( casenum__, starttime__, expected__, CasketOfStarEasy().maxEnergy( vector <int>( weight, weight + ( sizeof weight / sizeof(int) ) ) ) );
      }
      case 3: {
         int weight[]              = {477,744,474,777,447,747,777,474};
         int expected__            = 2937051;

         return verify_case( casenum__, starttime__, expected__, CasketOfStarEasy().maxEnergy( vector <int>( weight, weight + ( sizeof weight / sizeof(int) ) ) ) );
      }
      case 4: {
         int weight[]              = {1,1,1,1,1,1,1,1,1,1};
         int expected__            = 8;

         return verify_case( casenum__, starttime__, expected__, CasketOfStarEasy().maxEnergy( vector <int>( weight, weight + ( sizeof weight / sizeof(int) ) ) ) );
      }
      case 5: {
         int weight[]              = {1,1,100,1,1,1,1,100,1,1};
         int expected__            = 10601;

         return verify_case( casenum__, starttime__, expected__, CasketOfStarEasy().maxEnergy( vector <int>( weight, weight + ( sizeof weight / sizeof(int) ) ) ) );
      }

      // custom cases

      case 6: {
         int weight[]              = {2,1,2};
         int expected__            = 4;

         return verify_case( casenum__, starttime__, expected__, CasketOfStarEasy().maxEnergy( vector <int>( weight, weight + ( sizeof weight / sizeof(int) ) ) ) );
      }


      case 7: {
         int weight[]              = {1,2,1,2};
         int expected__            = 6;

         return verify_case( casenum__, starttime__, expected__, CasketOfStarEasy().maxEnergy( vector <int>( weight, weight + ( sizeof weight / sizeof(int) ) ) ) );
      }

/*
      case 7: {
         int weight[]              = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, CasketOfStarEasy().maxEnergy( vector <int>( weight, weight + ( sizeof weight / sizeof(int) ) ) ) );
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
