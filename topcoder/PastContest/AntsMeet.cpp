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


class AntsMeet {
public:
   int countAnts( vector <int> x, vector <int> y, string direction ) {

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
         int x[]                   = {0,10,20,30};
         int y[]                   = {0,10,20,30};
         string direction          = "NWNE";
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, AntsMeet().countAnts( vector <int>( x, x + ( sizeof x / sizeof(int) ) ), vector <int>( y, y + ( sizeof y / sizeof(int) ) ), direction ) );
      }
      case 1: {
         int x[]                   = {-10,0,0,10};
         int y[]                   = {0,-10,10,0};
         string direction          = "NEWS";
         int expected__            = 0;

         return verify_case( casenum__, starttime__, expected__, AntsMeet().countAnts( vector <int>( x, x + ( sizeof x / sizeof(int) ) ), vector <int>( y, y + ( sizeof y / sizeof(int) ) ), direction ) );
      }
      case 2: {
         int x[]                   = {-1,-1,-1,0,0,0,1,1,1};
         int y[]                   = {-1,0,1,-1,0,1,-1,0,1};
         string direction          = "ESEWNNEWW";
         int expected__            = 4;

         return verify_case( casenum__, starttime__, expected__, AntsMeet().countAnts( vector <int>( x, x + ( sizeof x / sizeof(int) ) ), vector <int>( y, y + ( sizeof y / sizeof(int) ) ), direction ) );
      }
      case 3: {
         int x[]                   = {4,7,6,2,6,5,7,7,8,4,7,8,8,8,5,4,8,9,1,5,9,3,4,0,0,1,0,7,2,6,9,6,3,0,5,5,1,2,0,4,9,7,7,1,8,1,9,2,7,3};
         int y[]                   = {2,3,0,6,8,4,9,0,5,0,2,4,3,8,1,5,0,7,3,7,0,9,8,1,9,4,7,8,1,1,6,6,6,2,8,5,1,9,0,1,1,1,7,0,2,5,4,7,5,3};
         string direction          = "SSNWSWSENSWSESWEWSWSENWNNNESWSWSWWSSWEEWWNWWWNWENN" ;
         int expected__            = 25;

         return verify_case( casenum__, starttime__, expected__, AntsMeet().countAnts( vector <int>( x, x + ( sizeof x / sizeof(int) ) ), vector <int>( y, y + ( sizeof y / sizeof(int) ) ), direction ) );
      }
      case 4: {
         int x[]                   = {478,-664,759,434,-405,513,565,-396,311,-174,56,993,251,-341,993,-112,242,129,383,513,-78,-341,-148,129,423 ,493,434,-405,478,-148,929,251,56,242,929,-78,423,-664,802,251,759,383,-112,-591,-591,-248,660,660,735,493};
         int y[]                   = {-186,98,948,795,289,-678,948,-170,-195,290,-354,-424,289,-157,-166,150,706,-678,684,-294,-234,36,36,-294,-216 ,-234,427,945,265,-157,265,715,275,715,-186,337,798,-170,427,706,754,961,286,-216,798,286,961,684,-424,337};
         string direction          = "WNSNNSSWWWEENWESNSWSWSEWWEWEWWWNWESNSSNNSNNWWWNESE";
         int expected__            = 44;

         return verify_case( casenum__, starttime__, expected__, AntsMeet().countAnts( vector <int>( x, x + ( sizeof x / sizeof(int) ) ), vector <int>( y, y + ( sizeof y / sizeof(int) ) ), direction ) );
      }

      // custom cases

/*
      case 5: {
         int x[]                   = ;
         int y[]                   = ;
         string direction          = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, AntsMeet().countAnts( vector <int>( x, x + ( sizeof x / sizeof(int) ) ), vector <int>( y, y + ( sizeof y / sizeof(int) ) ), direction ) );
      }
*/
/*
      case 6: {
         int x[]                   = ;
         int y[]                   = ;
         string direction          = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, AntsMeet().countAnts( vector <int>( x, x + ( sizeof x / sizeof(int) ) ), vector <int>( y, y + ( sizeof y / sizeof(int) ) ), direction ) );
      }
*/
/*
      case 7: {
         int x[]                   = ;
         int y[]                   = ;
         string direction          = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, AntsMeet().countAnts( vector <int>( x, x + ( sizeof x / sizeof(int) ) ), vector <int>( y, y + ( sizeof y / sizeof(int) ) ), direction ) );
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
