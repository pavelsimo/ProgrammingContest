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

int N, M;
int memo[4][4][4][4]; //upper row, lower row, left column, right column
int a[4][4];

class CutTheNumbers {
public:

   int doit(int r1, int r2,int c1, int c2) {
      if(r1 > r2 || c1 > c2)
         return 0;
      if(memo[r1][r2][c1][c2]>=0)
         return memo[r1][r2][c1][c2];
      int res = 0;
      int cur = 0;
      // take upper row
      for(int c = c1; c <= c2;++c)
         cur = cur*10 + a[r1][c];
      res = max(res, cur + doit(r1+1,r2,c1,c2));
      
      // take left column
      cur = 0;
      for(int r = r1; r <= r2;++r)
         cur = cur*10 + a[r][c1];
      res = max(res, cur + doit(r1,r2,c1+1,c2));
      
      // take bottom row
      cur = 0;
      for(int c = c1; c <= c2;++c)
         cur = cur*10 + a[r2][c];
      res = max(res, cur + doit(r1,r2-1,c1,c2));
      
      // take right column
      cur = 0;
      for(int r = r1; r <= r2;++r)
         cur = cur*10 + a[r][c2];
      res = max(res, cur + doit(r1,r2,c1,c2-1));
      
      return memo[r1][r2][c1][c2] = res;
   }

   int maximumSum( vector <string> board ) {
      N = sz(board);
      M = sz(board[0]);
      memset(memo,-1,sizeof(memo));
      for(int i = 0; i < N; ++i)
         for(int j = 0; j < M; ++j)
            a[i][j] = board[i][j]-'0';
      int res = doit(0,N-1,0,M-1);
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
         string board[]            = {"123",  "312"};
         int expected__            = 435;

         return verify_case( casenum__, starttime__, expected__, CutTheNumbers().maximumSum( vector <string>( board, board + ( sizeof board / sizeof(string) ) ) ) );
      }
      case 1: {
         string board[]            = {"99",  "11"};
         int expected__            = 182;

         return verify_case( casenum__, starttime__, expected__, CutTheNumbers().maximumSum( vector <string>( board, board + ( sizeof board / sizeof(string) ) ) ) );
      }
      case 2: {
         string board[]            = {"001",  "010",  "111",  "100"};
         int expected__            = 1131;

         return verify_case( casenum__, starttime__, expected__, CutTheNumbers().maximumSum( vector <string>( board, board + ( sizeof board / sizeof(string) ) ) ) );
      }
      case 3: {
         string board[]            = {"8"};
         int expected__            = 8;

         return verify_case( casenum__, starttime__, expected__, CutTheNumbers().maximumSum( vector <string>( board, board + ( sizeof board / sizeof(string) ) ) ) );
      }

      // custom cases

/*
      case 4: {
         string board[]            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, CutTheNumbers().maximumSum( vector <string>( board, board + ( sizeof board / sizeof(string) ) ) ) );
      }
*/
/*
      case 5: {
         string board[]            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, CutTheNumbers().maximumSum( vector <string>( board, board + ( sizeof board / sizeof(string) ) ) ) );
      }
*/
/*
      case 6: {
         string board[]            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, CutTheNumbers().maximumSum( vector <string>( board, board + ( sizeof board / sizeof(string) ) ) ) );
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
