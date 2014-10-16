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


class WordFind {
public:
   vector <string> findWords( vector <string> grid, vector <string> wordList ) {

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
   template<> ostream& operator<<( ostream &os, const vector<string> &v ) {
      os << "{";
      for ( vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) {
         if ( vi != v.begin() ) os << ",";
         os << " \"" << *vi << "\"";
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
   int verify_case( int casenum, long long starttime, const vector <string> &expected, const vector <string> &received ) {
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
         string grid[]             = {"TEST",  "GOAT",  "BOAT"};
         string wordList[]         = {"GOAT", "BOAT", "TEST"};
         string expected__[]       = { "1 0",   "2 0",   "0 0" };

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), WordFind().findWords( vector <string>( grid, grid + ( sizeof grid / sizeof(string) ) ), vector <string>( wordList, wordList + ( sizeof wordList / sizeof(string) ) ) ) );
      }
      case 1: {
         string grid[]             = {"SXXX",  "XQXM",  "XXLA",  "XXXR"};
         string wordList[]         = {"SQL", "RAM"};
         string expected__[]       = { "0 0",   "" };

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), WordFind().findWords( vector <string>( grid, grid + ( sizeof grid / sizeof(string) ) ), vector <string>( wordList, wordList + ( sizeof wordList / sizeof(string) ) ) ) );
      }
      case 2: {
         string grid[]             = {"EASYTOFINDEAGSRVHOTCJYG",  "FLVENKDHCESOXXXXFAGJKEO",  "YHEDYNAIRQGIZECGXQLKDBI",  "DEIJFKABAQSIHSNDLOMYJIN",  "CKXINIMMNGRNSNRGIWQLWOG",  "VOFQDROQGCWDKOUYRAFUCDO",  "PFLXWTYKOITSURQJGEGSPGG"};
         string wordList[]         = {"EASYTOFIND", "DIAG", "GOING", "THISISTOOLONGTOFITINTHISPUZZLE"};
         string expected__[]       = { "0 0",   "1 6",   "0 22",   "" };

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), WordFind().findWords( vector <string>( grid, grid + ( sizeof grid / sizeof(string) ) ), vector <string>( wordList, wordList + ( sizeof wordList / sizeof(string) ) ) ) );
      }

      // custom cases

/*
      case 3: {
         string grid[]             = ;
         string wordList[]         = ;
         string expected__[]       = ;

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), WordFind().findWords( vector <string>( grid, grid + ( sizeof grid / sizeof(string) ) ), vector <string>( wordList, wordList + ( sizeof wordList / sizeof(string) ) ) ) );
      }
*/
/*
      case 4: {
         string grid[]             = ;
         string wordList[]         = ;
         string expected__[]       = ;

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), WordFind().findWords( vector <string>( grid, grid + ( sizeof grid / sizeof(string) ) ), vector <string>( wordList, wordList + ( sizeof wordList / sizeof(string) ) ) ) );
      }
*/
/*
      case 5: {
         string grid[]             = ;
         string wordList[]         = ;
         string expected__[]       = ;

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), WordFind().findWords( vector <string>( grid, grid + ( sizeof grid / sizeof(string) ) ), vector <string>( wordList, wordList + ( sizeof wordList / sizeof(string) ) ) ) );
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
