/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11385  C++  "Ad Hoc" */
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>

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

int F[110];
string buf, token;
hash_map<int,int> fib;

int main(int argc, char *argv[]) {

	int a=2, b=1, nxt=0;
	fib[b] = 1;
	fib[a] = 2;
	for(int i = 3; i < 46; ++i) { 
		nxt = a+b;
		fib[nxt] = i;
		b = a;
		a = nxt;
	}
	
	int TC, N, M;
	getline(cin,buf);
	sscanf(buf.c_str(),"%d",&TC);
	
	while(TC-- > 0) {
		getline(cin,buf);
		sscanf(buf.c_str(),"%d",&N);
		getline(cin,buf);
		istringstream ncin2(buf);
		M=0;
		for(int i=0; i < N; ++i) {
		   getline(ncin2, token, ' ');
		   istringstream(token) >> F[i];
		   M = max(M,F[i]);
		}
		string ans(fib[M],' ');
		getline(cin,buf);
		for(int i=0,j=0; i < buf.size(); ++i) {
			if(isupper(buf[i])) {
				if(j>=N) break;
				ans[fib[F[j++]]-1] = buf[i];
			}
		}
		puts(ans.c_str());
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

