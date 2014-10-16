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

int A[55][55];

class FlipGame {
public:
   int minOperations( vector <string> board ) {
      int res = 0;
      int N = sz(board);
      int M = sz(board[0]);
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < M; ++j) {      
            A[i][j] = (board[i][j] == '1');
         }
      }
      for(res = 0; true; ++res) {
         int k = 0;
         for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
               if(A[i][j]) 
                  k = max(k, j + 1);
            }
            for(int j = 0; j < k; ++j)
               A[i][j]^=1;
         }
         if(!k) break;
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
         string board[]            = {"1000",  "1110",  "1111"};
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, FlipGame().minOperations( vector <string>( board, board + ( sizeof board / sizeof(string) ) ) ) );
      }
      case 1: {
         string board[]            = {"1111",  "1111",  "1111"};
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, FlipGame().minOperations( vector <string>( board, board + ( sizeof board / sizeof(string) ) ) ) );
      }
      case 2: {
         string board[]            = {"00",  "00",  "00"};
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, FlipGame().minOperations( vector <string>( board, board + ( sizeof board / sizeof(string) ) ) ) );
      }
      case 3: {
         string board[]            = {"00000000",  "00100000",  "01000000",  "00001000",  "00000000"};
         int expected__            = 4;

         return verify_case( casenum__, starttime__, expected__, FlipGame().minOperations( vector <string>( board, board + ( sizeof board / sizeof(string) ) ) ) );
      }
      case 4: {
         string board[]            = {"000000000000001100000000000000",  "000000000000011110000000000000",  "000000000000111111000000000000",  "000000000001111111100000000000",  "000000000011111111110000000000",  "000000000111111111111000000000",  "000000001100111111001100000000",  "000000011000011110000110000000",  "000000111100111111001111000000",  "000001111111111111111111100000",  "000011111111111111111111110000",  "000111111111000000111111111000",  "001111111111100001111111111100",  "011111111111110011111111111110",  "111111111111111111111111111111"};
         int expected__            = 29;

         return verify_case( casenum__, starttime__, expected__, FlipGame().minOperations( vector <string>( board, board + ( sizeof board / sizeof(string) ) ) ) );
      }

      // custom cases

/*
      case 5: {
         string board[]            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, FlipGame().minOperations( vector <string>( board, board + ( sizeof board / sizeof(string) ) ) ) );
      }
*/
/*
      case 6: {
         string board[]            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, FlipGame().minOperations( vector <string>( board, board + ( sizeof board / sizeof(string) ) ) ) );
      }
*/
/*
      case 7: {
         string board[]            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, FlipGame().minOperations( vector <string>( board, board + ( sizeof board / sizeof(string) ) ) ) );
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
