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


class ComplementMachine2D {
public:
   int largestSubmatrix( vector <string> matrix ) {

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
         string matrix[]           = {"0011",  "0011",  "1100",  "0111"};
         int expected__            = 12;

         return verify_case( casenum__, starttime__, expected__, ComplementMachine2D().largestSubmatrix( vector <string>( matrix, matrix + ( sizeof matrix / sizeof(string) ) ) ) );
      }
      case 1: {
         string matrix[]           = {"0011",  "1011",  "0101",  "1010"};
         int expected__            = 9;

         return verify_case( casenum__, starttime__, expected__, ComplementMachine2D().largestSubmatrix( vector <string>( matrix, matrix + ( sizeof matrix / sizeof(string) ) ) ) );
      }
      case 2: {
         string matrix[]           = {"1011",  "0011",  "0101",  "1010"};
         int expected__            = 8;

         return verify_case( casenum__, starttime__, expected__, ComplementMachine2D().largestSubmatrix( vector <string>( matrix, matrix + ( sizeof matrix / sizeof(string) ) ) ) );
      }
      case 3: {
         string matrix[]           = {"0000110101010",  "0111101010111",  "1110110111011"};
         int expected__            = 13;

         return verify_case( casenum__, starttime__, expected__, ComplementMachine2D().largestSubmatrix( vector <string>( matrix, matrix + ( sizeof matrix / sizeof(string) ) ) ) );
      }
      case 4: {
         string matrix[]           = {"11000000000110101101",  "00111111011101101101",  "00110011110111100010",  "10011110111110000111",  "00111010000000110111",  "00001101011011010110",  "11010010100100101100",  "11101101011011000001",  "11000010100100111001",  "11011010100100101010",  "10110010100100110110",  "01100010100100111001",  "10110010100100110011",  "01110101011011001010",  "01111101011011001011",  "00001000010010101011",  "11100101100100110001",  "10100100111001010101",  "11111000001010011110",  "01110100001110011111"} ;
         int expected__            = 100;

         return verify_case( casenum__, starttime__, expected__, ComplementMachine2D().largestSubmatrix( vector <string>( matrix, matrix + ( sizeof matrix / sizeof(string) ) ) ) );
      }

      // custom cases

/*
      case 5: {
         string matrix[]           = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, ComplementMachine2D().largestSubmatrix( vector <string>( matrix, matrix + ( sizeof matrix / sizeof(string) ) ) ) );
      }
*/
/*
      case 6: {
         string matrix[]           = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, ComplementMachine2D().largestSubmatrix( vector <string>( matrix, matrix + ( sizeof matrix / sizeof(string) ) ) ) );
      }
*/
/*
      case 7: {
         string matrix[]           = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, ComplementMachine2D().largestSubmatrix( vector <string>( matrix, matrix + ( sizeof matrix / sizeof(string) ) ) ) );
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
