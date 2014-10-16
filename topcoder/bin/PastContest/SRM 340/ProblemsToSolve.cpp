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
#define INF 987654321

int memo[55][55][55];

class ProblemsToSolve {
public:

   int doit(int cur, int cmin, int cmax, int threshold, vector <int> &a) {
      if(cur >= sz(a) && a[cmax]-a[cmin] < threshold) return INF;
      if(cur >= sz(a) || a[cmax]-a[cmin] >= threshold) return 0;
      if(memo[cur][cmin][cmax]>=0) return memo[cur][cmin][cmax];
      int m1 = cmin, m2 = cmax;
      if(a[cur] < a[m1]) 
         m1 = cur;
      if(a[cur] > a[m2]) 
         m2 = cur;
      return memo[cur][cmin][cmax] = min(doit(cur+1,m1,m2,threshold,a),doit(cur+2,m1,m2,threshold,a))+1;
   }

   int minNumber( vector <int> pleasantness, int variety ) {
      memset(memo,-1,sizeof(memo));
      int res = doit(0,0,0,variety,pleasantness);
      if(res >= INF) return pleasantness.size();
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
         int pleasantness[]        = {1, 2, 3};
         int variety               = 2;
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, ProblemsToSolve().minNumber( vector <int>( pleasantness, pleasantness + ( sizeof pleasantness / sizeof(int) ) ), variety ) );
      }
      case 1: {
         int pleasantness[]        = {1, 2, 3, 4, 5};
         int variety               = 4;
         int expected__            = 3;

         return verify_case( casenum__, starttime__, expected__, ProblemsToSolve().minNumber( vector <int>( pleasantness, pleasantness + ( sizeof pleasantness / sizeof(int) ) ), variety ) );
      }
      case 2: {
         int pleasantness[]        = {10, 1, 12, 101};
         int variety               = 100;
         int expected__            = 3;

         return verify_case( casenum__, starttime__, expected__, ProblemsToSolve().minNumber( vector <int>( pleasantness, pleasantness + ( sizeof pleasantness / sizeof(int) ) ), variety ) );
      }
      case 3: {
         int pleasantness[]        = {10, 1};
         int variety               = 9;
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, ProblemsToSolve().minNumber( vector <int>( pleasantness, pleasantness + ( sizeof pleasantness / sizeof(int) ) ), variety ) );
      }
      case 4: {
         int pleasantness[]        = {6, 2, 6, 2, 6, 3, 3, 3, 7};
         int variety               = 4;
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, ProblemsToSolve().minNumber( vector <int>( pleasantness, pleasantness + ( sizeof pleasantness / sizeof(int) ) ), variety ) );
      }

      // custom cases


      case 5: {
         int pleasantness[]        = {1};
         int variety               = 1;
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, ProblemsToSolve().minNumber( vector <int>( pleasantness, pleasantness + ( sizeof pleasantness / sizeof(int) ) ), variety ) );
      }

/*
      case 6: {
         int pleasantness[]        = ;
         int variety               = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, ProblemsToSolve().minNumber( vector <int>( pleasantness, pleasantness + ( sizeof pleasantness / sizeof(int) ) ), variety ) );
      }
*/
/*
      case 7: {
         int pleasantness[]        = ;
         int variety               = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, ProblemsToSolve().minNumber( vector <int>( pleasantness, pleasantness + ( sizeof pleasantness / sizeof(int) ) ), variety ) );
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
