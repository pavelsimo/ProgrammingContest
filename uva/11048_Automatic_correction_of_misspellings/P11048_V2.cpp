/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11048  C++  "Ad Hoc, String Manipulation" */
#include <iostream>
using namespace std;

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
}

const int INF = 100000000;

int main(int argc, char *argv[]) {	
	int N, M;
	string s;
	hash_map< string, int, __gnu_cxx::hash<string> > dict;
	getline(cin,s);
	sscanf(s.c_str(),"%d",&N);
	for(int i=0; i < N; ++i) {
		getline(cin,s);	
		dict[s]=i;
	}	
	getline(cin,s);
	sscanf(s.c_str(),"%d",&M);
	for(int i = 0; i < M; ++i) {
		getline(cin,s);
		if(dict.count(s)>0) {
			printf("%s is correct\n",s.c_str());
			continue;
		}
		int best = INF;
		string word = "";
		// delete
		for(int j = 0; j < s.size(); ++j) {
			string t = s;
			t.erase(t.begin()+j);
			if(dict.count(t)>0) {
				if(dict[t]<best) {
					best=dict[t];
					word=t;
				}
			}
		}
		for(char ch='a'; ch<='z'; ++ch) {
			// add
			for(int j = 0; j <= s.size(); ++j) {
				string t = s;
				t.insert(j,1,ch);
				if(dict.count(t)>0) {
					if(dict[t]<best) {
						best=dict[t];
						word=t;
					}
				}
			}
			// replace
			for(int j = 0; j < s.size(); ++j) {
				string t = s;
				t[j] = ch;
				if(dict.count(t)>0) {
					if(dict[t]<best) {
						best=dict[t];
						word=t;
					}
				}
			}
		}
		// swap
		for(int j = 0; j < s.size()-1; ++j) {
			string t = s;
			char c = t[j];
			t[j] = t[j+1];
			t[j+1] = c;
			if(dict.count(t)>0) {
				if(dict[t]<best) {
					best=dict[t];
					word=t;
				}
			}
		}
		if(best==INF) printf("%s is unknown\n",s.c_str());
		else printf("%s is a misspelling of %s\n",s.c_str(),word.c_str());
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */



