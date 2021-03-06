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
const int INF = 100000000;
vector<string> P;
int memo[52][10002];
int next[7];


class MysteriousRestaurant {
public:

   int getPrice(char ch) {
      if(ch >= '0' && ch <= '9') return ch-'0';
      if(ch >= 'A' && ch <= 'Z') return ch-'A'+10;
      return ch-'a'+36;
   }
   
   int doit(int i, int budget) {
      if(i >= N) return 0;
      int d = i%7;
      if(i > 6 && next[d] < 0) 
         return 0;
      int res = 0;
      if(next[d]>=0) {
         int x = getPrice(P[i][next[d]]);
         if(budget >= x)
            res = max(res,doit(i+1,budget-x) + 1);
      } else {
         for(int k = 0; k < M; ++k) {
            int x = getPrice(P[i][k]);
            if(budget >= x) {
               next[d] = k;
               res = max(res,doit(i+1,budget-x) + 1);
               next[d] = -1;
            }            
         }
      }
      return res;
   }

   int maxDays( vector <string> prices, int budget ) {
      int res = 0;
      memset(next,-1,sizeof(next));
      memset(memo,-1,sizeof(memo));
      P = prices;
      N = sz(prices);
      M = sz(prices[0]);
      res = doit(0,budget);
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
         string prices[]           = {"26", "14", "72", "39", "32", "85", "06"};
         int budget                = 13;
         int expected__            = 5;

         return verify_case( casenum__, starttime__, expected__, MysteriousRestaurant().maxDays( vector <string>( prices, prices + ( sizeof prices / sizeof(string) ) ), budget ) );
      }
      case 1: {
         string prices[]           = {"26", "14", "72", "39", "32", "85", "06", "91"};
         int budget                = 20;
         int expected__            = 8;

         return verify_case( casenum__, starttime__, expected__, MysteriousRestaurant().maxDays( vector <string>( prices, prices + ( sizeof prices / sizeof(string) ) ), budget ) );
      }
      case 2: {
         string prices[]           = {"SRM", "512"};
         int budget                = 4;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, MysteriousRestaurant().maxDays( vector <string>( prices, prices + ( sizeof prices / sizeof(string) ) ), budget ) );
      }
      case 3: {
         string prices[]           = {"Dear", "Code", "rsHa", "veFu", "nInT", "heCh", "alle", "ngeP", "hase", "andb", "ecar", "eful"};
         int budget                = 256;
         int expected__            = 10;

         return verify_case( casenum__, starttime__, expected__, MysteriousRestaurant().maxDays( vector <string>( prices, prices + ( sizeof prices / sizeof(string) ) ), budget ) );
      }

      // custom cases

/*
      case 4: {
         string prices[]           = ;
         int budget                = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, MysteriousRestaurant().maxDays( vector <string>( prices, prices + ( sizeof prices / sizeof(string) ) ), budget ) );
      }
*/
/*
      case 5: {
         string prices[]           = ;
         int budget                = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, MysteriousRestaurant().maxDays( vector <string>( prices, prices + ( sizeof prices / sizeof(string) ) ), budget ) );
      }
*/
/*
      case 6: {
         string prices[]           = ;
         int budget                = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, MysteriousRestaurant().maxDays( vector <string>( prices, prices + ( sizeof prices / sizeof(string) ) ), budget ) );
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
