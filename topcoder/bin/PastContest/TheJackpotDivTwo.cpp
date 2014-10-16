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


class TheJackpotDivTwo {
public:
   vector <int> find( vector <int> money, int jackpot ) {
      while(jackpot > 0) {
         int i = min_element(all(money)) - money.begin();
         money[i]++;
         jackpot--;
      }
      sort(all(money));
      return money;
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
   
   template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) {
      os << "{";
      for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) {
         if ( vi != v.begin() ) os << ",";
         os << " " << *vi;
      }
      os << " }";
      return os;
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
   int verify_case( int casenum, long long starttime, const vector <int> &expected, const vector <int> &received ) {
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
         int money[]               = {1, 2, 3, 4};
         int jackpot               = 2;
         int expected__[]          = {2, 3, 3, 4 };

         return verify_case( casenum__, starttime__, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof(int) ) ), TheJackpotDivTwo().find( vector <int>( money, money + ( sizeof money / sizeof(int) ) ), jackpot ) );
      }
      case 1: {
         int money[]               = {4, 7};
         int jackpot               = 1;
         int expected__[]          = {5, 7 };

         return verify_case( casenum__, starttime__, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof(int) ) ), TheJackpotDivTwo().find( vector <int>( money, money + ( sizeof money / sizeof(int) ) ), jackpot ) );
      }
      case 2: {
         int money[]               = {1};
         int jackpot               = 100;
         int expected__[]          = {101 };

         return verify_case( casenum__, starttime__, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof(int) ) ), TheJackpotDivTwo().find( vector <int>( money, money + ( sizeof money / sizeof(int) ) ), jackpot ) );
      }
      case 3: {
         int money[]               = {21, 85, 6, 54, 70, 100, 91, 60, 71};
         int jackpot               = 15;
         int expected__[]          = {21, 21, 54, 60, 70, 71, 85, 91, 100 };

         return verify_case( casenum__, starttime__, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof(int) ) ), TheJackpotDivTwo().find( vector <int>( money, money + ( sizeof money / sizeof(int) ) ), jackpot ) );
      }

      // custom cases

/*
      case 4: {
         int money[]               = ;
         int jackpot               = ;
         int expected__[]          = ;

         return verify_case( casenum__, starttime__, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof(int) ) ), TheJackpotDivTwo().find( vector <int>( money, money + ( sizeof money / sizeof(int) ) ), jackpot ) );
      }
*/
/*
      case 5: {
         int money[]               = ;
         int jackpot               = ;
         int expected__[]          = ;

         return verify_case( casenum__, starttime__, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof(int) ) ), TheJackpotDivTwo().find( vector <int>( money, money + ( sizeof money / sizeof(int) ) ), jackpot ) );
      }
*/
/*
      case 6: {
         int money[]               = ;
         int jackpot               = ;
         int expected__[]          = ;

         return verify_case( casenum__, starttime__, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof(int) ) ), TheJackpotDivTwo().find( vector <int>( money, money + ( sizeof money / sizeof(int) ) ), jackpot ) );
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
