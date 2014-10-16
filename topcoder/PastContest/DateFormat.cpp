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


typedef pair<int,int> PII;

class DateFormat {
public:

   string fromEuropeanToUs( vector <string> dateList ) {
      string res = "";
      string s = accumulate(all(dateList), string());
      string date;
      istringstream in(s);
      PII prev(-1, -1);
      for (int i = 0; in >> date; ++i) {
        int m, d;
        sscanf(date.c_str(), "%d/%d", &m, &d);
        bool us = PII(m, d) > prev && m <= 12;
        bool eu = PII(d, m) > prev && d <= 12;
        if (!us && !eu) return "";
        if (us && eu) prev = min(PII(m, d), PII(d, m));
        else if (us) prev = PII(m, d);
        else prev = PII(d, m);
        if (!res.empty()) res += " ";
        char buf[16];
        sprintf(buf, "%02d/%02d", prev.first, prev.second);
        res += buf;
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
         string dateList[]         = {"16/01"};
         string expected__         = "01/16";

         return verify_case( casenum__, starttime__, expected__, DateFormat().fromEuropeanToUs( vector <string>( dateList, dateList + ( sizeof dateList / sizeof(string) ) ) ) );
      }
      case 1: {
         string dateList[]         = {"02/01 08/02 08/02 21/09 06/11"};
         string expected__         = "01/02 02/08 08/02 09/21 11/06";

         return verify_case( casenum__, starttime__, expected__, DateFormat().fromEuropeanToUs( vector <string>( dateList, dateList + ( sizeof dateList / sizeof(string) ) ) ) );
      }
      case 2: {
         string dateList[]         = {"08/02 08/02 03/04"};
         string expected__         = "";

         return verify_case( casenum__, starttime__, expected__, DateFormat().fromEuropeanToUs( vector <string>( dateList, dateList + ( sizeof dateList / sizeof(string) ) ) ) );
      }
      case 3: {
         string dateList[]         = {"2", "9/02", " 08/", "03 01/08"};
         string expected__         = "02/29 03/08 08/01";

         return verify_case( casenum__, starttime__, expected__, DateFormat().fromEuropeanToUs( vector <string>( dateList, dateList + ( sizeof dateList / sizeof(string) ) ) ) );
      }
      case 4: {
         string dateList[]         = {"17/01 05/05 03/07 07/24 23/09 09/30 01/11 11/11"};
         string expected__         = "01/17 05/05 07/03 07/24 09/23 09/30 11/01 11/11";

         return verify_case( casenum__, starttime__, expected__, DateFormat().fromEuropeanToUs( vector <string>( dateList, dateList + ( sizeof dateList / sizeof(string) ) ) ) );
      }

      // custom cases

/*
      case 5: {
         string dateList[]         = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, DateFormat().fromEuropeanToUs( vector <string>( dateList, dateList + ( sizeof dateList / sizeof(string) ) ) ) );
      }
*/
/*
      case 6: {
         string dateList[]         = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, DateFormat().fromEuropeanToUs( vector <string>( dateList, dateList + ( sizeof dateList / sizeof(string) ) ) ) );
      }
*/
/*
      case 7: {
         string dateList[]         = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, DateFormat().fromEuropeanToUs( vector <string>( dateList, dateList + ( sizeof dateList / sizeof(string) ) ) ) );
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
