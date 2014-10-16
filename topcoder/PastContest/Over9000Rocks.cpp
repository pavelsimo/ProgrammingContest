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

typedef pair<int,int> Node;


class Over9000Rocks {
public:

   int countPossibilities( vector <int> lowerBound, vector <int> upperBound ) {
      vector<Node> X;
      int N = sz(lowerBound);
      for(int i = 0; i < (1<< N); ++i) {
         int sumL = 0;
         int sumU = 0;
         for(int j = 0; j < N; ++j) {
            if(i & (1<<j)) {
               sumL+=lowerBound[j];
               sumU+=upperBound[j];                              
            }
         }
         sumL = max(9001, sumL);
         if(sumU >= sumL)
            X.push_back(make_pair(sumL, -(sumU + 1)));
      }
      sort(all(X));
      int res = 0;
      int lo = 9001;
      for(int i = 0; i < sz(X); ++i) {
         res+=max(0,(-X[i].second) - max(lo, X[i].first));
         lo = max(lo, (-X[i].second));
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
         int lowerBound[]          = {9000};
         int upperBound[]          = {9001};
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, Over9000Rocks().countPossibilities( vector <int>( lowerBound, lowerBound + ( sizeof lowerBound / sizeof(int) ) ), vector <int>( upperBound, upperBound + ( sizeof upperBound / sizeof(int) ) ) ) );
      }
      case 1: {
         int lowerBound[]          = {9000, 1, 10};
         int upperBound[]          = {9000, 2, 20};
         int expected__            = 15;

         return verify_case( casenum__, starttime__, expected__, Over9000Rocks().countPossibilities( vector <int>( lowerBound, lowerBound + ( sizeof lowerBound / sizeof(int) ) ), vector <int>( upperBound, upperBound + ( sizeof upperBound / sizeof(int) ) ) ) );
      }
      case 2: {
         int lowerBound[]          = {1001, 2001, 3001, 3001};
         int upperBound[]          = {1003, 2003, 3003, 3003};
         int expected__            = 9;

         return verify_case( casenum__, starttime__, expected__, Over9000Rocks().countPossibilities( vector <int>( lowerBound, lowerBound + ( sizeof lowerBound / sizeof(int) ) ), vector <int>( upperBound, upperBound + ( sizeof upperBound / sizeof(int) ) ) ) );
      }
      case 3: {
         int lowerBound[]          = {9000,90000,1,10};
         int upperBound[]          = {9000,90000,3,15};
         int expected__            = 38;

         return verify_case( casenum__, starttime__, expected__, Over9000Rocks().countPossibilities( vector <int>( lowerBound, lowerBound + ( sizeof lowerBound / sizeof(int) ) ), vector <int>( upperBound, upperBound + ( sizeof upperBound / sizeof(int) ) ) ) );
      }
      case 4: {
         int lowerBound[]          = {1,1,1,1,1,1};
         int upperBound[]          = {3,4,5,6,7,8};
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, Over9000Rocks().countPossibilities( vector <int>( lowerBound, lowerBound + ( sizeof lowerBound / sizeof(int) ) ), vector <int>( upperBound, upperBound + ( sizeof upperBound / sizeof(int) ) ) ) );
      }

      // custom cases


      case 5: {
         int lowerBound[]          = {9000,9000,9000,9000,9000,9000,9000,9000,9000,9000,9000,9000};
         int upperBound[]          = {1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000};
         int expected__            = 11991000;

         return verify_case( casenum__, starttime__, expected__, Over9000Rocks().countPossibilities( vector <int>( lowerBound, lowerBound + ( sizeof lowerBound / sizeof(int) ) ), vector <int>( upperBound, upperBound + ( sizeof upperBound / sizeof(int) ) ) ) );
      }

/*
      case 6: {
         int lowerBound[]          = ;
         int upperBound[]          = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, Over9000Rocks().countPossibilities( vector <int>( lowerBound, lowerBound + ( sizeof lowerBound / sizeof(int) ) ), vector <int>( upperBound, upperBound + ( sizeof upperBound / sizeof(int) ) ) ) );
      }
*/
/*
      case 7: {
         int lowerBound[]          = ;
         int upperBound[]          = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, Over9000Rocks().countPossibilities( vector <int>( lowerBound, lowerBound + ( sizeof lowerBound / sizeof(int) ) ), vector <int>( upperBound, upperBound + ( sizeof upperBound / sizeof(int) ) ) ) );
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
