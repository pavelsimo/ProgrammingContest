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

class LittleElephantAndDouble {
public:
   
   string getAnswer( vector<int> A) {
      int N = SZ(A);
      int prev = 0;
      for(int i = 0; i < N; ++i) {
         while(A[i] % 2 == 0) A[i] /= 2;  
         if(i > 0 && A[i] != prev) return "NO";
         prev = A[i];
      }
      return "YES";
   }
   
   string getAnswer2( vector <int> A ) {
      string ans = "YES";
      int N = SZ(A);
      sort(A.begin(), A.end());
      for(int i = 0; i < N - 1; ++i) {
         llong pow2 = 1LL;
         while(A[i] * pow2 < A[N-1])
            pow2*=2LL;
         if(A[i]*pow2 != A[N-1]) 
            return "NO";
      }
      return ans;
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
         int A[]                   = {1, 2};
         string expected__         = "YES";

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndDouble().getAnswer( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
      }
      case 1: {
         int A[]                   = {1, 2, 3};
         string expected__         = "NO";

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndDouble().getAnswer( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
      }
      case 2: {
         int A[]                   = {4, 8, 2, 1, 16};
         string expected__         = "YES";

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndDouble().getAnswer( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
      }
      case 3: {
         int A[]                   = {94, 752, 94, 376, 1504};
         string expected__         = "YES";

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndDouble().getAnswer( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
      }
      case 4: {
         int A[]                   = {148, 298, 1184};
         string expected__         = "NO";

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndDouble().getAnswer( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
      }
      case 5: {
         int A[]                   = {7, 7, 7, 7};
         string expected__         = "YES";

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndDouble().getAnswer( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
      }

      // custom cases

/*
      case 6: {
         int A[]                   = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndDouble().getAnswer( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
      }
*/
/*
      case 7: {
         int A[]                   = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndDouble().getAnswer( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
      }
*/
/*
      case 8: {
         int A[]                   = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, LittleElephantAndDouble().getAnswer( vector <int>( A, A + ( sizeof A / sizeof(int) ) ) ) );
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
