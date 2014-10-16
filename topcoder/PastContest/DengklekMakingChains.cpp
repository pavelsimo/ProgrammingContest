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

bool nnn(string a) {
   return isdigit(a[0]) && isdigit(a[1]) && isdigit(a[2]);
}

bool xnx(string a) {
   return !isdigit(a[0]) && isdigit(a[1]) && !isdigit(a[2]);
}

bool xxx(string a) {
   return !isdigit(a[0]) && !isdigit(a[1]) && !isdigit(a[2]);
}

class DengklekMakingChains {
public:

   int maxBeauty( vector <string> chains ) {
      int res = 0;
      int x1 = 0;
      int x2 = 0;
      for(int i = 0; i < sz(chains); ++i) {
         if(xxx(chains[i])) continue;
         if(nnn(chains[i])) {
            res+=(chains[i][0]-'0')+(chains[i][1]-'0')+(chains[i][2]-'0'); 
         } else if(xnx(chains[i])) {
            x1 = max(x1, (chains[i][1]-'0'));
         } else {
            if(isdigit(chains[i][0])) {
               int t;
               if(isdigit(chains[i][1]))
                  t = (chains[i][0]-'0') + (chains[i][1]-'0');
               else
                  t = (chains[i][0]-'0');
               x2 = max(x2,t);
               for(int j = i + 1; j < sz(chains); ++j) {
                  if(xxx(chains[j]) || nnn(chains[j])) continue;
                  if(isdigit(chains[j][2]) && isdigit(chains[j][1]))
                     x2 = max(x2, t + (chains[j][2]-'0') + (chains[j][1]-'0'));
                  else if(isdigit(chains[j][2]))
                     x2 = max(x2, t + (chains[j][2]-'0'));
               }
            }
            if(isdigit(chains[i][2])) {
               int t;
               if(isdigit(chains[i][1]))
                  t = (chains[i][2]-'0') + (chains[i][1]-'0');
               else
                  t = (chains[i][2]-'0');
               x2 = max(x2,t);
               for(int j = i + 1; j < sz(chains); ++j) {
                  if(xxx(chains[j]) || nnn(chains[j])) continue;
                  if(isdigit(chains[j][0]) && isdigit(chains[j][1]))
                     x2 = max(x2, t + (chains[j][0]-'0') + (chains[j][1]-'0'));
                  else if(isdigit(chains[j][0]))
                     x2 = max(x2, t + (chains[j][0]-'0'));                             
               }               
            }
         }
      }
      return max(res + x2, x1); 
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
         string chains[]           = {".15", "7..", "402", "..3"};
         int expected__            = 19;

         return verify_case( casenum__, starttime__, expected__, DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof(string) ) ) ) );
      }
      case 1: {
         string chains[]           = {"..1", "7..", "567", "24.", "8..", "234"};
         int expected__            = 36;

         return verify_case( casenum__, starttime__, expected__, DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof(string) ) ) ) );
      }
      case 2: {
         string chains[]           = {"...", "..."};
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof(string) ) ) ) );
      }
      case 3: {
         string chains[]           = {"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"};
         int expected__            = 28;

         return verify_case( casenum__, starttime__, expected__, DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof(string) ) ) ) );
      }
      case 4: {
         string chains[]           = {"..1", "3..", "2..", ".7."};
         int expected__            = 7;

         return verify_case( casenum__, starttime__, expected__, DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof(string) ) ) ) );
      }
      case 5: {
         string chains[]           = {"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"};
         int expected__            = 58;

         return verify_case( casenum__, starttime__, expected__, DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof(string) ) ) ) );
      }

      // custom cases


      case 6: {
         string chains[]           = {"1.1","1.1"};
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof(string) ) ) ) );
      }


      case 7: {
         string chains[]           = {"4..", "244", "3.6", "193", ".4.", "8..", ".7.", "...", "...", "..5", "0.1"};
         int expected__            = 37;

         return verify_case( casenum__, starttime__, expected__, DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof(string) ) ) ) );
      }

/*
      case 8: {
         string chains[]           = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof(string) ) ) ) );
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
