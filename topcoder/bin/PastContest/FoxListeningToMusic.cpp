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


class FoxListeningToMusic {
public:
   vector <double> getProbabilities( vector <int> a, int T ) {
      int n = sz(a);
      vector<double> p(n);;
      double c = 1.0/n;
      for(int k = 0; k < T; ++k) {
         for(int i = 0; i < n; ++i) {
            p[i]+=c;
            for(int j = 0; j < n; ++j) {
               p[j]*=c;
            }  
         }
      }
      return p;
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
   
   static const double MAX_DOUBLE_ERROR = 1e-9;
   static bool topcoder_fequ( double expected, double result ) {
      if ( isnan( expected ) )
         return isnan( result );
      if ( isinf( expected ) )
         return expected > 0 ? result > 0 && isinf( result ) :
                               result < 0 && isinf( result );
      if ( isnan( result ) || isinf( result ) )
         return false;
      if ( fabs( result - expected ) < MAX_DOUBLE_ERROR )
         return true;
      return result > min(expected * (1.0 - MAX_DOUBLE_ERROR),
                          expected * (1.0 + MAX_DOUBLE_ERROR))
          && result < max(expected * (1.0 - MAX_DOUBLE_ERROR),
                          expected * (1.0 + MAX_DOUBLE_ERROR));
   }
   double moj_relative_error( double expected, double result ) {
      if ( isnan( expected ) || isinf( expected ) ||
           isnan( result ) || isinf( result ) || expected == 0 )
         return 0;
      return fabs( result-expected ) / fabs( expected );
   }
   static bool topcoder_fequ( const vector<double> &a, const vector<double> &b ) {
      if ( a.size() != b.size() ) return false;
      for ( size_t i=0; i<a.size(); ++i )
         if ( !topcoder_fequ( a[i], b[i] ) )
            return false;
      return true;
   }
   double moj_relative_error( const vector<double> &expected, const vector<double> &result ) {
      double ret = 0.0;
      for ( size_t i=0; i<expected.size(); ++i )
         ret = max( ret, moj_relative_error( expected[i], result[i] ) );
      return ret;
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

   long long get_time() {
#if defined(_SYS_TIME_H_) || defined(_SYS_TIME_H)
      struct timeval tv;
      gettimeofday(&tv, NULL);
      return tv.tv_sec * 1000000LL + tv.tv_usec;
#else
      return 0;
#endif
   }
   int verify_case( int casenum, long long starttime, const vector <double> &expected, const vector <double> &received ) {
      cerr << "Example " << casenum << "... "; 
      cerr.precision(9); 
      if ( topcoder_fequ( expected, received ) ) {
         cerr << "PASSED"; 
#if defined(_SYS_TIME_H_) || defined(_SYS_TIME_H)
         cerr << "  " << (get_time()-starttime)/1000 << "ms";
#endif
         double rerr = moj_relative_error( expected, received ); 
         if ( rerr > 0 ) cerr << "  (rerr " << rerr << ")";
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
         int length[]              = {1, 2};
         int T                     = 1;
         double expected__[]       = {0.25, 0.75 };

         return verify_case( casenum__, starttime__, vector <double>( expected__, expected__ + ( sizeof expected__ / sizeof(double) ) ), FoxListeningToMusic().getProbabilities( vector <int>( length, length + ( sizeof length / sizeof(int) ) ), T ) );
      }
      case 1: {
         int length[]              = {1, 10, 100, 1000, 10000};
         int T                     = 0;
         double expected__[]       = {0.2, 0.2, 0.2, 0.2, 0.2 };

         return verify_case( casenum__, starttime__, vector <double>( expected__, expected__ + ( sizeof expected__ / sizeof(double) ) ), FoxListeningToMusic().getProbabilities( vector <int>( length, length + ( sizeof length / sizeof(int) ) ), T ) );
      }
      case 2: {
         int length[]              = {5, 8, 4, 7};
         int T                     = 10;
         double expected__[]       = {0.1875, 0.3125, 0.1875, 0.3125 };

         return verify_case( casenum__, starttime__, vector <double>( expected__, expected__ + ( sizeof expected__ / sizeof(double) ) ), FoxListeningToMusic().getProbabilities( vector <int>( length, length + ( sizeof length / sizeof(int) ) ), T ) );
      }
      case 3: {
         int length[]              = {10, 1};
         int T                     = 9;
         double expected__[]       = {0.9990234375, 9.765625E-4 };

         return verify_case( casenum__, starttime__, vector <double>( expected__, expected__ + ( sizeof expected__ / sizeof(double) ) ), FoxListeningToMusic().getProbabilities( vector <int>( length, length + ( sizeof length / sizeof(int) ) ), T ) );
      }
      case 4: {
         int length[]              = {58, 47, 36, 25, 14, 3};
         int T                     = 100;
         double expected__[]       = {0.32895835374381194, 0.26291497538241776, 0.18463894970453887, 0.1312301113062895, 0.07518634032025856, 0.017071269542683242 };

         return verify_case( casenum__, starttime__, vector <double>( expected__, expected__ + ( sizeof expected__ / sizeof(double) ) ), FoxListeningToMusic().getProbabilities( vector <int>( length, length + ( sizeof length / sizeof(int) ) ), T ) );
      }

      // custom cases

/*
      case 5: {
         int length[]              = ;
         int T                     = ;
         double expected__[]       = ;

         return verify_case( casenum__, starttime__, vector <double>( expected__, expected__ + ( sizeof expected__ / sizeof(double) ) ), FoxListeningToMusic().getProbabilities( vector <int>( length, length + ( sizeof length / sizeof(int) ) ), T ) );
      }
*/
/*
      case 6: {
         int length[]              = ;
         int T                     = ;
         double expected__[]       = ;

         return verify_case( casenum__, starttime__, vector <double>( expected__, expected__ + ( sizeof expected__ / sizeof(double) ) ), FoxListeningToMusic().getProbabilities( vector <int>( length, length + ( sizeof length / sizeof(int) ) ), T ) );
      }
*/
/*
      case 7: {
         int length[]              = ;
         int T                     = ;
         double expected__[]       = ;

         return verify_case( casenum__, starttime__, vector <double>( expected__, expected__ + ( sizeof expected__ / sizeof(double) ) ), FoxListeningToMusic().getProbabilities( vector <int>( length, length + ( sizeof length / sizeof(int) ) ), T ) );
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
