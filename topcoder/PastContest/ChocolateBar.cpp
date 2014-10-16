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

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

int freq[26];

class ChocolateBar {
public:

   // O(n + n)
   int maxLength2( string s ) {
      memset(freq, 0, sizeof(freq));
      int res = 0;
      int lo = 0, hi = 0;
      while(hi < sz(s)) {
         freq[s[hi]-'a']++;
         while(freq[s[hi]-'a'] >= 2) {
            freq[s[lo]-'a']--;
            lo++;
         }
         res = max(res, hi - lo + 1);
         hi++;
      }
      return res;
   }

   // O(n^3)
   int maxLength( string s ) {
      int res = 0;
      for(int i = 0; i < sz(s); ++i) {
         for(int j = i; j < sz(s); ++j) {
            memset(freq, 0, sizeof(freq));
            bool ok = true;
            for(int k = i; k <= j; ++k) {
               freq[s[k]-'a']++;
               if(freq[s[k]-'a'] >= 2) {
                  ok = false;
                  break;
               }
            }
            if(ok)
               res = max(res, j - i + 1);
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
         string letters            = "srm";
         int expected__            = 3;

         return verify_case( casenum__, starttime__, expected__, ChocolateBar().maxLength( letters ) );
      }
      case 1: {
         string letters            = "dengklek";
         int expected__            = 6;

         return verify_case( casenum__, starttime__, expected__, ChocolateBar().maxLength( letters ) );
      }
      case 2: {
         string letters            = "haha";
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, ChocolateBar().maxLength( letters ) );
      }
      case 3: {
         string letters            = "www";
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, ChocolateBar().maxLength( letters ) );
      }
      case 4: {
         string letters            = "thisisansrmbeforetopcoderopenfinals";
         int expected__            = 9;

         return verify_case( casenum__, starttime__, expected__, ChocolateBar().maxLength( letters ) );
      }

      // custom cases

/*
      case 5: {
         string letters            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, ChocolateBar().maxLength( letters ) );
      }
*/
/*
      case 6: {
         string letters            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, ChocolateBar().maxLength( letters ) );
      }
*/
/*
      case 7: {
         string letters            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, ChocolateBar().maxLength( letters ) );
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
