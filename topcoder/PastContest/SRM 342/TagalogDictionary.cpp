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
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define all(x) (x).begin(),(x).end()
#define pb push_back


typedef vector<int> VI;
const char dict[][5] = {"a", "b", "k", "d", "e", "g", "h", "i", "l", "m", "n", "ng", "o", "p", "r", "s", "t", "u", "w", "y", "0"};

struct Word {
   string s;
   VI vt;
   Word(string cs) : s(cs) {
     for(int i = 0; i < sz(cs); ++i) {
        int j = 0;
        for(;dict[j][0]!=0;++j)
           if(cs[i]==dict[j][0]) break;
        if(i+1 < sz(cs) && cs[i]=='n' && cs[i+1]=='g') {
           j++; i++;
        }
        vt.push_back(j);
     }   
   }
   bool operator <(const Word &T) const {
      return vt < T.vt;  
   }
};


class TagalogDictionary {
public:
   
   vector <string> sortWords( vector <string> words ) {
      vector<string> res;
      vector<Word> a;
      int n = sz(words);
      for(int i = 0; i < n; ++i)
         a.push_back(Word(words[i]));
      sort(all(a));
      for(int i = 0; i < n; ++i)
         res.push_back(a[i].s);
      return res;
   }
   
   /* V1
    * 
   vector <string> sortWords( vector <string> words ) {
      vector<string> res;
      int n = sz(words);
      for(int i = 0; i < n; ++i) {
         res.push_back(words[i]);
         for(int j = 0; j < sz(res[i]); ++j) {
            if(res[i][j]=='k') res[i][j] = 'c';
            if(res[i][j] >= 'a' && res[i][j] <= 'n') res[i][j] = toupper(res[i][j]);
         }
         for(int j = 0; j < sz(res[i]); ++j) {
            if(j+1 < sz(res[i]) && res[i][j]=='N' && res[i][j+1]=='G') {
                 res[i][j]='n';
                 res[i].erase(res[i].begin()+j+1);
            }
         }
      }
      sort(all(res));
      for(int i = 0; i < sz(res); ++i) {
         for(int j = 0; j < sz(res[i]); ++j) {
            if(res[i][j]=='n')
               res[i].insert(j+1,"g");
         }
         for(int j = 0; j < sz(res[i]); ++j) {
            res[i][j] = tolower(res[i][j]);
            if(res[i][j]=='c') res[i][j] = 'k';
         }
      }
      return res;
   }
   */
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
         string words[]            = {"abakada","alpabet","tagalog","ako"};
         string expected__[]       = {"abakada", "ako", "alpabet", "tagalog" };

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), TagalogDictionary().sortWords( vector <string>( words, words + ( sizeof words / sizeof(string) ) ) ) );
      }
      case 1: {
         string words[]            = {"ang","ano","anim","alak","alam","alab"};
         string expected__[]       = {"alab", "alak", "alam", "anim", "ano", "ang" };

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), TagalogDictionary().sortWords( vector <string>( words, words + ( sizeof words / sizeof(string) ) ) ) );
      }
      case 2: {
         string words[]            = {"siya","niya","kaniya","ikaw","ito","iyon"};
         string expected__[]       = {"kaniya", "ikaw", "ito", "iyon", "niya", "siya" };

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), TagalogDictionary().sortWords( vector <string>( words, words + ( sizeof words / sizeof(string) ) ) ) );
      }
      case 3: {
         string words[]            = {"kaba","baka","naba","ngipin","nipin"};
         string expected__[]       = {"baka", "kaba", "naba", "nipin", "ngipin" };

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), TagalogDictionary().sortWords( vector <string>( words, words + ( sizeof words / sizeof(string) ) ) ) );
      }
      case 4: {
         string words[]            = {"knilngiggnngginggn","ingkigningg","kingkong","dingdong","dindong","dingdont","ingkblot"};
         string expected__[]       = {"kingkong", "knilngiggnngginggn", "dindong", "dingdont", "dingdong", "ingkblot", "ingkigningg" };

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), TagalogDictionary().sortWords( vector <string>( words, words + ( sizeof words / sizeof(string) ) ) ) );
      }
      case 5: {
         string words[]            = {"silangang", "baka", "bada", "silang"};
         string expected__[]       = {"baka", "bada", "silang", "silangang" };

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), TagalogDictionary().sortWords( vector <string>( words, words + ( sizeof words / sizeof(string) ) ) ) );
      }

      // custom cases

/*
      case 6: {
         string words[]            = ;
         string expected__[]       = ;

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), TagalogDictionary().sortWords( vector <string>( words, words + ( sizeof words / sizeof(string) ) ) ) );
      }
*/
/*
      case 7: {
         string words[]            = ;
         string expected__[]       = ;

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), TagalogDictionary().sortWords( vector <string>( words, words + ( sizeof words / sizeof(string) ) ) ) );
      }
*/
/*
      case 8: {
         string words[]            = ;
         string expected__[]       = ;

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), TagalogDictionary().sortWords( vector <string>( words, words + ( sizeof words / sizeof(string) ) ) ) );
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
