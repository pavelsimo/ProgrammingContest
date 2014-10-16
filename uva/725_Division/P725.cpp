/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  725  C++  "Brute Force, Simple Math" */
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
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)


int valid(char *abcde, char *fghij) {
	int n = strlen(fghij);
	int m = strlen(abcde);
	if(m > 5) return 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(fghij[i] == abcde[j]) return 0;
   for(int i = 0; i < m; ++i)
       for(int j = i+1; j < m; ++j)
			if(abcde[i] == abcde[j]) return 0;
	return 1;
}

int main() {
	int n, found;
	char fghij[16], abcde[16];
	int tc = 0;
	while(scanf("%d",&n)==1) {
		if(n==0) break;
		if(tc++!=0) printf("\n");
		found = 0;
		for(int f = 0; f <= 9; ++f) {
			for(int g = 0; g <= 9; ++g) {
				if(f == g) continue;
				for(int h = 0; h <= 9; ++h) {
					if(h == g || h == f) continue;
					for(int i = 0; i <= 9; ++i) {
						if(i == h || i == g || i == f) continue;
						for(int j = 0; j <= 9; ++j) {
							if(j == i || j == h || j == g || j == f) continue;
							sprintf(fghij,"%d%d%d%d%d",f,g,h,i,j);
							int y = atoi(fghij);
							int x = n*y;
							sprintf(abcde,"%05d",x);
							if(valid(abcde,fghij)) {
								printf("%s / %s = %d\n",abcde,fghij,n);
								found = 1;
							}
						}
					}
				}
			}
		}
		if(!found) printf("There are no solutions for %d.\n",n);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
