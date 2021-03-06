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


class CheatingQuiz {
public:

   vector <int> howMany( string a ) {
      vector<int> res;
      int freq[10], opt = 0;
      memset(freq,0,sizeof(freq));
      for(int i = 0; i < sz(a); ++i) {
         if(freq[a[i]-'A'] == 0) opt++;
         freq[a[i]-'A']++;
      }
      for(int i = 0; i < sz(a); ++i) {
         freq[a[i]-'A']--;
         res.push_back(opt);
         if(freq[a[i]-'A'] == 0) opt--;
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
         string answers            = "AAAAA";
         int expected__[]          = {1, 1, 1, 1, 1 };

         return verify_case( casenum__, starttime__, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof(int) ) ), CheatingQuiz().howMany( answers ) );
      }
      case 1: {
         string answers            = "AAABBB";
         int expected__[]          = {2, 2, 2, 1, 1, 1 };

         return verify_case( casenum__, starttime__, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof(int) ) ), CheatingQuiz().howMany( answers ) );
      }
      case 2: {
         string answers            = "CAAAAAC";
         int expected__[]          = {2, 2, 2, 2, 2, 2, 1 };

         return verify_case( casenum__, starttime__, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof(int) ) ), CheatingQuiz().howMany( answers ) );
      }
      case 3: {
         string answers            = "BBCA";
         int expected__[]          = {3, 3, 2, 1 };

         return verify_case( casenum__, starttime__, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof(int) ) ), CheatingQuiz().howMany( answers ) );
      }
      case 4: {
         string answers            = "BACACABCBBBBCAAAAACCCABBCAA";
         int expected__[]          = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1, 1 };

         return verify_case( casenum__, starttime__, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof(int) ) ), CheatingQuiz().howMany( answers ) );
      }

      // custom cases

/*
      case 5: {
         string answers            = ;
         int expected__[]          = ;

         return verify_case( casenum__, starttime__, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof(int) ) ), CheatingQuiz().howMany( answers ) );
      }
*/
/*
      case 6: {
         string answers            = ;
         int expected__[]          = ;

         return verify_case( casenum__, starttime__, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof(int) ) ), CheatingQuiz().howMany( answers ) );
      }
*/
/*
      case 7: {
         string answers            = ;
         int expected__[]          = ;

         return verify_case( casenum__, starttime__, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof(int) ) ), CheatingQuiz().howMany( answers ) );
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
