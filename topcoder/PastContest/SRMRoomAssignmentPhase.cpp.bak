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

typedef vector<int> VI;
typedef vector<VI> VVI;


class SRMRoomAssignmentPhase {
public:
   int countCompetitors( vector <int> ratings, int K ) {
      VVI rooms;
      int me = ratings[0];
      sort(ratings.rbegin(),ratings.rend());
      rooms = VVI(K + 1);
      for(int i = 0; i < sz(ratings); ++i) {
         int j, k;
         for(j = i, k = 0; k < K && j < sz(ratings); ++j, ++k)
            rooms[k].push_back(ratings[j]);
         i = j - 1;
      }
      for(int i = 0; i < sz(rooms); ++i) {
         for(int j = 0; j < sz(rooms[i]); ++j) {
            if(rooms[i][j] == me) 
               return j;
         }
      }
      return 0;
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
         int ratings[]             = {491, 981, 1199, 763, 994, 879, 888};
         int K                     = 3;
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, SRMRoomAssignmentPhase().countCompetitors( vector <int>( ratings, ratings + ( sizeof ratings / sizeof(int) ) ), K ) );
      }
      case 1: {
         int ratings[]             = {1024, 1000, 600};
         int K                     = 1;
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, SRMRoomAssignmentPhase().countCompetitors( vector <int>( ratings, ratings + ( sizeof ratings / sizeof(int) ) ), K ) );
      }
      case 2: {
         int ratings[]             = {505, 679, 900, 1022};
         int K                     = 2;
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, SRMRoomAssignmentPhase().countCompetitors( vector <int>( ratings, ratings + ( sizeof ratings / sizeof(int) ) ), K ) );
      }
      case 3: {
         int ratings[]             = {716, 58, 1000, 1004, 912, 822, 453, 1100, 558};
         int K                     = 3;
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, SRMRoomAssignmentPhase().countCompetitors( vector <int>( ratings, ratings + ( sizeof ratings / sizeof(int) ) ), K ) );
      }
      case 4: {
         int ratings[]             = {422, 623, 1023, 941, 882, 776, 852, 495, 803, 622, 618, 532, 751, 500};
         int K                     = 4;
         int expected__            = 3;

         return verify_case( casenum__, starttime__, expected__, SRMRoomAssignmentPhase().countCompetitors( vector <int>( ratings, ratings + ( sizeof ratings / sizeof(int) ) ), K ) );
      }
      case 5: {
         int ratings[]             = {1197, 1198, 1196, 1195, 1199};
         int K                     = 1;
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, SRMRoomAssignmentPhase().countCompetitors( vector <int>( ratings, ratings + ( sizeof ratings / sizeof(int) ) ), K ) );
      }

      // custom cases

/*
      case 6: {
         int ratings[]             = ;
         int K                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, SRMRoomAssignmentPhase().countCompetitors( vector <int>( ratings, ratings + ( sizeof ratings / sizeof(int) ) ), K ) );
      }
*/
/*
      case 7: {
         int ratings[]             = ;
         int K                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, SRMRoomAssignmentPhase().countCompetitors( vector <int>( ratings, ratings + ( sizeof ratings / sizeof(int) ) ), K ) );
      }
*/
/*
      case 8: {
         int ratings[]             = ;
         int K                     = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, SRMRoomAssignmentPhase().countCompetitors( vector <int>( ratings, ratings + ( sizeof ratings / sizeof(int) ) ), K ) );
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
