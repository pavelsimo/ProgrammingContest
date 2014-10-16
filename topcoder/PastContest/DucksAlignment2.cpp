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

typedef pair<int,int> PII;
const int INF = 0x3f3f3f3f;
int N, M;

class DucksAlignment {
public:

   int dist(PII p1, PII p2) {
      return abs(p1.first-p2.first) + abs(p1.second-p2.second);      
   }

   int minimumTime( vector <string> grid ) {
      int res = INF;
      int H = sz(grid);
      int W = sz(grid[0]);
      vector<PII> ducks;
      for(int r = 0; r < H; ++r) {
         for(int c = 0; c < W; ++c) {
            if(grid[r][c] == 'o') {
               ducks.push_back(PII(r,c));
            }
         }
      }
      sort(all(ducks));
      int N = sz(ducks);
      for(int c = 0; c < W; ++c) {
         for(int r = 0; r + N <= H; ++r) {
            int cost = 0;
            for(int i = 0; i < N; ++i)
               cost+=dist(PII(r+i,c),ducks[i]);
            res = min(res,cost);      
         }
      }
      for(int i = 0; i < N; ++i)
         swap(ducks[i].first,ducks[i].second);
      sort(all(ducks));
      for(int r = 0; r < H; ++r) {
         for(int c = 0; c + N <= W; ++c) {
            int cost = 0;
            for(int i = 0; i < N; ++i)
               cost+=dist(make_pair(r,c+i),ducks[i]);
            res = min(res,cost);
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
         string grid[]             = {".o",  "o."};
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, DucksAlignment().minimumTime( vector <string>( grid, grid + ( sizeof grid / sizeof(string) ) ) ) );
      }
      case 1: {
         string grid[]             = {".o...",  "..o..",  "....o"};
         int expected__            = 3;

         return verify_case( casenum__, starttime__, expected__, DucksAlignment().minimumTime( vector <string>( grid, grid + ( sizeof grid / sizeof(string) ) ) ) );
      }
      case 2: {
         string grid[]             = {"o..........",  "..o........",  ".......o...",  "...........",  "...........",  "...........",  "........o..",  "..........."};
         int expected__            = 16;

         return verify_case( casenum__, starttime__, expected__, DucksAlignment().minimumTime( vector <string>( grid, grid + ( sizeof grid / sizeof(string) ) ) ) );
      }
      case 3: {
         string grid[]             = {".........",  "....o....",  "........."};
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, DucksAlignment().minimumTime( vector <string>( grid, grid + ( sizeof grid / sizeof(string) ) ) ) );
      }
      case 4: {
         string grid[]             = {"...o..........................",  "............................o.",  ".o............................",  "............o.................",  ".................o............",  "......................o.......",  "......o.......................",  "....o.........................",  "...............o..............",  ".......................o......",  "...........................o..",  ".......o......................"};
         int expected__            = 99;

         return verify_case( casenum__, starttime__, expected__, DucksAlignment().minimumTime( vector <string>( grid, grid + ( sizeof grid / sizeof(string) ) ) ) );
      }

      // custom cases

/*
      case 5: {
         string grid[]             = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, DucksAlignment().minimumTime( vector <string>( grid, grid + ( sizeof grid / sizeof(string) ) ) ) );
      }
*/
/*
      case 6: {
         string grid[]             = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, DucksAlignment().minimumTime( vector <string>( grid, grid + ( sizeof grid / sizeof(string) ) ) ) );
      }
*/
/*
      case 7: {
         string grid[]             = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, DucksAlignment().minimumTime( vector <string>( grid, grid + ( sizeof grid / sizeof(string) ) ) ) );
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
