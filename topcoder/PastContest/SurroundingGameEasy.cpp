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

int di[] = {1,-1,0,0};
int dj[] = {0,0,+1,-1};

class SurroundingGameEasy {
public:
   int score( vector <string> C, vector <string> B, vector <string> S ) {
      int N = sz(C);
      int M = sz(C[0]);
      int benefit = 0, cost = 0;
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < M; ++j) {
            bool dom = false;
            if(S[i][j] == 'o') {
               dom = true;
               cost += (C[i][j] - '0');
            } else {
               int k;
               for(k = 0; k < 4; ++k) {
                  int ni = i + di[k];
                  int nj = j + dj[k];
                  if(ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
                  if(S[ni][nj] == '.') break;
               }
               if(k == 4) dom = true;
            }
            if(dom) benefit += (B[i][j] - '0');
         }
      }
      return benefit - cost;
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
         string cost[]             = {"21","12"};
         string benefit[]          = {"21","12"};
         string stone[]            = {".o","o."};
         int expected__            = 4;

         return verify_case( casenum__, starttime__, expected__, SurroundingGameEasy().score( vector <string>( cost, cost + ( sizeof cost / sizeof(string) ) ), vector <string>( benefit, benefit + ( sizeof benefit / sizeof(string) ) ), vector <string>( stone, stone + ( sizeof stone / sizeof(string) ) ) ) );
      }
      case 1: {
         string cost[]             = {"99","99"};
         string benefit[]          = {"11","11"};
         string stone[]            = {".o","o."};
         int expected__            = -14;

         return verify_case( casenum__, starttime__, expected__, SurroundingGameEasy().score( vector <string>( cost, cost + ( sizeof cost / sizeof(string) ) ), vector <string>( benefit, benefit + ( sizeof benefit / sizeof(string) ) ), vector <string>( stone, stone + ( sizeof stone / sizeof(string) ) ) ) );
      }
      case 2: {
         string cost[]             = {"888","888","888"};
         string benefit[]          = {"000","090","000"};
         string stone[]            = {"...",".o.","..."};
         int expected__            = 1;

         return verify_case( casenum__, starttime__, expected__, SurroundingGameEasy().score( vector <string>( cost, cost + ( sizeof cost / sizeof(string) ) ), vector <string>( benefit, benefit + ( sizeof benefit / sizeof(string) ) ), vector <string>( stone, stone + ( sizeof stone / sizeof(string) ) ) ) );
      }
      case 3: {
         string cost[]             = {"4362","4321"};
         string benefit[]          = {"5329","5489"};
         string stone[]            = {"...o","..o."};
         int expected__            = 22;

         return verify_case( casenum__, starttime__, expected__, SurroundingGameEasy().score( vector <string>( cost, cost + ( sizeof cost / sizeof(string) ) ), vector <string>( benefit, benefit + ( sizeof benefit / sizeof(string) ) ), vector <string>( stone, stone + ( sizeof stone / sizeof(string) ) ) ) );
      }
      case 4: {
         string cost[]             = {"5413","4323","8321","5490"};
         string benefit[]          = {"0432","7291","3901","2310"};
         string stone[]            = {"ooo.","o..o","...o","oooo"};
         int expected__            = -12;

         return verify_case( casenum__, starttime__, expected__, SurroundingGameEasy().score( vector <string>( cost, cost + ( sizeof cost / sizeof(string) ) ), vector <string>( benefit, benefit + ( sizeof benefit / sizeof(string) ) ), vector <string>( stone, stone + ( sizeof stone / sizeof(string) ) ) ) );
      }

      // custom cases

/*
      case 5: {
         string cost[]             = ;
         string benefit[]          = ;
         string stone[]            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, SurroundingGameEasy().score( vector <string>( cost, cost + ( sizeof cost / sizeof(string) ) ), vector <string>( benefit, benefit + ( sizeof benefit / sizeof(string) ) ), vector <string>( stone, stone + ( sizeof stone / sizeof(string) ) ) ) );
      }
*/
/*
      case 6: {
         string cost[]             = ;
         string benefit[]          = ;
         string stone[]            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, SurroundingGameEasy().score( vector <string>( cost, cost + ( sizeof cost / sizeof(string) ) ), vector <string>( benefit, benefit + ( sizeof benefit / sizeof(string) ) ), vector <string>( stone, stone + ( sizeof stone / sizeof(string) ) ) ) );
      }
*/
/*
      case 7: {
         string cost[]             = ;
         string benefit[]          = ;
         string stone[]            = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, SurroundingGameEasy().score( vector <string>( cost, cost + ( sizeof cost / sizeof(string) ) ), vector <string>( benefit, benefit + ( sizeof benefit / sizeof(string) ) ), vector <string>( stone, stone + ( sizeof stone / sizeof(string) ) ) ) );
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
