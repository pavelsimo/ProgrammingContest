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

const int MAXN = 100002;
int D[100002];
int D2[100002]; // negative
const int INF = 1000000000;

class CubeRoll {
public:

   bool psq(int n) {
      int q = (int)ceil(sqrt(n));
      return q*q == n;
   }
   
   int getMinimumSteps( int initPos, int goalPos, vector <int> holePos ) {
      int res = -1;
      vector<int> squares;
      for(int i = 1; i*i <= 100000; ++i)
         squares.push_back(i*i);
      sort(all(holePos));
      for(int i = 0; i < sz(holePos); ++i) {
         if(holePos[i] >= initPos && holePos[i] <= goalPos) return -1;
         if(holePos[i] >= goalPos && holePos[i] <= initPos) return -1;
      }
      if(psq(abs(initPos-goalPos))) return 1; 
      int lo = -INF, hi = INF;
      if(initPos > holePos[sz(holePos)-1] && goalPos > holePos[sz(holePos)-1]) {
         lo = holePos[sz(holePos)-1];
         //hi = INF;
      } else if(initPos < holePos[0] && goalPos < holePos[0]) {
         //lo = -INF;
         hi = holePos[0];
      } else {
         for(int i = 0; i < sz(holePos)-1; ++i) {
            if(initPos > holePos[i] &&  goalPos < holePos[i+1]) {
               lo = holePos[i];
               hi = holePos[i+1];
               break;
            }
         }
      }
      queue<int> Q;
      Q.push(initPos);
      memset(D,-1,sizeof(D));
      D[initPos] = 0;
      DEBUG(initPos);
      DEBUG(goalPos);
      DEBUG(lo);
      DEBUG(hi);
      while(!Q.empty()) {
         int cur = Q.front(); Q.pop();
         //DEBUG(cur);
         if(cur==goalPos) 
            return D[cur];
         for(int i = 0; i < sz(squares); ++i) {
            int nxt = cur + squares[i];
            //printf("%d = %d - %d\n",nxt,cur,squares[i]);
            if(nxt > lo && nxt < hi && D[nxt]==-1) {
               D[nxt] = D[cur] + 1;
               Q.push(nxt);
            }
            nxt = cur - squares[i];
            //printf("%d = %d - %d\n",nxt,cur,squares[i]);
            if(nxt > lo && nxt < hi && D[nxt]==-1) {
               D[nxt] = D[cur] + 1;
               Q.push(nxt);
            }
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
         int initPos               = 5;
         int goalPos               = 1;
         int holePos[]             = {3};
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, CubeRoll().getMinimumSteps( initPos, goalPos, vector <int>( holePos, holePos + ( sizeof holePos / sizeof(int) ) ) ) );
      }
      case 1: {
         int initPos               = 36;
         int goalPos               = 72;
         int holePos[]             = {300, 100, 200, 400};
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, CubeRoll().getMinimumSteps( initPos, goalPos, vector <int>( holePos, holePos + ( sizeof holePos / sizeof(int) ) ) ) );
      }
      case 2: {
         int initPos               = 10;
         int goalPos               = 21;
         int holePos[]             = {38,45};
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, CubeRoll().getMinimumSteps( initPos, goalPos, vector <int>( holePos, holePos + ( sizeof holePos / sizeof(int) ) ) ) );
      }
      case 3: {
         int initPos               = 98765;
         int goalPos               = 4963;
         int holePos[]             = {10,20,40,30};
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, CubeRoll().getMinimumSteps( initPos, goalPos, vector <int>( holePos, holePos + ( sizeof holePos / sizeof(int) ) ) ) );
      }
      case 4: {
         int initPos               = 68332;
         int goalPos               = 825;
         int holePos[]             = {99726,371,67,89210};
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, CubeRoll().getMinimumSteps( initPos, goalPos, vector <int>( holePos, holePos + ( sizeof holePos / sizeof(int) ) ) ) );
      }

      // custom cases


      case 5: {
         int initPos               = 100;
         int goalPos               = 123;
         int holePos[]             = {99,124};
         int expected__            = 3;

         return verify_case( casenum__, starttime__, expected__, CubeRoll().getMinimumSteps( initPos, goalPos, vector <int>( holePos, holePos + ( sizeof holePos / sizeof(int) ) ) ) );
      }

/*
      case 6: {
         int initPos               = ;
         int goalPos               = ;
         int holePos[]             = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, CubeRoll().getMinimumSteps( initPos, goalPos, vector <int>( holePos, holePos + ( sizeof holePos / sizeof(int) ) ) ) );
      }
*/
/*
      case 7: {
         int initPos               = ;
         int goalPos               = ;
         int holePos[]             = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, CubeRoll().getMinimumSteps( initPos, goalPos, vector <int>( holePos, holePos + ( sizeof holePos / sizeof(int) ) ) ) );
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
