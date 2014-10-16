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

typedef long long llong;

class SlimeXSlimesCity {
public:

   int merge( vector <int> population ) {
      int N = sz(population);
      vector<llong> sum(N);
      int res = 0;
      sort(population.begin(),population.end());
      sum[0] = 0; 
      for(int i = 1; i < N; ++i) {
         sum[i] = population[i-1]+sum[i-1];
      }
      for(int i = 0; i < N; ++i) {
         int j;
         for(j = i+1; j < N; ++j) {
            if(population[j]>sum[j]) break;
         }
         if(j==N) res++;
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
         int population[]          = {2, 3, 4};
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, SlimeXSlimesCity().merge( vector <int>( population, population + ( sizeof population / sizeof(int) ) ) ) );
      }
      case 1: {
         int population[]          = {1, 2, 3};
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, SlimeXSlimesCity().merge( vector <int>( population, population + ( sizeof population / sizeof(int) ) ) ) );
      }
      case 2: {
         int population[]          = {8,2,3,8};
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, SlimeXSlimesCity().merge( vector <int>( population, population + ( sizeof population / sizeof(int) ) ) ) );
      }
      case 3: {
         int population[]          = {1000000000, 999999999, 999999998, 999999997};
         int expected__            = 3;

         return verify_case( casenum__, starttime__, expected__, SlimeXSlimesCity().merge( vector <int>( population, population + ( sizeof population / sizeof(int) ) ) ) );
      }
      case 4: {
         int population[]          = {1,1,1};
         int expected__            = 3;

         return verify_case( casenum__, starttime__, expected__, SlimeXSlimesCity().merge( vector <int>( population, population + ( sizeof population / sizeof(int) ) ) ) );
      }
      case 5: {
         int population[]          = {1, 2, 4, 6, 14, 16, 20};
         int expected__            = 3;

         return verify_case( casenum__, starttime__, expected__, SlimeXSlimesCity().merge( vector <int>( population, population + ( sizeof population / sizeof(int) ) ) ) );
      }
      
      //{{1, 3, 5, 7, 8, 10, 21, 23, 45, 678, 3330, 4445, 5567, 6789, 9832, 278934, 4749874, 387383, 3873893, 3873, 378636, 3783, 38733, 38739, 393783, 38973, 3637, 37, 458579, 587585, 5857895, 587598, 5857985, 58759, 5857985, 5987589, 5985795, 5857895, 58579, 589579}}

      // custom cases


      case 6: {
         int population[]          = {1, 3, 5, 7, 8, 10, 21, 23, 45, 678, 3330, 4445, 5567, 6789, 9832, 278934, 4749874, 387383, 3873893, 3873, 378636, 3783, 38733, 38739, 393783, 38973, 3637, 37, 458579, 587585, 5857895, 587598, 5857985, 58759, 5857985, 5987589, 5985795, 5857895, 58579, 589579};
         int expected__            = 16;

         return verify_case( casenum__, starttime__, expected__, SlimeXSlimesCity().merge( vector <int>( population, population + ( sizeof population / sizeof(int) ) ) ) );
      }

/*
      case 7: {
         int population[]          = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, SlimeXSlimesCity().merge( vector <int>( population, population + ( sizeof population / sizeof(int) ) ) ) );
      }
*/
/*
      case 8: {
         int population[]          = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, SlimeXSlimesCity().merge( vector <int>( population, population + ( sizeof population / sizeof(int) ) ) ) );
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
