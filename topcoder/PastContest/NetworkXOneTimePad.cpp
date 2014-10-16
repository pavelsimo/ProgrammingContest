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

set<string> possibleKeys;

class NetworkXOneTimePad {
public:

   string sxor(string s1, string s2) {
      string res = s1;
      for(int i = 0; i < sz(res); ++i) {
         if(s1[i]==s2[i]) res[i] = '0';
         else res[i] = '1';
      }
      return res;
   }

   int crack( vector <string> p, vector <string> c ) {
      possibleKeys.clear();
      int res = 0;
      sort(all(p));
      for(int i = 0; i < sz(p); ++i) {
         for(int j = 0; j < sz(c); ++j) {
            possibleKeys.insert(sxor(p[i],c[j]));
         }
      }
      for(set<string>::iterator it = possibleKeys.begin(); it != possibleKeys.end(); ++it) {
         bool consistent = true;
         for(int j = 0; j < sz(c); ++j) {
            string s = sxor(c[j],*it);
            if(!binary_search(all(p),s))
               consistent = false;
         }
         if(consistent) res++;
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
         string plaintexts[]       = {"110", "001"};
         string ciphertexts[]      = {"101", "010"};
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, NetworkXOneTimePad().crack( vector <string>( plaintexts, plaintexts + ( sizeof plaintexts / sizeof(string) ) ), vector <string>( ciphertexts, ciphertexts + ( sizeof ciphertexts / sizeof(string) ) ) ) );
      }
      case 1: {
         string plaintexts[]       = {"00", "01", "10", "11"};
         string ciphertexts[]      = {"00", "01", "10", "11"};
         int expected__            = 4;

         return verify_case( casenum__, starttime__, expected__, NetworkXOneTimePad().crack( vector <string>( plaintexts, plaintexts + ( sizeof plaintexts / sizeof(string) ) ), vector <string>( ciphertexts, ciphertexts + ( sizeof ciphertexts / sizeof(string) ) ) ) );
      }
      case 2: {
         string plaintexts[]       = {"01", "10"};
         string ciphertexts[]      = {"00"};
         int expected__            = 2;

         return verify_case( casenum__, starttime__, expected__, NetworkXOneTimePad().crack( vector <string>( plaintexts, plaintexts + ( sizeof plaintexts / sizeof(string) ) ), vector <string>( ciphertexts, ciphertexts + ( sizeof ciphertexts / sizeof(string) ) ) ) );
      }
      case 3: {
         string plaintexts[]       = {"000", "111", "010", "101", "110", "001"};
         string ciphertexts[]      = {"011", "100"};
         int expected__            = 6;

         return verify_case( casenum__, starttime__, expected__, NetworkXOneTimePad().crack( vector <string>( plaintexts, plaintexts + ( sizeof plaintexts / sizeof(string) ) ), vector <string>( ciphertexts, ciphertexts + ( sizeof ciphertexts / sizeof(string) ) ) ) );
      }

      // custom cases

/*
      case 4: {
         string plaintexts[]       = ;
         string ciphertexts[]      = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, NetworkXOneTimePad().crack( vector <string>( plaintexts, plaintexts + ( sizeof plaintexts / sizeof(string) ) ), vector <string>( ciphertexts, ciphertexts + ( sizeof ciphertexts / sizeof(string) ) ) ) );
      }
*/
/*
      case 5: {
         string plaintexts[]       = ;
         string ciphertexts[]      = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, NetworkXOneTimePad().crack( vector <string>( plaintexts, plaintexts + ( sizeof plaintexts / sizeof(string) ) ), vector <string>( ciphertexts, ciphertexts + ( sizeof ciphertexts / sizeof(string) ) ) ) );
      }
*/
/*
      case 6: {
         string plaintexts[]       = ;
         string ciphertexts[]      = ;
         int expected__            = ;

         return verify_case( casenum__, starttime__, expected__, NetworkXOneTimePad().crack( vector <string>( plaintexts, plaintexts + ( sizeof plaintexts / sizeof(string) ) ), vector <string>( ciphertexts, ciphertexts + ( sizeof ciphertexts / sizeof(string) ) ) ) );
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
