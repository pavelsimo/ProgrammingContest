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


class CCipher {
public:
   string decode( string s, int shift ) {
      string res = ""; 
      for(int i = 0; i < s.size(); ++i) {
         char ch = ((s[i]-'A' + 26 - shift)%26)+'A';
         res+=ch;
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
         string cipherText         = "VQREQFGT";
         int shift                 = 2;
         string expected__         = "TOPCODER";

         return verify_case( casenum__, starttime__, expected__, CCipher().decode( cipherText, shift ) );
      }
      case 1: {
         string cipherText         = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
         int shift                 = 10;
         string expected__         = "QRSTUVWXYZABCDEFGHIJKLMNOP";

         return verify_case( casenum__, starttime__, expected__, CCipher().decode( cipherText, shift ) );
      }
      case 2: {
         string cipherText         = "TOPCODER";
         int shift                 = 0;
         string expected__         = "TOPCODER";

         return verify_case( casenum__, starttime__, expected__, CCipher().decode( cipherText, shift ) );
      }
      case 3: {
         string cipherText         = "ZWBGLZ";
         int shift                 = 25;
         string expected__         = "AXCHMA";

         return verify_case( casenum__, starttime__, expected__, CCipher().decode( cipherText, shift ) );
      }
      case 4: {
         string cipherText         = "DBNPCBQ";
         int shift                 = 1;
         string expected__         = "CAMOBAP";

         return verify_case( casenum__, starttime__, expected__, CCipher().decode( cipherText, shift ) );
      }
      case 5: {
         string cipherText         = "LIPPSASVPH";
         int shift                 = 4;
         string expected__         = "HELLOWORLD";

         return verify_case( casenum__, starttime__, expected__, CCipher().decode( cipherText, shift ) );
      }

      // custom cases

/*
      case 6: {
         string cipherText         = ;
         int shift                 = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, CCipher().decode( cipherText, shift ) );
      }
*/
/*
      case 7: {
         string cipherText         = ;
         int shift                 = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, CCipher().decode( cipherText, shift ) );
      }
*/
/*
      case 8: {
         string cipherText         = ;
         int shift                 = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, CCipher().decode( cipherText, shift ) );
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
