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

string player[] = {"Alice", "Bob"};
int freq[55];
class RowAndManyCoins {
public:
   string getWinner( string cells ) {
      memset(freq,0,sizeof(freq));
      char prev = cells[0];
      freq[0] = 1;
      for(int i = 1; i < sz(cells); ++i) {
         if(cells[i] == prev) freq[i] = freq[i - 1] + 1;
         else freq[i] = 1;
         prev = cells[i];
      }
      int cnt[2];
      cnt[0] = cnt[1] = 0;
      for(int i = 0; i < sz(cells); ++i) {
         if(freq[i + 1] <= freq[i]) {
            if(cells[i] == 'A') cnt[0]++;
            else cnt[1]++;
         }
      }
      return cnt[0]>=cnt[1] ? player[0]: player[1];
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
         string cells              = "ABBB";
         string expected__         = "Alice";

         return verify_case( casenum__, starttime__, expected__, RowAndManyCoins().getWinner( cells ) );
      }
      case 1: {
         string cells              = "BBBB";
         string expected__         = "Bob";

         return verify_case( casenum__, starttime__, expected__, RowAndManyCoins().getWinner( cells ) );
      }
      case 2: {
         string cells              = "BA";
         string expected__         = "Alice";

         return verify_case( casenum__, starttime__, expected__, RowAndManyCoins().getWinner( cells ) );
      }
      case 3: {
         string cells              = "BABBABBB";
         string expected__         = "Bob";

         return verify_case( casenum__, starttime__, expected__, RowAndManyCoins().getWinner( cells ) );
      }
      case 4: {
         string cells              = "ABABBBABAABBAA";
         string expected__         = "Alice";

         return verify_case( casenum__, starttime__, expected__, RowAndManyCoins().getWinner( cells ) );
      }
      case 5: {
         string cells              = "BBBAAABBAAABBB";
         string expected__         = "Bob";

         return verify_case( casenum__, starttime__, expected__, RowAndManyCoins().getWinner( cells ) );
      }

      // custom cases


      case 6: {
         string cells              = "BABB";
         string expected__         = "Bob";

         return verify_case( casenum__, starttime__, expected__, RowAndManyCoins().getWinner( cells ) );
      }


      case 7: {
         string cells              = "ABAAB";
         string expected__         = "Alice";

         return verify_case( casenum__, starttime__, expected__, RowAndManyCoins().getWinner( cells ) );
      }


      case 8: {
         string cells              = "BABBB";
         string expected__         = "Bob";

         return verify_case( casenum__, starttime__, expected__, RowAndManyCoins().getWinner( cells ) );
      }

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
