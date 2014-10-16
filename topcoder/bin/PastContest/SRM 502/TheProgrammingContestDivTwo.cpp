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
#define pb push_back


class TheProgrammingContestDivTwo {
public:

   // O(n)
   vector <int> find( int T, vector <int> requiredTime ) {
      vector<int> res;
      int solved = 0, penality = 0, time = 0, n = sz(requiredTime);
      sort(all(requiredTime));
      for(int i = 0; i < n; ++i) {
           time+=requiredTime[i];
           if(time <= T) {
               solved++;
               penality+=time; 
           }
      }
      res.push_back(solved);
      res.push_back(penality);
      return res;
   }

   // O(n^2)
   /*
   vector <int> find( int T, vector <int> requiredTime ) {
      vector<int> res, a;
      int score = 0;
      int penality = 0;
      int n = sz(requiredTime);
      sort(all(requiredTime));
      for(int i = n-1; i >= 0; --i) {
         int time = 0;
         int p = 0;
         for(int j = 0; j < n-i; ++j) {
            time+=requiredTime[j];
            p+=time;
         }
         if(time <= T) {
            score = n-i;
            penality = p;
         }
      }
      res.push_back(score);
      res.push_back(penality);
      return res;
   }
   */
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
         int T                     = 74;
         int requiredTime[]        = {47};
         int expected__[]          = {1, 47 };

         return verify_case( casenum__, starttime__, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof(int) ) ), TheProgrammingContestDivTwo().find( T, vector <int>( requiredTime, requiredTime + ( sizeof requiredTime / sizeof(int) ) ) ) );
      }
      case 1: {
         int T                     = 74;
         int requiredTime[]        = {4747};
         int expected__[]          = {0, 0 };

         return verify_case( casenum__, starttime__, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof(int) ) ), TheProgrammingContestDivTwo().find( T, vector <int>( requiredTime, requiredTime + ( sizeof requiredTime / sizeof(int) ) ) ) );
      }
      case 2: {
         int T                     = 47;
         int requiredTime[]        = {8, 5};
         int expected__[]          = {2, 18 };

         return verify_case( casenum__, starttime__, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof(int) ) ), TheProgrammingContestDivTwo().find( T, vector <int>( requiredTime, requiredTime + ( sizeof requiredTime / sizeof(int) ) ) ) );
      }
      case 3: {
         int T                     = 47;
         int requiredTime[]        = {12, 3, 21, 6, 4, 13};
         int expected__[]          = {5, 86 };

         return verify_case( casenum__, starttime__, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof(int) ) ), TheProgrammingContestDivTwo().find( T, vector <int>( requiredTime, requiredTime + ( sizeof requiredTime / sizeof(int) ) ) ) );
      }
      case 4: {
         int T                     = 58;
         int requiredTime[]        = {4, 5, 82, 3, 4, 65, 7, 6, 8, 7, 6, 4, 8, 7, 6, 37, 8};
         int expected__[]          = {10, 249 };

         return verify_case( casenum__, starttime__, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof(int) ) ), TheProgrammingContestDivTwo().find( T, vector <int>( requiredTime, requiredTime + ( sizeof requiredTime / sizeof(int) ) ) ) );
      }
      case 5: {
         int T                     = 100000;
         int requiredTime[]        = {100000};
         int expected__[]          = {1, 100000 };

         return verify_case( casenum__, starttime__, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof(int) ) ), TheProgrammingContestDivTwo().find( T, vector <int>( requiredTime, requiredTime + ( sizeof requiredTime / sizeof(int) ) ) ) );
      }

      // custom cases

/*
      case 6: {
         int T                     = ;
         int requiredTime[]        = ;
         int expected__[]          = ;

         return verify_case( casenum__, starttime__, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof(int) ) ), TheProgrammingContestDivTwo().find( T, vector <int>( requiredTime, requiredTime + ( sizeof requiredTime / sizeof(int) ) ) ) );
      }
*/
/*
      case 7: {
         int T                     = ;
         int requiredTime[]        = ;
         int expected__[]          = ;

         return verify_case( casenum__, starttime__, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof(int) ) ), TheProgrammingContestDivTwo().find( T, vector <int>( requiredTime, requiredTime + ( sizeof requiredTime / sizeof(int) ) ) ) );
      }
*/
/*
      case 8: {
         int T                     = ;
         int requiredTime[]        = ;
         int expected__[]          = ;

         return verify_case( casenum__, starttime__, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof(int) ) ), TheProgrammingContestDivTwo().find( T, vector <int>( requiredTime, requiredTime + ( sizeof requiredTime / sizeof(int) ) ) ) );
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
