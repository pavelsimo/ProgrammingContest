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
#define pb push_back


class QuizShow {
public:
   int wager( vector <int> scores, int wager1, int wager2 ) {
      int res = 0, best = 0;
      int N = scores[0];
      int M = 1 << 3;
      for(int w = 0; w <= N; ++w) {
         int wins = 0;
         for(int i = 0; i < M; ++i) {
            int A = scores[0];
            int B = scores[1];
            int C = scores[2];
            if(i & 4) A+=w;
            else A-=w;
            if(i & 2) B+=wager1;
            else B-=wager1;
            if(i & 1) C+=wager2;
            else C-=wager2;
            if(A > B && A > C)
               wins++;
         }
         if(wins > best) {
            best = wins;
            res = w;
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
         int scores[]              = { 100, 100, 100 };
         int wager1                = 25;
         int wager2                = 75;
         int expected__            = 76;

         return verify_case( casenum__, starttime__, expected__, QuizShow().wager( vector <int>( scores, scores + ( sizeof scores / sizeof(int) ) ), wager1, wager2 ) );
      }
      case 1: {
         int scores[]              = { 10, 50, 60 };
         int wager1                = 30;
         int wager2                = 41;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, QuizShow().wager( vector <int>( scores, scores + ( sizeof scores / sizeof(int) ) ), wager1, wager2 ) );
      }
      case 2: {
         int scores[]              = { 10, 50, 60 };
         int wager1                = 31;
         int wager2                = 41;
         int expected__            = 10;

         return verify_case( casenum__, starttime__, expected__, QuizShow().wager( vector <int>( scores, scores + ( sizeof scores / sizeof(int) ) ), wager1, wager2 ) );
      }
      case 3: {
         int scores[]              = { 2, 2, 12 };
         int wager1                = 0;
         int wager2                = 10;
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, QuizShow().wager( vector <int>( scores, scores + ( sizeof scores / sizeof(int) ) ), wager1, wager2 ) );
      }
      case 4: {
         int scores[]              = { 10000, 10000, 10000 };
         int wager1                = 9998;
         int wager2                = 9997;
         int expected__            = 9999;

         return verify_case( casenum__, starttime__, expected__, QuizShow().wager( vector <int>( scores, scores + ( sizeof scores / sizeof(int) ) ), wager1, wager2 ) );
      }
      case 5: {
         int scores[]              = { 5824, 4952, 6230 };
         int wager1                = 364;
         int wager2                = 287;
         int expected__            = 694;

         return verify_case( casenum__, starttime__, expected__, QuizShow().wager( vector <int>( scores, scores + ( sizeof scores / sizeof(int) ) ), wager1, wager2 ) );
      }

      // custom cases

/*
      case 6: {
         int scores[]              = ;
         int wager1                = ;
         int wager2                = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, QuizShow().wager( vector <int>( scores, scores + ( sizeof scores / sizeof(int) ) ), wager1, wager2 ) );
      }
*/
/*
      case 7: {
         int scores[]              = ;
         int wager1                = ;
         int wager2                = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, QuizShow().wager( vector <int>( scores, scores + ( sizeof scores / sizeof(int) ) ), wager1, wager2 ) );
      }
*/
/*
      case 8: {
         int scores[]              = ;
         int wager1                = ;
         int wager2                = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, QuizShow().wager( vector <int>( scores, scores + ( sizeof scores / sizeof(int) ) ), wager1, wager2 ) );
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
