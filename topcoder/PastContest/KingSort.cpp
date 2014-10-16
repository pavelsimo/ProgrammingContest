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

const int MAXN = 50;
string num[MAXN] = {"I","II","III","IV","V","VI","VII","VIII","IX","X","XI","XII","XIII","XIV","XV","XVI","XVII",
"XVIII","XIX","XX","XXI","XXII","XXIII","XXIV","XXV","XXVI","XXVII","XXVIII","XXIX","XXX","XXXI","XXXII",
"XXXIII","XXXIV","XXXV","XXXVI","XXXVII","XXXVIII","XXXIX","XL","XLI","XLII","XLIII","XLIV","XLV","XLVI",
"XLVII","XLVIII","XLIX","L"};
class KingSort {
public:
   vector <string> getSortedList( vector <string> kings ) {
      vector<string> res;
      vector<pair<string,pair<int,string> > > temp;   
      string a, b;
      for(int i = 0; i < sz(kings); ++i) {
         istringstream in(kings[i]);
         in >> a >> b;
         temp.push_back(make_pair(a,make_pair(find(num,num+MAXN,b)-num,b)));
      }
      sort(all(temp));
      for(int i = 0; i < sz(temp); ++i)
         res.push_back(temp[i].first + " " + temp[i].second.second);
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
         string kings[]            = {"Louis IX", "Louis VIII"};
         string expected__[]       = {"Louis VIII", "Louis IX" };

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), KingSort().getSortedList( vector <string>( kings, kings + ( sizeof kings / sizeof(string) ) ) ) );
      }
      case 1: {
         string kings[]            = {"Louis IX", "Philippe II"};
         string expected__[]       = {"Louis IX", "Philippe II" };

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), KingSort().getSortedList( vector <string>( kings, kings + ( sizeof kings / sizeof(string) ) ) ) );
      }
      case 2: {
         string kings[]            = {"Richard III", "Richard I", "Richard II"};
         string expected__[]       = {"Richard I", "Richard II", "Richard III" };

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), KingSort().getSortedList( vector <string>( kings, kings + ( sizeof kings / sizeof(string) ) ) ) );
      }
      case 3: {
         string kings[]            = {"John X", "John I", "John L", "John V"};
         string expected__[]       = {"John I", "John V", "John X", "John L" };

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), KingSort().getSortedList( vector <string>( kings, kings + ( sizeof kings / sizeof(string) ) ) ) );
      }
      case 4: {
         string kings[]            = {"Philippe VI", "Jean II", "Charles V", "Charles VI", "Charles VII", "Louis XI"};
         string expected__[]       = {"Charles V", "Charles VI", "Charles VII", "Jean II", "Louis XI", "Philippe VI" };

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), KingSort().getSortedList( vector <string>( kings, kings + ( sizeof kings / sizeof(string) ) ) ) );
      }
      case 5: {
         string kings[]            = {"Philippe II", "Philip II"};
         string expected__[]       = {"Philip II", "Philippe II" };

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), KingSort().getSortedList( vector <string>( kings, kings + ( sizeof kings / sizeof(string) ) ) ) );
      }

      // custom cases

/*
      case 6: {
         string kings[]            = ;
         string expected__[]       = ;

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), KingSort().getSortedList( vector <string>( kings, kings + ( sizeof kings / sizeof(string) ) ) ) );
      }
*/
/*
      case 7: {
         string kings[]            = ;
         string expected__[]       = ;

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), KingSort().getSortedList( vector <string>( kings, kings + ( sizeof kings / sizeof(string) ) ) ) );
      }
*/
/*
      case 8: {
         string kings[]            = ;
         string expected__[]       = ;

         return verify_case( casenum__, starttime__, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof(string) ) ), KingSort().getSortedList( vector <string>( kings, kings + ( sizeof kings / sizeof(string) ) ) ) );
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
