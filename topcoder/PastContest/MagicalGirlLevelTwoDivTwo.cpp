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

int dx[] = {+1,+1,-1,-1};
int dy[] = {+1,-1,+1,-1};
bool seen[200][200];
vector<int> J;

class MagicalGirlLevelTwoDivTwo {
public:
   string bfs(int x, int y) {
      queue<PII> Q;
      Q.push(PII(100,100));
      seen[100][100] = true;
      while(!Q.empty()) {
         PII cur = Q.front(); Q.pop();
         int cx = cur.first;
         int cy = cur.second;
         if(cx == x && cy == y) return "YES";
         for(int i = 0; i < sz(J); ++i) {
            for(int j = 0; j <= 1; ++j) {
               int ddx = j ? 1: J[i];
               int ddy = j ? J[i]: 1;
               for(int dir = 0; dir < 4; ++dir) {
                  int nx = cx + dx[dir]*ddx;
                  int ny = cy + dy[dir]*ddy;  
                  if(nx < 0 || nx >= 200 || ny < 0 || ny >= 200) continue;
                  if(!seen[nx][ny]) {
                     Q.push(PII(nx,ny));
                     seen[nx][ny] = true;
                  }
               }
            }  
         }
      }
      return "NO";
   }

   string isReachable( vector <int> jumpTypes, int x, int y ) {
      J = jumpTypes;
      memset(seen,false,sizeof(seen));
      string res = bfs(x + 100, y + 100);
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
   int verify_case( int casenum, long long starttime, const string &expected, const string &received ) {
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
         cerr << "    Expected: \"" << expected << "\"" << endl; 
         cerr << "    Received: \"" << received << "\"" << endl; 
         return 0;
      }
   }

   int run_test_case( int casenum__ ) {
      long long starttime__ = get_time();
      switch( casenum__ ) {
      case 0: {
         int jumpTypes[]           = {2};
         int x                     = 5;
         int y                     = 4;
         string expected__         = "YES";

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelTwoDivTwo().isReachable( vector <int>( jumpTypes, jumpTypes + ( sizeof jumpTypes / sizeof(int) ) ), x, y ) );
      }
      case 1: {
         int jumpTypes[]           = {3};
         int x                     = 5;
         int y                     = 4;
         string expected__         = "NO";

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelTwoDivTwo().isReachable( vector <int>( jumpTypes, jumpTypes + ( sizeof jumpTypes / sizeof(int) ) ), x, y ) );
      }
      case 2: {
         int jumpTypes[]           = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
         int x                     = -30;
         int y                     = 27;
         string expected__         = "YES";

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelTwoDivTwo().isReachable( vector <int>( jumpTypes, jumpTypes + ( sizeof jumpTypes / sizeof(int) ) ), x, y ) );
      }
      case 3: {
         int jumpTypes[]           = {29};
         int x                     = 29;
         int y                     = 0;
         string expected__         = "NO";

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelTwoDivTwo().isReachable( vector <int>( jumpTypes, jumpTypes + ( sizeof jumpTypes / sizeof(int) ) ), x, y ) );
      }

      // custom cases


      case 4: {
         int jumpTypes[]           = {24, 28, 10, 14, 22, 16};
         int x                     = 3;
         int y                     = -5;
         string expected__         = "YES";

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelTwoDivTwo().isReachable( vector <int>( jumpTypes, jumpTypes + ( sizeof jumpTypes / sizeof(int) ) ), x, y ) );
      }

/*
      case 5: {
         int jumpTypes[]           = ;
         int x                     = ;
         int y                     = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelTwoDivTwo().isReachable( vector <int>( jumpTypes, jumpTypes + ( sizeof jumpTypes / sizeof(int) ) ), x, y ) );
      }
*/
/*
      case 6: {
         int jumpTypes[]           = ;
         int x                     = ;
         int y                     = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, MagicalGirlLevelTwoDivTwo().isReachable( vector <int>( jumpTypes, jumpTypes + ( sizeof jumpTypes / sizeof(int) ) ), x, y ) );
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
