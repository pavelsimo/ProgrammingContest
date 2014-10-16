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

typedef long long llong;
bool seen[10002];

struct Node {
   string s;
   int mod;
   Node(string _s, int _mod) :
      s(_s), mod(_mod) {}
};

string tostr(int d) {
   stringstream out;
   out << d;
   return out.str();
}

string format(string s) {
   return s.substr(0,3)+"..."+s.substr(sz(s)-3)+"("+tostr(sz(s))+" digits)";
}

class MultiplesWithLimit {
public:
   string minMultiples( int N, vector <int> forbiddenDigits ) {
      memset(seen,false,sizeof(seen));
      string res = "IMPOSSIBLE";
      queue<Node> Q;
      for(int d = 1; d <= 9; ++d) {
         if(find(all(forbiddenDigits),d) == forbiddenDigits.end()) {
            seen[d % N] = true;
            Q.push(Node(tostr(d),d % N));
         }
      }
      while(!Q.empty()) {
         Node cur = Q.front(); Q.pop();
         if(cur.mod == 0) {
            if(sz(cur.s) >= 9)
               return format(cur.s);
            return cur.s;         
         }
         for(int d = 0; d <= 9; ++d) {
            if(find(all(forbiddenDigits),d) == forbiddenDigits.end()) {
               int nmod = (cur.mod * 10 + d) % N;
               string ns = cur.s + tostr(d);
               if(!seen[nmod]) {
                  Q.push(Node(ns,nmod));   
                  seen[nmod] = true;
               }
            }
         }         
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
         int N                     = 8;
         int forbiddenDigits[]     = {2,3,4,5,6,7,8,9};
         string expected__         = "1000";

         return verify_case( casenum__, starttime__, expected__, MultiplesWithLimit().minMultiples( N, vector <int>( forbiddenDigits, forbiddenDigits + ( sizeof forbiddenDigits / sizeof(int) ) ) ) );
      }
      case 1: {
         int N                     = 9;
         int forbiddenDigits[]     = {1,3,4,5,6,7,8,9};
         string expected__         = "222...222(9 digits)";

         return verify_case( casenum__, starttime__, expected__, MultiplesWithLimit().minMultiples( N, vector <int>( forbiddenDigits, forbiddenDigits + ( sizeof forbiddenDigits / sizeof(int) ) ) ) );
      }
      case 2: {
         int N                     = 524;
         int forbiddenDigits[]     = {5,2,4};
         string expected__         = "3668";

         return verify_case( casenum__, starttime__, expected__, MultiplesWithLimit().minMultiples( N, vector <int>( forbiddenDigits, forbiddenDigits + ( sizeof forbiddenDigits / sizeof(int) ) ) ) );
      }
      case 3: {
         int N                     = 10000;
         int forbiddenDigits[]     = {0};
         string expected__         = "IMPOSSIBLE";

         return verify_case( casenum__, starttime__, expected__, MultiplesWithLimit().minMultiples( N, vector <int>( forbiddenDigits, forbiddenDigits + ( sizeof forbiddenDigits / sizeof(int) ) ) ) );
      }
      case 4: {
         int N                     = 1;
         int forbiddenDigits[]     = {0,1,2,3,4,5,6,7,8,9};
         string expected__         = "IMPOSSIBLE";

         return verify_case( casenum__, starttime__, expected__, MultiplesWithLimit().minMultiples( N, vector <int>( forbiddenDigits, forbiddenDigits + ( sizeof forbiddenDigits / sizeof(int) ) ) ) );
      }

      // custom cases

/*
      case 5: {
         int N                     = ;
         int forbiddenDigits[]     = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, MultiplesWithLimit().minMultiples( N, vector <int>( forbiddenDigits, forbiddenDigits + ( sizeof forbiddenDigits / sizeof(int) ) ) ) );
      }
*/
/*
      case 6: {
         int N                     = ;
         int forbiddenDigits[]     = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, MultiplesWithLimit().minMultiples( N, vector <int>( forbiddenDigits, forbiddenDigits + ( sizeof forbiddenDigits / sizeof(int) ) ) ) );
      }
*/
/*
      case 7: {
         int N                     = ;
         int forbiddenDigits[]     = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, MultiplesWithLimit().minMultiples( N, vector <int>( forbiddenDigits, forbiddenDigits + ( sizeof forbiddenDigits / sizeof(int) ) ) ) );
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
