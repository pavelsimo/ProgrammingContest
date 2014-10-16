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

typedef long long llong;
const int MAXN = 31;

class LittleElephantAndXor {
public:
   
   vector<int> da, db, dc;
   llong memo[MAXN + 1][2][2][2];
   
   vector<int> to_int_vector(int x) {
      vector<int> res(MAXN);
      for(int i = 0; i < MAXN; ++i) {
         res[i] = ((x & (1 << i)) != 0);
      }
      return res;
   }
   
   llong rec(int i, int eqA, int eqB, int eqC) {
      if(i == 0) 
         return 1LL;
      if(memo[i][eqA][eqB][eqC] != -1) 
         return memo[i][eqA][eqB][eqC];
      llong res = 0LL;
      for(int x = 0; x <= 1; ++x) {
         for(int y = 0; y <= 1; ++y) {
            int z = x ^ y;
            if((!eqA || (x <= da[i-1])) &&
               (!eqB || (y <= db[i-1])) &&
               (!eqC || (z <= dc[i-1]))) {
                  res += rec(i - 1, 
                             eqA && x == da[i-1],
                             eqB && y == db[i-1],
                             eqC && z == dc[i-1]);
               }
         }
      }
      return memo[i][eqA][eqB][eqC] = res;
   }
   
   long long getNumber( int A, int B, int C ) {
      llong res = 0LL;
      da = to_int_vector(A);
      db = to_int_vector(B);
      dc = to_int_vector(C);
      memset(memo, -1, sizeof(memo));
      res = rec(MAXN, 1, 1, 1);
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
   int verify_case( int casenum, long long starttime, const long long &expected, const long long &received ) {
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
         int A                     = 2;
         int B                     = 2;
         int C                     = 1;
         long long expected__      = 5LL;

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndXor().getNumber( A, B, C ) );
      }
      case 1: {
         int A                     = 4;
         int B                     = 7;
         int C                     = 3;
         long long expected__      = 20LL;

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndXor().getNumber( A, B, C ) );
      }
      case 2: {
         int A                     = 10;
         int B                     = 10;
         int C                     = 5;
         long long expected__      = 57LL;

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndXor().getNumber( A, B, C ) );
      }
      case 3: {
         int A                     = 774;
         int B                     = 477;
         int C                     = 447;
         long long expected__      = 214144LL;

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndXor().getNumber( A, B, C ) );
      }
      case 4: {
         int A                     = 1000000000;
         int B                     = 1000000000;
         int C                     = 500000000;
         long long expected__      = 468566946385621507LL;

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndXor().getNumber( A, B, C ) );
      }

      // custom cases

/*
      case 5: {
         int A                     = ;
         int B                     = ;
         int C                     = ;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndXor().getNumber( A, B, C ) );
      }
*/
/*
      case 6: {
         int A                     = ;
         int B                     = ;
         int C                     = ;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndXor().getNumber( A, B, C ) );
      }
*/
/*
      case 7: {
         int A                     = ;
         int B                     = ;
         int C                     = ;
         long long expected__      = LL;

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndXor().getNumber( A, B, C ) );
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
