/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  576  C++  "Ad Hoc, Brute Force" */
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

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

using namespace std;

int a[22];

bool cmp(const int a, const int b) {
	return a > b;
}

set<vector<int> > S;

int main(int argc, char *argv[]) {
	int n, m;
	while(2 == scanf("%d%d",&n,&m)) {
		if(!n && !m) break;
		S.clear();
		for(int i = 0; i < m; ++i)
			scanf("%d",&a[i]);
		sort(a, a + m, cmp);
		printf("Sums of %d:\n", n);
		for(int i = 0; i < (1 << m); ++i) {
			int sum = 0;
			for(int j = 0; j < m; ++j) {
				if(i & (1 << j)) 
					sum += a[j];
			}
			if(sum == n) {
				vector<int> ans;
				for(int j = 0; j < m; ++j) {
					if(i & (1 << j)) 
						ans.push_back(-a[j]);
				}
				if(!S.count(ans))
					S.insert(ans);
			}
		}
		if(!S.size()) {
			printf("NONE\n");
		} else {
			foreach(it, S) {
				vector<int> ans = *it;
				for(int j = 0; j < sz(ans); ++j) {
					if(j > 0) putchar('+');
					printf("%d", -ans[j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
