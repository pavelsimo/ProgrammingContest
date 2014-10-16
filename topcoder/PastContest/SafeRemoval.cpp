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


const int INF = 10000;
vector<int> x[4];
int memo[52][52][52][52];

int rec(int a, int b, int c, int d, int sum, int k) {
   if(k == 0) return sum;
   int &res = memo[a][b][c][d];
   if(res != 0) return res;
   res = -1;
   if(a < sz(x[0]) && (sum - x[0][a]) % 4) 
      res = max(res, rec(a+1, b, c, d, sum - x[0][a], k - 1));
   if(b < sz(x[1]) && (sum - x[1][b]) % 4) 
      res = max(res, rec(a, b+1, c, d, sum - x[1][b], k - 1));
   if(c < sz(x[2]) && (sum - x[2][c]) % 4) 
      res = max(res, rec(a, b, c+1, d, sum - x[2][c], k - 1));
   if(d < sz(x[3]) && (sum - x[3][d]) % 4) 
      res = max(res, rec(a, b, c, d+1, sum - x[3][d], k - 1));   
   return res;
}

class SafeRemoval {
public:

   int removeThem( vector <int> a, int k ) {
      memset(memo, 0, sizeof(memo));
      for(int i = 0; i < 4; ++i) x[i].clear();
      int sum = accumulate(all(a), 0);
      for(int i = 0; i < sz(a); ++i) x[a[i]%4].push_back(a[i]);
      for(int i = 0; i < 4; ++i) sort(all(x[i]));
      int res = rec(0,0,0,0,sum,k);
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
         int seq[]                 = {3, 8, 4};
         int k                     = 1;
         int expected__            = 11;

         return verify_case( casenum__, starttime__, expected__, SafeRemoval().removeThem( vector <int>( seq, seq + ( sizeof seq / sizeof(int) ) ), k ) );
      }
      case 1: {
         int seq[]                 = {1,1,1,1,1,1};
         int k                     = 3;
         int expected__            = -1;

         return verify_case( casenum__, starttime__, expected__, SafeRemoval().removeThem( vector <int>( seq, seq + ( sizeof seq / sizeof(int) ) ), k ) );
      }
      case 2: {
         int seq[]                 = {1,6,1,10,1,2,7,11};
         int k                     = 6;
         int expected__            = 21;

         return verify_case( casenum__, starttime__, expected__, SafeRemoval().removeThem( vector <int>( seq, seq + ( sizeof seq / sizeof(int) ) ), k ) );
      }
      case 3: {
         int seq[]                 = {1,1,1,1,1,1,1,1,7};
         int k                     = 3;
         int expected__            = 6;

         return verify_case( casenum__, starttime__, expected__, SafeRemoval().removeThem( vector <int>( seq, seq + ( sizeof seq / sizeof(int) ) ), k ) );
      }

      // custom cases

/*
      case 4: {
         int seq[]                 = ;
         int k                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, SafeRemoval().removeThem( vector <int>( seq, seq + ( sizeof seq / sizeof(int) ) ), k ) );
      }
*/
/*
      case 5: {
         int seq[]                 = ;
         int k                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, SafeRemoval().removeThem( vector <int>( seq, seq + ( sizeof seq / sizeof(int) ) ), k ) );
      }
*/
/*
      case 6: {
         int seq[]                 = ;
         int k                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, SafeRemoval().removeThem( vector <int>( seq, seq + ( sizeof seq / sizeof(int) ) ), k ) );
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
