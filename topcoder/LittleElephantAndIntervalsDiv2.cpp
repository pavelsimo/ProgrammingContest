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

#define SZ(a) int((a).size())
#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FOREACH(it,c) for(__typeof__((c).begin()) it=(c).begin();it!=(c).end();++it)


class LittleElephantAndIntervalsDiv2 {
public:
   
   vector<int> lo, hi;
   int nblocks;
   int nintervals;
   char color[12];
   set<string> S;
   
   void go(int cur_interval) {
      if(cur_interval == nintervals) {
         string new_block(nblocks, 'W');
         for(int i = 0; i < nintervals; ++i) {
            for(int j = lo[i] - 1; j <= hi[i] - 1; ++j) {
               new_block[j] = color[i];
            }
         }
         S.insert(new_block);
      } else {
         color[cur_interval] = 'B';
         go(cur_interval + 1);
         color[cur_interval] = 'W';
         go(cur_interval + 1);
      }
   }
   

   int getNumber( int M, vector <int> L, vector <int> R ) {
      S.clear();
      lo = L, hi = R;
      nblocks = M;
      nintervals = SZ(L);
      go(0);
      return SZ(S);
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
         int M                     = 4;
         int L[]                   = {1, 2, 3};
         int R[]                   = {1, 2, 3};
         int expected__            = 8;

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndIntervalsDiv2().getNumber( M, vector <int>( L, L + ( sizeof L / sizeof(int) ) ), vector <int>( R, R + ( sizeof R / sizeof(int) ) ) ) );
      }
      case 1: {
         int M                     = 3;
         int L[]                   = {1, 1, 2};
         int R[]                   = {3, 1, 3};
         int expected__            = 4;

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndIntervalsDiv2().getNumber( M, vector <int>( L, L + ( sizeof L / sizeof(int) ) ), vector <int>( R, R + ( sizeof R / sizeof(int) ) ) ) );
      }
      case 2: {
         int M                     = 100;
         int L[]                   = {47};
         int R[]                   = {74};
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndIntervalsDiv2().getNumber( M, vector <int>( L, L + ( sizeof L / sizeof(int) ) ), vector <int>( R, R + ( sizeof R / sizeof(int) ) ) ) );
      }
      case 3: {
         int M                     = 100;
         int L[]                   = {10, 20, 50};
         int R[]                   = {20, 50, 100};
         int expected__            = 8;

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndIntervalsDiv2().getNumber( M, vector <int>( L, L + ( sizeof L / sizeof(int) ) ), vector <int>( R, R + ( sizeof R / sizeof(int) ) ) ) );
      }
      case 4: {
         int M                     = 42;
         int L[]                   = {5, 23, 4, 1, 15, 2, 22, 26, 13, 16};
         int R[]                   = {30, 41, 17, 1, 21, 6, 28, 30, 15, 19};
         int expected__            = 512;

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndIntervalsDiv2().getNumber( M, vector <int>( L, L + ( sizeof L / sizeof(int) ) ), vector <int>( R, R + ( sizeof R / sizeof(int) ) ) ) );
      }

      // custom cases

/*
      case 5: {
         int M                     = ;
         int L[]                   = ;
         int R[]                   = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndIntervalsDiv2().getNumber( M, vector <int>( L, L + ( sizeof L / sizeof(int) ) ), vector <int>( R, R + ( sizeof R / sizeof(int) ) ) ) );
      }
*/
/*
      case 6: {
         int M                     = ;
         int L[]                   = ;
         int R[]                   = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndIntervalsDiv2().getNumber( M, vector <int>( L, L + ( sizeof L / sizeof(int) ) ), vector <int>( R, R + ( sizeof R / sizeof(int) ) ) ) );
      }
*/
/*
      case 7: {
         int M                     = ;
         int L[]                   = ;
         int R[]                   = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndIntervalsDiv2().getNumber( M, vector <int>( L, L + ( sizeof L / sizeof(int) ) ), vector <int>( R, R + ( sizeof R / sizeof(int) ) ) ) );
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
