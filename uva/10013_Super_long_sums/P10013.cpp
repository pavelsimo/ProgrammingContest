/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10013 C++  "Math, Factorial" */
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
#include <bitset>
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

int main(int argc, char *argv[]) {
	int TC, n, a, b;
	queue<int> q;
	scanf("%d",&TC);
	for(int tc=0; tc<TC;++tc) {
      if(tc>0) putchar('\n');
		scanf("%d\n",&n);
		while(n-- > 0) {
			scanf("%d%d",&a,&b);
			int d = a+b;
			if(d>9) {
				while(!q.empty()) {
					int cur = (q.front()+1)%10;
					printf("%d",cur);
					q.pop();
				}
			} else if(d<9) {
				while(!q.empty()) {
					printf("%d",q.front());
					q.pop();
				}
			}
			q.push(d%10);
		}
		while(!q.empty()) {
			printf("%d",q.front());
			q.pop();
		}
		putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

