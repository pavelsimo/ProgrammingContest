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


class KingdomReorganization {
public:
   int getCost( vector <string> kingdom, vector <string> build, vector <string> destroy ) {

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
         string kingdom[]          = {"000","000","000"};
         string build[]            = {"ABD","BAC","DCA"};
         string destroy[]          = {"ABD","BAC","DCA"};
         int expected__            = 3;

         return verify_case( casenum__, starttime__, expected__, KingdomReorganization().getCost( vector <string>( kingdom, kingdom + ( sizeof kingdom / sizeof(string) ) ), vector <string>( build, build + ( sizeof build / sizeof(string) ) ), vector <string>( destroy, destroy + ( sizeof destroy / sizeof(string) ) ) ) );
      }
      case 1: {
         string kingdom[]          = {"011","101","110"};
         string build[]            = {"ABD","BAC","DCA"};
         string destroy[]          = {"ABD","BAC","DCA"};
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, KingdomReorganization().getCost( vector <string>( kingdom, kingdom + ( sizeof kingdom / sizeof(string) ) ), vector <string>( build, build + ( sizeof build / sizeof(string) ) ), vector <string>( destroy, destroy + ( sizeof destroy / sizeof(string) ) ) ) );
      }
      case 2: {
         string kingdom[]          = {"011000","101000","110000","000011","000101","000110"};
         string build[]            = {"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"};
         string destroy[]          = {"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"};
         int expected__            = 7;

         return verify_case( casenum__, starttime__, expected__, KingdomReorganization().getCost( vector <string>( kingdom, kingdom + ( sizeof kingdom / sizeof(string) ) ), vector <string>( build, build + ( sizeof build / sizeof(string) ) ), vector <string>( destroy, destroy + ( sizeof destroy / sizeof(string) ) ) ) );
      }
      case 3: {
         string kingdom[]          = {"0"};
         string build[]            = {"A"};
         string destroy[]          = {"A"};
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, KingdomReorganization().getCost( vector <string>( kingdom, kingdom + ( sizeof kingdom / sizeof(string) ) ), vector <string>( build, build + ( sizeof build / sizeof(string) ) ), vector <string>( destroy, destroy + ( sizeof destroy / sizeof(string) ) ) ) );
      }
      case 4: {
         string kingdom[]          = {"0001","0001","0001","1110"};
         string build[]            = {"AfOj","fAcC","OcAP","jCPA"};
         string destroy[]          = {"AWFH","WAxU","FxAV","HUVA"};
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, KingdomReorganization().getCost( vector <string>( kingdom, kingdom + ( sizeof kingdom / sizeof(string) ) ), vector <string>( build, build + ( sizeof build / sizeof(string) ) ), vector <string>( destroy, destroy + ( sizeof destroy / sizeof(string) ) ) ) );
      }
      case 5: {
         string kingdom[]          = {"0000000000","0000000011","0001010000","0010010000","0000001000","0011000000","0000100000","0000000011","0100000101","0100000110"};
         string build[]            = {"AhPEqkSFMM","hAfKPtsDad","PfAyGQkaqN","EKyAeLpRpm","qPGeASfNwo","ktQLSAnCAK","SskpfnAdJS","FDaRNCdAZz","MaqpwAJZAn","MdNmoKSznA"};
         string destroy[]          = {"AgTqWWxEYH","gAXPgjzIRA","TXAleTmWvT","qPlAQkwxRO","WgeQAqgbJJ","WjTkqAiTzl","xzmwgiAuHb","EIWxbTuAwk","YRvRJzHwAn","HATOJlbknA"};
         int expected__            = 65;

         return verify_case( casenum__, starttime__, expected__, KingdomReorganization().getCost( vector <string>( kingdom, kingdom + ( sizeof kingdom / sizeof(string) ) ), vector <string>( build, build + ( sizeof build / sizeof(string) ) ), vector <string>( destroy, destroy + ( sizeof destroy / sizeof(string) ) ) ) );
      }

      // custom cases

/*
      case 6: {
         string kingdom[]          = ;
         string build[]            = ;
         string destroy[]          = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, KingdomReorganization().getCost( vector <string>( kingdom, kingdom + ( sizeof kingdom / sizeof(string) ) ), vector <string>( build, build + ( sizeof build / sizeof(string) ) ), vector <string>( destroy, destroy + ( sizeof destroy / sizeof(string) ) ) ) );
      }
*/
/*
      case 7: {
         string kingdom[]          = ;
         string build[]            = ;
         string destroy[]          = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, KingdomReorganization().getCost( vector <string>( kingdom, kingdom + ( sizeof kingdom / sizeof(string) ) ), vector <string>( build, build + ( sizeof build / sizeof(string) ) ), vector <string>( destroy, destroy + ( sizeof destroy / sizeof(string) ) ) ) );
      }
*/
/*
      case 8: {
         string kingdom[]          = ;
         string build[]            = ;
         string destroy[]          = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, KingdomReorganization().getCost( vector <string>( kingdom, kingdom + ( sizeof kingdom / sizeof(string) ) ), vector <string>( build, build + ( sizeof build / sizeof(string) ) ), vector <string>( destroy, destroy + ( sizeof destroy / sizeof(string) ) ) ) );
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
