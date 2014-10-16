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

#define MOD 27

bool islegal(string s) {
   if(isspace(s[0])) return false;
   if(isspace(s[sz(s)-1])) return false;
   for(int i = 0; i < sz(s)-1; ++i)
      if(isspace(s[i]) && isspace(s[i+1])) return false;
   istringstream in(s);
   string word;
   while(in >> word) {
      if(sz(word) < 2 || sz(word) > 8) 
         return false;
      if(word.find_first_of("aeiou",0)==string::npos)
         return false;
   }
   return true;
}

int tonum(char ch) {
   if(isspace(ch)) return 0;
   return ch-'a'+1;
}

char tochar(int x) {
   if(x==0) return ' ';
   return 'a'+x-1;
}

string decrypt(string s, string passwd) {
   string res = s;
   for(int i = 0; i < sz(res); ++i) {
      int x = (MOD + tonum(res[i]) - tonum(passwd[i%3])) % MOD;
      res[i] = tochar(x);      
   }
   return res;
}

class SimpleRotationDecoder {
public:
   string decode( string cipherText ) {
      for(char p1 = 'a'; p1 <= 'z'; ++p1)
      for(char p2 = 'a'; p2 <= 'z'; ++p2)
      for(char p3 = 'a'; p3 <= 'z'; ++p3) {
         string password = "";
         password+=p1;
         password+=p2;
         password+=p3;
         string s = decrypt(cipherText,password);
         if(islegal(s)) return s;
      }
      return "";  
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
         string cipherText         = "mmbtvrbhhtgohaktklqegnrmlelojotyeyeiudvtil ey ffg";
         string expected__         = "the quick brown fox jumps over the lazy dog again";

         return verify_case( casenum__, starttime__, expected__, SimpleRotationDecoder().decode( cipherText ) );
      }
      case 1: {
         string cipherText         = "ntgntgntgntofwlfwlfwlnookookook";
         string expected__         = "he he he heh he he heh he he he";

         return verify_case( casenum__, starttime__, expected__, SimpleRotationDecoder().decode( cipherText ) );
      }
      case 2: {
         string cipherText         = "f sgnzslhzquq ydyuinmqiwfyrtdvn";
         string expected__         = "abkbprnn usmlbqz mdpelkoa jofni";

         return verify_case( casenum__, starttime__, expected__, SimpleRotationDecoder().decode( cipherText ) );
      }
      case 3: {
         string cipherText         = "shxnaaeqjlofhhsuurbhpdgt z";
         string expected__         = "naeiui jrghnca pnzxaxz avs";

         return verify_case( casenum__, starttime__, expected__, SimpleRotationDecoder().decode( cipherText ) );
      }

      // custom cases

/*
      case 4: {
         string cipherText         = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, SimpleRotationDecoder().decode( cipherText ) );
      }
*/
/*
      case 5: {
         string cipherText         = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, SimpleRotationDecoder().decode( cipherText ) );
      }
*/
/*
      case 6: {
         string cipherText         = ;
         string expected__         = ;

         return verify_case( casenum__, starttime__, expected__, SimpleRotationDecoder().decode( cipherText ) );
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
