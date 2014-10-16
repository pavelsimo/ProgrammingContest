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

#define BUFFER_SIZE 2048
#define SIZE 80

int main(int argc, char *argv[]) {

	int TC;
	char buf[BUFFER_SIZE];
	char country[SIZE];
	char name[
	char *token;
	scanf("%d\n",&TC);
	while ( TC-- > 0 ) {
		gets(buf);
		token = strtok(buf, " ");
		for(int i = 0; token != NULL; ++i) {
			if ( i == 0 ) 
			printf("%s\n",token);
			token = strtok(NULL, " ");        
		}
	}

	return 0;
}
