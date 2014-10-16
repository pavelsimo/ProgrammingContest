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

int freq[256];

class CatAndRabbit {
public:

   string getWinner( string s ) {
      memset(freq, 0, sizeof(freq));
      int cnt = 0;
      char prev = s[0];      
      for(int i = 0; i < sz(s); ++i) freq[(int)s[i]]++;
      if(freq['.'] == 0 || freq['#'] == 0) return "Rabbit";
      string s2 = "";
      for(int i = 0; i < sz(s); ++i) {
         if(i == 0 || s[i] != prev) 
            s2 += s[i];
         else {
            if(s[i] == '.') s2 += '.';
         }
         prev = s[i];
      }
      for(int i = 0; i < sz(s2); ++i) {
         if(s2[i] == '.') cnt++;
      }
      DEBUG(s2);
      DEBUG(s);
      DEBUG(cnt);
      return cnt % 2 == 0 ? "Rabbit" : "Cat";
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
         string tiles              = "#..";
         string expected__         = "Cat";

         return verify_case( casenum__, starttime__, expected__, CatAndRabbit().getWinner( tiles ) );
      }
      case 1: {
         string tiles              = ".#.";
         string expected__         = "Rabbit";

         return verify_case( casenum__, starttime__, expected__, CatAndRabbit().getWinner( tiles ) );
      }
      case 2: {
         string tiles              = "###";
         string expected__         = "Rabbit";

         return verify_case( casenum__, starttime__, expected__, CatAndRabbit().getWinner( tiles ) );
      }
      case 3: {
         string tiles              = "#..##.#";
         string expected__         = "Cat";

         return verify_case( casenum__, starttime__, expected__, CatAndRabbit().getWinner( tiles ) );
      }
      case 4: {
         string tiles              = "...";
         string expected__         = "Rabbit";

         return verify_case( casenum__, starttime__, expected__, CatAndRabbit().getWinner( tiles ) );
      }
      case 5: {
         string tiles              = "###...####....###...####....";
         string expected__         = "Rabbit";

         return verify_case( casenum__, starttime__, expected__, CatAndRabbit().getWinner( tiles ) );
      }

      // custom cases

/*
      case 6: {
         string tiles              = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, CatAndRabbit().getWinner( tiles ) );
      }
*/
/*
      case 7: {
         string tiles              = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, CatAndRabbit().getWinner( tiles ) );
      }
*/
/*
      case 8: {
         string tiles              = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, CatAndRabbit().getWinner( tiles ) );
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
