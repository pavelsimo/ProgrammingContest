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
#define pb push_back

typedef vector<int> VI;
typedef vector<VI> VVI;

class NinePuzzle {
public:

   int getMinimumCost( string init, string goal ) {
      VVI B(10);
      B[0].pb(1); B[0].pb(2);
      B[1].pb(0); B[1].pb(2); B[1].pb(3); B[1].pb(4);
      B[2].pb(0); B[2].pb(1); B[2].pb(4); B[2].pb(5);
      B[3].pb(1); B[3].pb(4); B[3].pb(6); B[3].pb(7);
      B[4].pb(1); B[4].pb(2); B[4].pb(3); B[4].pb(5); B[4].pb(7); B[4].pb(8);
      B[5].pb(2); B[5].pb(4); B[5].pb(8); B[5].pb(9);
      B[6].pb(3); B[6].pb(7);
      B[7].pb(3); B[7].pb(4); B[7].pb(6); B[7].pb(8);
      B[8].pb(4); B[8].pb(5); B[8].pb(7); B[8].pb(9);
      B[9].pb(5); B[9].pb(8);      
      set<string> S;
      S.clear();
      int ans = 0x3f3f3f3f;
      int start = 0;
      for(int i = 0; i < sz(init); ++i) {
         if(init[i] == '*') 
            start = i;
      }
      queue<string> Q;
      Q.push(goal);
      S.insert(goal);
      while(!Q.empty()) {
         string cur = Q.front();
         Q.pop();
         if(cur[start]=='*') {
            int cnt = 0;
            for(int i = 0; i < sz(cur); ++i) {
               if(i != start && init[i]!=cur[i])
                  cnt++;   
            }
            ans = min(ans,cnt);
         }
         int cur_start = 0;
         for(int i = 0; i < sz(cur); ++i) {
            if(cur[i]=='*')
               cur_start = i;
         }
         for(int i = 0; i < sz(B[cur_start]); ++i) {
            swap(cur[cur_start],cur[B[cur_start][i]]);
            if(S.count(cur)==0) {
               Q.push(cur);
               S.insert(cur);
            }
            swap(cur[cur_start],cur[B[cur_start][i]]);
         }
      }
      return ans;
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
         string init               = "BG*YRGRRYR" ;
         string goal               = "BGGY*YRRRR" ;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, NinePuzzle().getMinimumCost( init, goal ) );
      }
      case 1: {
         string init               = "GBBB*BGBBG" ;
         string goal               = "RYYY*YRYYR";
         int expected__            = 9;

         return verify_case( casenum__, starttime__, expected__, NinePuzzle().getMinimumCost( init, goal ) );
      }
      case 2: {
         string init               = "RRBR*BRBBB" ;
         string goal               = "BBRB*RBRRR" ;
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, NinePuzzle().getMinimumCost( init, goal ) );
      }

      // custom cases

/*
      case 3: {
         string init               = ;
         string goal               = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, NinePuzzle().getMinimumCost( init, goal ) );
      }
*/
/*
      case 4: {
         string init               = ;
         string goal               = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, NinePuzzle().getMinimumCost( init, goal ) );
      }
*/
/*
      case 5: {
         string init               = ;
         string goal               = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, NinePuzzle().getMinimumCost( init, goal ) );
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
