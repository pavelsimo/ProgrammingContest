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

vector<string> A[26];

struct cmp {
   bool operator() (const string &a, const string &b) {
      return strcasecmp(a.c_str(), b.c_str()) < 0;
   }
};

class Glossary {
public:
   int getsize() {
      int res = 0;
      int cnt = 0;
      for(int i = 0; i < 13; ++i) {
         if(sz(A[i]) > 0) cnt+=2+sz(A[i]);  
         res = max(res,cnt);
      }
      cnt = 0;
      for(int i = 13; i < 26; ++i) {
         if(sz(A[i]) > 0) cnt+=2+sz(A[i]);
         res = max(res,cnt);
      }      
      return res;         
   }
   
   vector <string> buildGlossary( vector <string> items ) {
      vector<string> res;
      for(int i = 0; i < 26; ++i)
         A[i].clear();
      for(int i = 0; i < sz(items); ++i)
         A[tolower(items[i][0])-'a'].push_back(items[i]);
      for(int i = 0; i < 26; ++i)
         sort(all(A[i]),cmp());
      int N = getsize();
      for(int i = 0; i < N; ++i)
         res.push_back(string(40,' '));
      int index = 0;
      for(int i = 0; i < 13; ++i) {
         if(sz(A[i]) > 0) {
            char ch = 'A' + i;
            string s1 = "", s2 = "";
            res[index][0] = ch;
            index++;
            for(int j = 0; j < 19; ++j) 
               res[index][j] = '-';
            index++;
            for(int j = 0; j < sz(A[i]); ++j) {
               string word = A[i][j];
               for(int k = 0; k < sz(word); ++k)
                  res[index][2 + k] = word[k];
               index++;
            }
         }
      }
      index = 0;
      for(int i = 13; i < 26; ++i) {
         if(sz(A[i]) > 0) {
            char ch = 'A' + i;
            string s1 = "", s2 = "";
            res[index][21] = ch;
            index++;
            for(int j = 21; j < 40; ++j) 
               res[index][j] = '-';
            index++;
            for(int j = 0; j < sz(A[i]); ++j) {
               string word = A[i][j];
               for(int k = 0; k < sz(word); ++k)
                  res[index][23 + k] = word[k];
               index++;
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
         string items[]            = {"Canada", "France", "Germany", "Italy", "Japan", "Russia",   "United Kingdom", "United States"};
         string expected__[]       = {"C                    R                  ", "-------------------  -------------------", "  Canada               Russia           ", "F                    U                  ", "-------------------  -------------------", "  France               United Kingdom   ", "G                      United States    ", "-------------------                     ", "  Germany                               ", "I                                       ", "-------------------                     ", "  Italy                                 ", "J                                       ", "-------------------                     ", "  Japan                                 " };

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), Glossary().buildGlossary( vector <string>( items, items + ( sizeof items / sizeof(string) ) ) ) );
      }
      case 1: {
         string items[]            = {"alpha", "beta", "gamma", "delta", "omega"};
         string expected__[]       = {"A                    O                  ", "-------------------  -------------------", "  alpha                omega            ", "B                                       ", "-------------------                     ", "  beta                                  ", "D                                       ", "-------------------                     ", "  delta                                 ", "G                                       ", "-------------------                     ", "  gamma                                 " };

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), Glossary().buildGlossary( vector <string>( items, items + ( sizeof items / sizeof(string) ) ) ) );
      }
      case 2: {
         string items[]            = {"AVL tree", "backtracking", "array", "balanced tree", "binary search"};
         string expected__[]       = {"A                                       ", "-------------------                     ", "  array                                 ", "  AVL tree                              ", "B                                       ", "-------------------                     ", "  backtracking                          ", "  balanced tree                         ", "  binary search                         " };

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), Glossary().buildGlossary( vector <string>( items, items + ( sizeof items / sizeof(string) ) ) ) );
      }
      case 3: {
         string items[]            = {"XXXXXXXXXXXXXXXXX",   "YYYYYYYYYYYYYYYYY",  "ZZZZZZZZZZZZZZZZZ"};
         string expected__[]       = {"                     X                  ", "                     -------------------", "                       XXXXXXXXXXXXXXXXX", "                     Y                  ", "                     -------------------", "                       YYYYYYYYYYYYYYYYY", "                     Z                  ", "                     -------------------", "                       ZZZZZZZZZZZZZZZZZ" };

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), Glossary().buildGlossary( vector <string>( items, items + ( sizeof items / sizeof(string) ) ) ) );
      }
      case 4: {
         string items[]            = {"Asteria", "Astraeus", "Atlas", "Clymene", "Coeus", "Crius",   "Cronus", "Dione", "Epimetheus", "Helios", "Hyperion", "Iapetus",   "Leto", "Mnemosyne", "Oceanus", "Ophion", "Phoebe", "Prometheus",   "Rhea", "Tethys", "Theia", "Themis"};
         string expected__[]       = {"A                    O                  ", "-------------------  -------------------", "  Asteria              Oceanus          ", "  Astraeus             Ophion           ", "  Atlas              P                  ", "C                    -------------------", "-------------------    Phoebe           ", "  Clymene              Prometheus       ", "  Coeus              R                  ", "  Crius              -------------------", "  Cronus               Rhea             ", "D                    T                  ", "-------------------  -------------------", "  Dione                Tethys           ", "E                      Theia            ", "-------------------    Themis           ", "  Epimetheus                            ", "H                                       ", "-------------------                     ", "  Helios                                ", "  Hyperion                              ", "I                                       ", "-------------------                     ", "  Iapetus                               ", "L                                       ", "-------------------                     ", "  Leto                                  ", "M                                       ", "-------------------                     ", "  Mnemosyne                             " };

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), Glossary().buildGlossary( vector <string>( items, items + ( sizeof items / sizeof(string) ) ) ) );
      }

      // custom cases

/*
      case 5: {
         string items[]            = ;
         string expected__[]       = ;

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), Glossary().buildGlossary( vector <string>( items, items + ( sizeof items / sizeof(string) ) ) ) );
      }
*/
/*
      case 6: {
         string items[]            = ;
         string expected__[]       = ;

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), Glossary().buildGlossary( vector <string>( items, items + ( sizeof items / sizeof(string) ) ) ) );
      }
*/
/*
      case 7: {
         string items[]            = ;
         string expected__[]       = ;

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), Glossary().buildGlossary( vector <string>( items, items + ( sizeof items / sizeof(string) ) ) ) );
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
