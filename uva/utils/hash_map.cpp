#include <iostream>
#include <string>
#include <map>
 
using namespace std;
 
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
 
// ============================================================================
// Hash
// ============================================================================
 
#ifdef __GNUC__
#if (__GNUC__ <= 2)
  #include <hash_map>
  using std::hash_map;
#else
  #include <ext/hash_map>
  using __gnu_cxx::hash_map;
#endif
#else
//#elif _WIN32
  #include "stl_hash.h"
  using std::hash_map;
#endif
 
namespace __gnu_cxx {
   template<> struct hash< std::string > {
      size_t operator() ( const std::string& x ) const {
         return hash< const char* >()( x.c_str() );
      }
   };
 
   template<> struct hash< long long > {
      size_t operator()( const long long& x ) const {
         return (x >> 32) ^ hash< int >()( x & 0xFFFFFFFF );
      }
   };
 
   template<typename T1, typename T2>
   struct hash< pair<T1, T2> > {
      size_t operator() (const pair<T1, T2>& pr) const {
         return hash<T1>()(pr.first) ^ hash<T2>()(pr.second);
      }
   };
}
 
struct hash_long_long {
   size_t operator()(const long long in)  const {
      long long ret = (in >> 32L) ^ (in & 0xFFFFFFFF);
      return (size_t) ret;
   }
};
 
 
/*
struct djb_hash_string {
   size_t operator() ( const string& key ) const {
      size_t h = 0;
      for ( int i = 0; i < key.size(); ++i )
      // h = 33 * h + key[i];
         h = 33 * h ^ key[i];
      return h;
   }
};
 
struct rot_hash_string {
   size_t operator() ( const string& key ) const {
      size_t h = 0;
      for ( int i = 0; i < key.size(); ++i )
        h = ( h << 4 ) ^ ( h >> 28 ) ^ key[i];
      return h;
   }
};
 
struct sax_hash_string {
   size_t operator() ( const string& key ) const {
      size_t h = 0;
      for ( int i = 0; i < key.size(); ++i )
         h ^= ( h << 5 ) + ( h >> 2 ) + key[i];
      return h;
   }
};
 
struct fnv_hash_string {
   size_t operator() ( const string& key ) const {
      size_t h = 2166136261;
 
      for ( int i = 0; i < key.size(); ++i )
         h = ( h * 16777619 ) ^ key[i];
 
      return h;
   }
};
 
struct oat_hash_string {
   size_t operator() ( const string& key ) const {
      size_t h = 0;
 
      for ( int i = 0; i < key.size(); ++i ) {
         h += p[i];
         h += ( h << 10 );
         h ^= ( h >> 6 );
      }
 
      h += ( h << 3 );
      h ^= ( h >> 11 );
      h += ( h << 15 );
 
      return h;
   }
};
*/
 
int main() {
   hash_map< string, int, __gnu_cxx::hash<string> > hm1;
   hm1["cat"] = 3;
   hm1["dog"] = -7;
   hm1["horse"] = 1000000000;
   FOREACH(it, hm1)
      cout << it->first << ' ' << it->second << endl;
   cout << endl;
 
   hash_map< long long, int, __gnu_cxx::hash<long long> > hm2;
   hm2[ 1234567890123456LL ] = 10;
   hm2[ -2 ] = 333;
   FOREACH(it, hm2)
      cout << it->first << ' ' << it->second << endl;
   cout << endl;
 
   hash_map< pair<int,int>, int, __gnu_cxx::hash< pair<int,int> > > hm3;
   hm3[ pair<int,int>(1,3) ] = -1;
   hm3[ make_pair(-1, 0) ] = 10;
   hash_map< pair<int,int>, int, __gnu_cxx::hash< pair<int,int> > >::iterator nit = hm3.find(make_pair(-1,0));
   if(nit != hm3.end()) cout << "nit: " << nit->second << endl;
   FOREACH(it, hm3)
      cout << '(' << it->first.first << ',' << it->first.second << ')'
           << ' ' << it->second << endl;
   cout << endl;
 
   hash_map<long long, int, hash_long_long> hm4;
   hm4[ 1234567890123456LL ] = 10;
   hm4[ -2 ] = 333;
   FOREACH(it, hm4)
      cout << it->first << ' ' << it->second << endl;
   cout << endl;
 
   return 0;
}
