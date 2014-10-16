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

typedef vector<int> VI;

VI P, S;
int F[] = {2,4,8};
int memo[10][200][200];

class SRMCodingPhase {  
public:
   int rec(int mask, int ctime, int luck) {
      int res = 0;
      if(memo[mask][ctime][luck] >= 0) 
         return memo[mask][ctime][luck];
      for(int i = 0; i < 3; ++i) {
         if(!(mask & (1<<i))) {
            for(int l = 0; l <= min(luck, S[i] - 1); ++l) {
               int ntime = S[i] - l;
               if(ctime >= ntime)
                  res = max(res, rec(mask|(1<<i), ctime - ntime, luck - l) + P[i] - F[i] * ntime);   
            }
         }
      }
      return memo[mask][ctime][luck] = res;
   }
   
   int countScore( vector <int> points, vector <int> skills, int luck ) {
      memset(memo,-1,sizeof(memo));
      P = points;
      S = skills;
      return rec(0,75,luck);
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
         int points[]              = {250, 500, 1000};
         int skills[]              = {10, 25, 40};
         int luck                  = 0;
         int expected__            = 1310;

         return verify_case( casenum__, starttime__, expected__, SRMCodingPhase().countScore( vector <int>( points, points + ( sizeof points / sizeof(int) ) ), vector <int>( skills, skills + ( sizeof skills / sizeof(int) ) ), luck ) );
      }
      case 1: {
         int points[]              = {300, 600, 900};
         int skills[]              = {30, 65, 90};
         int luck                  = 25;
         int expected__            = 680;

         return verify_case( casenum__, starttime__, expected__, SRMCodingPhase().countScore( vector <int>( points, points + ( sizeof points / sizeof(int) ) ), vector <int>( skills, skills + ( sizeof skills / sizeof(int) ) ), luck ) );
      }
      case 2: {
         int points[]              = {250, 550, 950};
         int skills[]              = {10, 25, 40};
         int luck                  = 75;
         int expected__            = 1736;

         return verify_case( casenum__, starttime__, expected__, SRMCodingPhase().countScore( vector <int>( points, points + ( sizeof points / sizeof(int) ) ), vector <int>( skills, skills + ( sizeof skills / sizeof(int) ) ), luck ) );
      }
      case 3: {
         int points[]              = {256, 512, 1024};
         int skills[]              = {35, 30, 25};
         int luck                  = 0;
         int expected__            = 1216;

         return verify_case( casenum__, starttime__, expected__, SRMCodingPhase().countScore( vector <int>( points, points + ( sizeof points / sizeof(int) ) ), vector <int>( skills, skills + ( sizeof skills / sizeof(int) ) ), luck ) );
      }
      case 4: {
         int points[]              = {300, 600, 1100};
         int skills[]              = {80, 90, 100};
         int luck                  = 4;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, SRMCodingPhase().countScore( vector <int>( points, points + ( sizeof points / sizeof(int) ) ), vector <int>( skills, skills + ( sizeof skills / sizeof(int) ) ), luck ) );
      }

      // custom cases


      case 5: {
         int points[]              = {300,500,999};
         int skills[]              = {75,75,75};
         int luck                  = 100;
         int expected__            = 1295;

         return verify_case( casenum__, starttime__, expected__, SRMCodingPhase().countScore( vector <int>( points, points + ( sizeof points / sizeof(int) ) ), vector <int>( skills, skills + ( sizeof skills / sizeof(int) ) ), luck ) );
      }

/*
      case 6: {
         int points[]              = ;
         int skills[]              = ;
         int luck                  = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, SRMCodingPhase().countScore( vector <int>( points, points + ( sizeof points / sizeof(int) ) ), vector <int>( skills, skills + ( sizeof skills / sizeof(int) ) ), luck ) );
      }
*/
/*
      case 7: {
         int points[]              = ;
         int skills[]              = ;
         int luck                  = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, SRMCodingPhase().countScore( vector <int>( points, points + ( sizeof points / sizeof(int) ) ), vector <int>( skills, skills + ( sizeof skills / sizeof(int) ) ), luck ) );
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
