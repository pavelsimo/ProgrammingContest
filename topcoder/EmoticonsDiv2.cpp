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
#define FOREACH(it,c) for(__typeof__((c).begin()) it=(c).begin();it!=(c).end();++it)


class EmoticonsDiv2 {
public:
   
   int bfs(int dst) {
      queue<pair<int, pair<int, int> > > Q;
      Q.push(make_pair(1, make_pair(0, 0)));
      while(!Q.empty()) {
         pair<int,pair<int, int> > cur = Q.front();
         int csmiles = cur.first;
         int ctime = cur.second.first;
         int cclipboard = cur.second.second;
         Q.pop();
         if(csmiles > dst) continue;
         if(csmiles == dst) return ctime;
         Q.push(make_pair(2*csmiles, make_pair(ctime + 2, csmiles)));
         if(cclipboard > 0) Q.push(make_pair(csmiles + cclipboard, make_pair(ctime + 1, cclipboard)));
      }
      return -1;
   }

   int printSmiles( int smiles ) {
      int res = bfs(smiles);
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
         int smiles                = 2;
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, EmoticonsDiv2().printSmiles( smiles ) );
      }
      case 1: {
         int smiles                = 6;
         int expected__            = 5;

         return verify_case( casenum__, starttime__, expected__, EmoticonsDiv2().printSmiles( smiles ) );
      }
      case 2: {
         int smiles                = 11;
         int expected__            = 11;

         return verify_case( casenum__, starttime__, expected__, EmoticonsDiv2().printSmiles( smiles ) );
      }
      case 3: {
         int smiles                = 16;
         int expected__            = 8;

         return verify_case( casenum__, starttime__, expected__, EmoticonsDiv2().printSmiles( smiles ) );
      }
      case 4: {
         int smiles                = 1000;
         int expected__            = 21;

         return verify_case( casenum__, starttime__, expected__, EmoticonsDiv2().printSmiles( smiles ) );
      }

      // custom cases

/*
      case 5: {
         int smiles                = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, EmoticonsDiv2().printSmiles( smiles ) );
      }
*/
/*
      case 6: {
         int smiles                = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, EmoticonsDiv2().printSmiles( smiles ) );
      }
*/
/*
      case 7: {
         int smiles                = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, EmoticonsDiv2().printSmiles( smiles ) );
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
