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


class TheJediTestDiv2 {
public:
   int countSupervisors( vector <int> S, int Y, int J ) {
      int res = 100000002;
      for(int i = 0; i < sz(S); ++i) {
         vector<int> t(all(S));
         int jediCnt = 0;
         for(int j = 0; j < sz(S); ++j) {
            int x;
            if(j == i) {
               t[j] = max(0, t[j] - Y);
               x = t[j] / J;
               jediCnt += x;
               t[j] -= x * J;
            } else {
               x = t[j] / J;
               t[j] -= x * J;
               jediCnt += x;
            }
            if(t[j] > 0) jediCnt++;
         }
         res = min(res, jediCnt);
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
         int students[]            = {10, 15};
         int Y                     = 12;
         int J                     = 5;
         int expected__            = 3;

         return verify_case( casenum__, starttime__, expected__, TheJediTestDiv2().countSupervisors( vector <int>( students, students + ( sizeof students / sizeof(int) ) ), Y, J ) );
      }
      case 1: {
         int students[]            = {11, 13, 15};
         int Y                     = 9;
         int J                     = 5;
         int expected__            = 7;

         return verify_case( casenum__, starttime__, expected__, TheJediTestDiv2().countSupervisors( vector <int>( students, students + ( sizeof students / sizeof(int) ) ), Y, J ) );
      }
      case 2: {
         int students[]            = {10};
         int Y                     = 100;
         int J                     = 2;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, TheJediTestDiv2().countSupervisors( vector <int>( students, students + ( sizeof students / sizeof(int) ) ), Y, J ) );
      }
      case 3: {
         int students[]            = {0, 0, 0, 0, 0};
         int Y                     = 145;
         int J                     = 21;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, TheJediTestDiv2().countSupervisors( vector <int>( students, students + ( sizeof students / sizeof(int) ) ), Y, J ) );
      }
      case 4: {
         int students[]            = {4, 7, 10, 5, 6, 55, 2};
         int Y                     = 20;
         int J                     = 3;
         int expected__            = 26;

         return verify_case( casenum__, starttime__, expected__, TheJediTestDiv2().countSupervisors( vector <int>( students, students + ( sizeof students / sizeof(int) ) ), Y, J ) );
      }

      // custom cases

/*
      case 5: {
         int students[]            = ;
         int Y                     = ;
         int J                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, TheJediTestDiv2().countSupervisors( vector <int>( students, students + ( sizeof students / sizeof(int) ) ), Y, J ) );
      }
*/
/*
      case 6: {
         int students[]            = ;
         int Y                     = ;
         int J                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, TheJediTestDiv2().countSupervisors( vector <int>( students, students + ( sizeof students / sizeof(int) ) ), Y, J ) );
      }
*/
/*
      case 7: {
         int students[]            = ;
         int Y                     = ;
         int J                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, TheJediTestDiv2().countSupervisors( vector <int>( students, students + ( sizeof students / sizeof(int) ) ), Y, J ) );
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
