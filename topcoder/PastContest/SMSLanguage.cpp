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


class SMSLanguage {
public:

   string replaceAll(const string &s, const string &pattern, const string &newstr) {
      string res = s;
      size_t pos = res.find(pattern);
      while(pos != string::npos) {
         res.replace(pos, sz(pattern), newstr);
         pos = res.find(pattern,pos + sz(pattern));
      }
      return res;
   }

   string translate( string text ) {
      string res = text;
      res = replaceAll(res,".","");
      res = replaceAll(res,",","");
      res = replaceAll(res,"?","");
      res = replaceAll(res,"!","");
      for(int i = 0; i < sz(res); ++i)
         if(isalpha(res[i])) 
            res[i] = tolower(res[i]);
      res = replaceAll(res,"and","&");
      res = replaceAll(res,"ate","8");
      res = replaceAll(res,"at","@");
      res = replaceAll(res,"you","U");
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
         string text               = "I HATE rats, and you?";
         string expected__         = "i h8 r@s & U";

         return verify_case( casenum__, starttime__, expected__, SMSLanguage().translate( text ) );
      }
      case 1: {
         string text               = "What is the weather like today?";
         string expected__         = "wh@ is the we@her like today";

         return verify_case( casenum__, starttime__, expected__, SMSLanguage().translate( text ) );
      }
      case 2: {
         string text               = "It is not too late to..";
         string expected__         = "it is not too l8 to";

         return verify_case( casenum__, starttime__, expected__, SMSLanguage().translate( text ) );
      }
      case 3: {
         string text               = "this text is already in sms language";
         string expected__         = "this text is already in sms language";

         return verify_case( casenum__, starttime__, expected__, SMSLanguage().translate( text ) );
      }

      // custom cases

/*
      case 4: {
         string text               = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, SMSLanguage().translate( text ) );
      }
*/
/*
      case 5: {
         string text               = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, SMSLanguage().translate( text ) );
      }
*/
/*
      case 6: {
         string text               = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, SMSLanguage().translate( text ) );
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
