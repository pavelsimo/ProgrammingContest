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
#define pb push_back

class DisjointSet {
   size_t _n;
   size_t _size;
public:
   vector<int>    parent;
   vector<size_t> rank;
 
   DisjointSet(size_t n);
   size_t size() const;
   int find_rep(int u);
   bool union_rep(int u, int v);
};
 
DisjointSet::DisjointSet(size_t n) : _n(n), _size(n) {
   parent = vector<int>(_n, -1);
   rank   = vector<size_t>(_n, 0);
}
 
inline size_t DisjointSet::size() const {
   return _size;	
}
 
int DisjointSet::find_rep(int u) {
   // path compresion
   return parent[u] < 0 ? u : parent[u] = find_rep(parent[u]);
}
 
bool DisjointSet::union_rep(int u, int v) {
   int u_root = find_rep(u);
   int v_root = find_rep(v);
   if (u_root == v_root)
      return false;
   int u_rank = rank[u_root];
   int v_rank = rank[v_root];
   if (u_rank > v_rank)
      parent[v_root] = u_root;
   else {
      parent[u_root] = v_root;
      if (u_rank == v_rank)
         rank[v_root] = rank[u_root] + 1;
   }
   --_size;
   return true;
}

struct Edge {
   int u, v;
   double cost;
   Edge(int _u, int _v, double _cost) : u(_u), v(_v), cost(_cost) {}
};
 
class cmp {
public:
   bool operator()(const Edge& e1, const Edge& e2) {
      if (e1.cost != e2.cost) return e1.cost < e2.cost;
      if (e1.u != e2.u) return e1.u < e2.u;
      return e1.v < e2.v;
   }
};

vector<Edge> edges;
typedef long long llong;

class KingdomXCitiesandVillagesAnother {
public:

   
   double determineLength( vector <int> cityX, vector <int> cityY, vector <int> villageX, vector <int> villageY ) {
      double res = 0.0;
      int N = sz(villageX);
      int M = sz(cityX);
      vector<llong> X, Y;
      edges.clear();
      for(int i = 0; i < M; ++i) {
         X.push_back(cityX[i]);
         Y.push_back(cityY[i]);
      }
      for(int i = 0; i < N; ++i) {
         X.push_back(villageX[i]);
         Y.push_back(villageY[i]);
      }
      for(int i = 0; i < sz(X); ++i) {
         for(int j = 0; j < sz(X); ++j) {
            if(i==j) continue;
            double dist = 0.0;
            if(i >= M || j >= M)
               dist=sqrt((X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]));
            Edge cur(i,j,dist);   
            edges.push_back(cur);
         }
      }
      sort(edges.begin(),edges.end(),cmp());
      DisjointSet dset(sz(X));
      for(int i = 0; i < sz(edges) && sz(dset) > 1; ++i) {
         if(dset.union_rep(edges[i].u,edges[i].v))
            res+=edges[i].cost;
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
   
   long long get_time() {
#if defined(_SYS_TIME_H_) || defined(_SYS_TIME_H)
      struct timeval tv;
      gettimeofday(&tv, NULL);
      return tv.tv_sec * 1000000LL + tv.tv_usec;
#else
      return 0;
#endif
   }
   int verify_case( int casenum, long long starttime, const double &expected, const double &received ) {
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
         int cityX[]               = {1};
         int cityY[]               = {1};
         int villageX[]            = {2,3};
         int villageY[]            = {1,1};
         double expected__         = 2.0;

         return verify_case( casenum__, starttime__, expected__, KingdomXCitiesandVillagesAnother().determineLength( vector <int>( cityX, cityX + ( sizeof cityX / sizeof(int) ) ), vector <int>( cityY, cityY + ( sizeof cityY / sizeof(int) ) ), vector <int>( villageX, villageX + ( sizeof villageX / sizeof(int) ) ), vector <int>( villageY, villageY + ( sizeof villageY / sizeof(int) ) ) ) );
      }
      case 1: {
         int cityX[]               = {1,2};
         int cityY[]               = {1,1};
         int villageX[]            = {1,2};
         int villageY[]            = {2,2};
         double expected__         = 2.0;

         return verify_case( casenum__, starttime__, expected__, KingdomXCitiesandVillagesAnother().determineLength( vector <int>( cityX, cityX + ( sizeof cityX / sizeof(int) ) ), vector <int>( cityY, cityY + ( sizeof cityY / sizeof(int) ) ), vector <int>( villageX, villageX + ( sizeof villageX / sizeof(int) ) ), vector <int>( villageY, villageY + ( sizeof villageY / sizeof(int) ) ) ) );
      }
      case 2: {
         int cityX[]               = {0};
         int cityY[]               = {0};
         int villageX[]            = {2};
         int villageY[]            = {2};
         double expected__         = 2.8284271247461903;

         return verify_case( casenum__, starttime__, expected__, KingdomXCitiesandVillagesAnother().determineLength( vector <int>( cityX, cityX + ( sizeof cityX / sizeof(int) ) ), vector <int>( cityY, cityY + ( sizeof cityY / sizeof(int) ) ), vector <int>( villageX, villageX + ( sizeof villageX / sizeof(int) ) ), vector <int>( villageY, villageY + ( sizeof villageY / sizeof(int) ) ) ) );
      }

      // custom cases


      case 3: {
         int cityX[]               = {920978};
         int cityY[]               = {375185};
         int villageX[]            = {228692};
         int villageY[]            = {991009};
         double expected__         = 926552.2676956762;

         return verify_case( casenum__, starttime__, expected__, KingdomXCitiesandVillagesAnother().determineLength( vector <int>( cityX, cityX + ( sizeof cityX / sizeof(int) ) ), vector <int>( cityY, cityY + ( sizeof cityY / sizeof(int) ) ), vector <int>( villageX, villageX + ( sizeof villageX / sizeof(int) ) ), vector <int>( villageY, villageY + ( sizeof villageY / sizeof(int) ) ) ) );
      }

/*
      case 4: {
         int cityX[]               = ;
         int cityY[]               = ;
         int villageX[]            = ;
         int villageY[]            = ;
         double expected__         = ;

         return verify_case( casenum__, starttime__, expected__, KingdomXCitiesandVillagesAnother().determineLength( vector <int>( cityX, cityX + ( sizeof cityX / sizeof(int) ) ), vector <int>( cityY, cityY + ( sizeof cityY / sizeof(int) ) ), vector <int>( villageX, villageX + ( sizeof villageX / sizeof(int) ) ), vector <int>( villageY, villageY + ( sizeof villageY / sizeof(int) ) ) ) );
      }
*/
/*
      case 5: {
         int cityX[]               = ;
         int cityY[]               = ;
         int villageX[]            = ;
         int villageY[]            = ;
         double expected__         = ;

         return verify_case( casenum__, starttime__, expected__, KingdomXCitiesandVillagesAnother().determineLength( vector <int>( cityX, cityX + ( sizeof cityX / sizeof(int) ) ), vector <int>( cityY, cityY + ( sizeof cityY / sizeof(int) ) ), vector <int>( villageX, villageX + ( sizeof villageX / sizeof(int) ) ), vector <int>( villageY, villageY + ( sizeof villageY / sizeof(int) ) ) ) );
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
