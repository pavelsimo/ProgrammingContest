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


class TwoRectangles {
public:

   bool checkSegment(int x1, int x2, int x3, int x4) {
      return (x3 > x1 && x3 < x2) || (x4 > x1 && x4 < x2);
   }

   string describeIntersection( vector <int> A, vector <int> B ) {
      int X[] = {0,2,2,0};
      int Y[] = {1,3,1,3};
      int N = 4;
      vector<pair<int,int> > pa, pb;
      for(int i = 0; i < N; ++i) {
         pa.push_back(make_pair(A[X[i]], A[Y[i]]));
         pb.push_back(make_pair(B[X[i]], B[Y[i]]));
      }
      for(int i = 0; i < N; ++i) {
         if(pb[i].first > A[0] && pb[i].first < A[2] && pb[i].second > A[1] && pb[i].second < A[3])
            return "rectangle";
         if(pa[i].first > B[0] && pa[i].first < B[2] && pa[i].second > B[1] && pa[i].second < B[3])
            return "rectangle";
      }
      for(int i = 1; i <= 3; i+=2) { 
         for(int j = 1; j <= 3; j+=2) {   
            if(A[i] == B[j] && checkSegment(A[0], A[2], B[0], B[2])) return "segment";      
            if(A[i] == B[j] && checkSegment(B[0], B[2], A[0], A[2])) return "segment";
         }
      }
      for(int i = 0; i <= 2; i+=2) {
         for(int j = 0; j <= 2; j+=2) {
            if(A[i] == B[j] && checkSegment(A[1], A[3], B[1], B[3])) return "segment";      
            if(A[i] == B[j] && checkSegment(B[1], B[3], A[1], A[3])) return "segment";
         }
      }
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < N; ++j) {   
            if(pa[i].first == pb[j].first && pa[i].second == pb[j].second) 
               return "point";
         }
      }
      return "none";
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
         int A[]                   = {0,0,3,2};
         int B[]                   = {1,1,5,3};
         string expected__         = "rectangle";

         return verify_case( casenum__, starttime__, expected__, TwoRectangles().describeIntersection( vector <int>( A, A + ( sizeof A / sizeof(int) ) ), vector <int>( B, B + ( sizeof B / sizeof(int) ) ) ) );
      }
      case 1: {
         int A[]                   = {0,0,5,3};
         int B[]                   = {1,2,2,3};
         string expected__         = "rectangle";

         return verify_case( casenum__, starttime__, expected__, TwoRectangles().describeIntersection( vector <int>( A, A + ( sizeof A / sizeof(int) ) ), vector <int>( B, B + ( sizeof B / sizeof(int) ) ) ) );
      }
      case 2: {
         int A[]                   = {1,1,6,2};
         int B[]                   = {3,2,5,4};
         string expected__         = "segment";

         return verify_case( casenum__, starttime__, expected__, TwoRectangles().describeIntersection( vector <int>( A, A + ( sizeof A / sizeof(int) ) ), vector <int>( B, B + ( sizeof B / sizeof(int) ) ) ) );
      }
      case 3: {
         int A[]                   = {0,1,2,3};
         int B[]                   = {2,0,5,2};
         string expected__         = "segment";

         return verify_case( casenum__, starttime__, expected__, TwoRectangles().describeIntersection( vector <int>( A, A + ( sizeof A / sizeof(int) ) ), vector <int>( B, B + ( sizeof B / sizeof(int) ) ) ) );
      }
      case 4: {
         int A[]                   = {0,0,1,1};
         int B[]                   = {1,1,5,2};
         string expected__         = "point";

         return verify_case( casenum__, starttime__, expected__, TwoRectangles().describeIntersection( vector <int>( A, A + ( sizeof A / sizeof(int) ) ), vector <int>( B, B + ( sizeof B / sizeof(int) ) ) ) );
      }
      case 5: {
         int A[]                   = {1,1,2,2};
         int B[]                   = {3,1,4,2};
         string expected__         = "none";

         return verify_case( casenum__, starttime__, expected__, TwoRectangles().describeIntersection( vector <int>( A, A + ( sizeof A / sizeof(int) ) ), vector <int>( B, B + ( sizeof B / sizeof(int) ) ) ) );
      }

      // custom cases

/*
      case 6: {
         int A[]                   = ;
         int B[]                   = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, TwoRectangles().describeIntersection( vector <int>( A, A + ( sizeof A / sizeof(int) ) ), vector <int>( B, B + ( sizeof B / sizeof(int) ) ) ) );
      }
*/
/*
      case 7: {
         int A[]                   = ;
         int B[]                   = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, TwoRectangles().describeIntersection( vector <int>( A, A + ( sizeof A / sizeof(int) ) ), vector <int>( B, B + ( sizeof B / sizeof(int) ) ) ) );
      }
*/
/*
      case 8: {
         int A[]                   = ;
         int B[]                   = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, TwoRectangles().describeIntersection( vector <int>( A, A + ( sizeof A / sizeof(int) ) ), vector <int>( B, B + ( sizeof B / sizeof(int) ) ) ) );
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
