/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11056  C++  "Ad Hoc, Sorting" */
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
#include <list>
#include <utility>
using namespace std;

struct Racer {
	char name[32];
	int min, sec, ms;
	Racer(int _min=0, int _sec=0, int _ms=0) : 
		min(_min), sec(_sec), ms(_ms){}
	bool operator< (const Racer &T) const {
		if(min!=T.min) return min < T.min;
		if(sec!=T.sec) return sec < T.sec;
		if(ms!=T.ms) return ms < T.ms;
		return strcasecmp(name,T.name) < 0;
	}
};

int N;
char buf[1024], name[32];
const int maxn = 110;
Racer a[maxn];

int main(int argc, char *argv[]) {
	int min, sec, ms;
	while(gets(buf)) {
		sscanf(buf,"%d",&N);
		for(int i = 0; i < N; ++i) {
         gets(buf);
			sscanf(buf,"%s : %d min %d sec %d ms",&a[i].name,&a[i].min,&a[i].sec,&a[i].ms);
		}
		gets(buf);
		sort(a,a+N);
		for(int i=0, j=0; i < N; ++i) {
			if(i%2==0) printf("Row %d\n",++j);
			printf("%s\n",a[i].name);
		}
		putchar('\n');
	}	
	return 0;
}
/* @END_OF_SOURCE_CODE */

