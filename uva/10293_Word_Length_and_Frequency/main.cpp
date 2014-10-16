#include <iostream>
#include <cstring> 
#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

#define N 32
int A[N];

int is_letter(const char c) {
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? 1: 0;
}

void solve(const string &s) {
	int t=0;
	memset(A,0,sizeof(A));
	for(int i = 0; i < s.size(); ++i) {
		if (is_letter(s[i])) {
			while (i < s.size()) {
				if(s[i]=='\'' || s[i]=='-' ) {
					i++;
					continue;
				}
				if(!is_letter(s[i])) break;
				t++;
				i++;
			}
			A[t]++;
			t=0;
		}
	}
	for(int i = 0; i < N; ++i)
		if ( A[i] != 0 ) 
			printf("%d %d\n",i,A[i]);
	printf("\n");
}

int main(int argc, char *argv[]) {
	string buffer;
	string text = "";
	while( getline(cin,buffer) ) {
		if ( buffer == "#" ) {
			solve(text);
			text = "";
		}
		if ( buffer[buffer.size()-1] != '-' )
			text+= buffer + " ";
		else
			text+= buffer;
	}
	return 0;
}
