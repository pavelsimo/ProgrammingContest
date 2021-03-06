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

const int INF = 0x3f3f3f3f;
typedef vector<int> VI;
typedef vector<VI> VVI;
VVI A;

class DropCoins {
public:
   int getMinimum( vector <string> board, int K ) {
      int res = INF;
      int N = sz(board);
      int M = sz(board[0]);
      A = VVI(N + 1, VI(M + 1));
      for(int i = 0; i < N; ++i) {
         int sum = 0;
         for(int j = 0; j < M; ++j) {
            sum+=board[i][j]=='o';
            if(i > 0) A[i][j] = A[i-1][j] + sum;
            else A[i][j] = sum;
         }
      }
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < M; ++j) {
            for(int ii = i; ii < N; ++ii) {
               for(int jj = j; jj < M; ++jj) {
                  int sum = A[ii][jj];
                  if(i > 0) sum-=A[i-1][jj];
                  if(j > 0) sum-=A[ii][j-1];
                  if(i > 0 && j > 0) sum+=A[i-1][j-1];
                  if(sum == K) {
                     int u = i; 
                     int d = N-ii-1;
                     int l = j;
                     int r = M-jj-1;
                     res = min(res, l + r + u + d + min(l,r) + min(u,d));
                  }
               }  
            }
         }   
      }
      return res == INF ? -1 : res;
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
         string board[]            = {".o.." ,"oooo" ,"..o."} ;
         int K                     = 3;
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof(string) ) ), K ) );
      }
      case 1: {
         string board[]            = {".....o" ,"......" ,"oooooo" ,"oooooo" ,"......" ,"o....."} ;
         int K                     = 12;
         int expected__            = 3;

         return verify_case( casenum__, starttime__, expected__, DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof(string) ) ), K ) );
      }
      case 2: {
         string board[]            = {"...." ,".oo." ,".oo." ,"...."} ;
         int K                     = 3;
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof(string) ) ), K ) );
      }
      case 3: {
         string board[]            = {"......." ,"..ooo.." ,"ooooooo" ,".oo.oo." ,"oo...oo"} ;
         int K                     = 12;
         int expected__            = 4;

         return verify_case( casenum__, starttime__, expected__, DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof(string) ) ), K ) );
      }
      case 4: {
         string board[]            = {"................." ,".ooooooo...oooo.." ,".ooooooo..oooooo." ,".oo.......oo..oo." ,".oo.......oo..oo." ,".ooooo.....oooo.." ,".ooooooo...oooo.." ,".....ooo..oo..oo." ,"......oo..oo..oo." ,".ooooooo..oooooo." ,".oooooo....oooo.." ,"................."} ;
         int K                     = 58;
         int expected__            = 6;

         return verify_case( casenum__, starttime__, expected__, DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof(string) ) ), K ) );
      }

      // custom cases

/*
      case 5: {
         string board[]            = ;
         int K                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof(string) ) ), K ) );
      }
*/
/*
      case 6: {
         string board[]            = ;
         int K                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof(string) ) ), K ) );
      }
*/
/*
      case 7: {
         string board[]            = ;
         int K                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof(string) ) ), K ) );
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
