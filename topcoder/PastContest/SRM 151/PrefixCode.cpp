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

#define SZ(a) int((a).size())
#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)


class PrefixCode {
public:
   string isOne( vector <string> words ) {
      int k = -1;
      for(int i = 0; i < SZ(words); ++i) {
         string pattern = words[i];
         for(int j = 0; j < SZ(words); ++j) {
            if(i==j) continue;
            size_t pos;
            if((pos=words[j].find(pattern))!=string::npos) {
               if(pos==0) {
                  k = i;
                  break;
               }
            }
         }
         if(k>=0) break;
      }
      if(k<0) return "Yes";
      stringstream ss;
      ss << "No, " << k;
      return ss.str();
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
         string words[]            = {"trivial"};
         string expected__         = "Yes";

         return verify_case( casenum__, starttime__, expected__, PrefixCode().isOne( vector <string>( words, words + ( sizeof words / sizeof(string) ) ) ) );
      }
      case 1: {
         string words[]            = {"10001", "011", "100", "001", "10"};
         string expected__         = "No, 2";

         return verify_case( casenum__, starttime__, expected__, PrefixCode().isOne( vector <string>( words, words + ( sizeof words / sizeof(string) ) ) ) );
      }
      case 2: {
         string words[]            = {"no", "nosy", "neighbors", "needed"};
         string expected__         = "No, 0";

         return verify_case( casenum__, starttime__, expected__, PrefixCode().isOne( vector <string>( words, words + ( sizeof words / sizeof(string) ) ) ) );
      }
      case 3: {
         string words[]            = {"1010", "11", "100", "0", "1011"};
         string expected__         = "Yes";

         return verify_case( casenum__, starttime__, expected__, PrefixCode().isOne( vector <string>( words, words + ( sizeof words / sizeof(string) ) ) ) );
      }
      case 4: {
         string words[]            = {"No", "not"};
         string expected__         = "Yes";

         return verify_case( casenum__, starttime__, expected__, PrefixCode().isOne( vector <string>( words, words + ( sizeof words / sizeof(string) ) ) ) );
      }

      // custom cases

/*
      case 5: {
         string words[]            = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, PrefixCode().isOne( vector <string>( words, words + ( sizeof words / sizeof(string) ) ) ) );
      }
*/
/*
      case 6: {
         string words[]            = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, PrefixCode().isOne( vector <string>( words, words + ( sizeof words / sizeof(string) ) ) ) );
      }
*/
/*
      case 7: {
         string words[]            = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, PrefixCode().isOne( vector <string>( words, words + ( sizeof words / sizeof(string) ) ) ) );
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
