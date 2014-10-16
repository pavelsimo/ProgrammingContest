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


class RollingDiceDivTwo {
public:
   int minimumFaces( vector <string> rolls ) {
      int res = 0;
      int M = sz(rolls[0]);
      int N = sz(rolls);
      for(int i = 0; i < sz(rolls); ++i)
         sort(all(rolls[i]));
      for(int j = 0; j < M; ++j) {
         int hi = 0;
         for(int i = 0; i < N; ++i)
            hi = max(hi, rolls[i][j] - '0');
         res+=hi;
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
         string rolls[]            = {"137", "364", "115", "724"};
         int expected__            = 14;

         return verify_case( casenum__, starttime__, expected__, RollingDiceDivTwo().minimumFaces( vector <string>( rolls, rolls + ( sizeof rolls / sizeof(string) ) ) ) );
      }
      case 1: {
         string rolls[]            = {"1112", "1111", "1211", "1111"};
         int expected__            = 5;

         return verify_case( casenum__, starttime__, expected__, RollingDiceDivTwo().minimumFaces( vector <string>( rolls, rolls + ( sizeof rolls / sizeof(string) ) ) ) );
      }
      case 2: {
         string rolls[]            = {"24412", "56316", "66666", "45625"};
         int expected__            = 30;

         return verify_case( casenum__, starttime__, expected__, RollingDiceDivTwo().minimumFaces( vector <string>( rolls, rolls + ( sizeof rolls / sizeof(string) ) ) ) );
      }
      case 3: {
         string rolls[]            = {"931", "821", "156", "512", "129", "358", "555"};
         int expected__            = 19;

         return verify_case( casenum__, starttime__, expected__, RollingDiceDivTwo().minimumFaces( vector <string>( rolls, rolls + ( sizeof rolls / sizeof(string) ) ) ) );
      }
      case 4: {
         string rolls[]            = {"3", "7", "4", "2", "4"};
         int expected__            = 7;

         return verify_case( casenum__, starttime__, expected__, RollingDiceDivTwo().minimumFaces( vector <string>( rolls, rolls + ( sizeof rolls / sizeof(string) ) ) ) );
      }
      case 5: {
         string rolls[]            = {"281868247265686571829977999522", "611464285871136563343229916655", "716739845311113736768779647392", "779122814312329463718383927626", "571573431548647653632439431183", "547362375338962625957869719518", "539263489892486347713288936885", "417131347396232733384379841536"};
         int expected__            = 176;

         return verify_case( casenum__, starttime__, expected__, RollingDiceDivTwo().minimumFaces( vector <string>( rolls, rolls + ( sizeof rolls / sizeof(string) ) ) ) );
      }

      // custom cases

/*
      case 6: {
         string rolls[]            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, RollingDiceDivTwo().minimumFaces( vector <string>( rolls, rolls + ( sizeof rolls / sizeof(string) ) ) ) );
      }
*/
/*
      case 7: {
         string rolls[]            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, RollingDiceDivTwo().minimumFaces( vector <string>( rolls, rolls + ( sizeof rolls / sizeof(string) ) ) ) );
      }
*/
/*
      case 8: {
         string rolls[]            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, RollingDiceDivTwo().minimumFaces( vector <string>( rolls, rolls + ( sizeof rolls / sizeof(string) ) ) ) );
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
