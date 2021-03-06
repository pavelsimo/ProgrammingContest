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

class GogoXCake {
public:
   string solve( vector <string> cake, vector <string> cutter ) {
      int N = sz(cake) - sz(cutter);
      int M = sz(cake[0]) - sz(cutter[0]);
      for(int i = 0; i <= N; ++i) {
         for(int j = 0; j <= M; ++j) {
            bool ok = true;
            for(int ii = 0; ii < sz(cutter); ++ii) {
               for(int jj = 0; jj < sz(cutter[ii]); ++jj) {
                  if(cutter[ii][jj] == '.' && cake[i + ii][j + jj] == 'X')
                     ok = false;
               }
            }
            if(ok) {
               for(int ii = 0; ii < sz(cutter); ++ii) {
                  for(int jj = 0; jj < sz(cutter[ii]); ++jj) {
                     if(cutter[ii][jj] == '.')
                        cake[i + ii][j + jj] = 'X';     
                  }
               }
            }
         }
      }
      for(int i = 0; i < sz(cake); ++i) {
         for(int j = 0; j < sz(cake[i]); ++j) {
            if(cake[i][j] == '.') 
               return "NO";  
         }
      }
      return "YES";
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
         string cake[]             = {"X.X" ,"..." ,"..." ,"X.X"};
         string cutter[]           = {".X" ,".." ,"X."};
         string expected__         = "YES";

         return verify_case( casenum__, starttime__, expected__, GogoXCake().solve( vector <string>( cake, cake + ( sizeof cake / sizeof(string) ) ), vector <string>( cutter, cutter + ( sizeof cutter / sizeof(string) ) ) ) );
      }
      case 1: {
         string cake[]             = {"..XX" ,"...X" ,"X..." ,"XX.."};
         string cutter[]           = {".." ,".."};
         string expected__         = "NO";

         return verify_case( casenum__, starttime__, expected__, GogoXCake().solve( vector <string>( cake, cake + ( sizeof cake / sizeof(string) ) ), vector <string>( cutter, cutter + ( sizeof cutter / sizeof(string) ) ) ) );
      }
      case 2: {
         string cake[]             = {"...X..."};
         string cutter[]           = {"..."};
         string expected__         = "YES";

         return verify_case( casenum__, starttime__, expected__, GogoXCake().solve( vector <string>( cake, cake + ( sizeof cake / sizeof(string) ) ), vector <string>( cutter, cutter + ( sizeof cutter / sizeof(string) ) ) ) );
      }
      case 3: {
         string cake[]             = {".X." ,"X.X" ,".X."};
         string cutter[]           = {"."};
         string expected__         = "YES";

         return verify_case( casenum__, starttime__, expected__, GogoXCake().solve( vector <string>( cake, cake + ( sizeof cake / sizeof(string) ) ), vector <string>( cutter, cutter + ( sizeof cutter / sizeof(string) ) ) ) );
      }
      case 4: {
         string cake[]             = {"XXXXXXX" ,"X.....X" ,"X.....X" ,"X.....X" ,"XXXXXXX"};
         string cutter[]           = {".X." ,"XXX" ,".X."};
         string expected__         = "NO";

         return verify_case( casenum__, starttime__, expected__, GogoXCake().solve( vector <string>( cake, cake + ( sizeof cake / sizeof(string) ) ), vector <string>( cutter, cutter + ( sizeof cutter / sizeof(string) ) ) ) );
      }
      case 5: {
         string cake[]             = {".." ,"X." ,".X"};
         string cutter[]           = {".." ,".X" ,"X."};
         string expected__         = "NO";

         return verify_case( casenum__, starttime__, expected__, GogoXCake().solve( vector <string>( cake, cake + ( sizeof cake / sizeof(string) ) ), vector <string>( cutter, cutter + ( sizeof cutter / sizeof(string) ) ) ) );
      }
      case 6: {
         string cake[]             = {"X.." ,".XX" ,".XX"};
         string cutter[]           = {".XX" ,".XX" ,"X.."};
         string expected__         = "NO";

         return verify_case( casenum__, starttime__, expected__, GogoXCake().solve( vector <string>( cake, cake + ( sizeof cake / sizeof(string) ) ), vector <string>( cutter, cutter + ( sizeof cutter / sizeof(string) ) ) ) );
      }

      // custom cases


      case 7: {
         string cake[]             = {"XXX", 
                                      "XXX", 
                                      ".XX"};
                                      
         string cutter[]           = {".X", 
                                      "X."};
         string expected__         = "NO";

         return verify_case( casenum__, starttime__, expected__, GogoXCake().solve( vector <string>( cake, cake + ( sizeof cake / sizeof(string) ) ), vector <string>( cutter, cutter + ( sizeof cutter / sizeof(string) ) ) ) );
      }

/*
      case 8: {
         string cake[]             = ;
         string cutter[]           = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, GogoXCake().solve( vector <string>( cake, cake + ( sizeof cake / sizeof(string) ) ), vector <string>( cutter, cutter + ( sizeof cutter / sizeof(string) ) ) ) );
      }
*/
/*
      case 9: {
         string cake[]             = ;
         string cutter[]           = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, GogoXCake().solve( vector <string>( cake, cake + ( sizeof cake / sizeof(string) ) ), vector <string>( cutter, cutter + ( sizeof cutter / sizeof(string) ) ) ) );
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
