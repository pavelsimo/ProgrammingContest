#include <cstring>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
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

const int maxn = 52;
int B[maxn][maxn];
const int INF = 100000000;

int main() {
	int n, m, a, b;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf("%d",&B[i][j]);
		}
	}
	scanf("%d%d",&a,&b);
	int ans = INF;
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= m; ++j) {
			int cnt = 0;
			bool found=false;
			for(int ii = i; ii < i+a; ++ii) {
				if(i+a>n || j+b>m) break;
				for(int jj = j; jj < j+b; ++jj) {
					cnt+=B[ii][jj];
					found=true;
				}
			}
			if(found) ans=min(ans,cnt);
			cnt=0;
			found=false;
			for(int ii = i; ii < i+b; ++ii) {
				if(i+b>n || j+a>m) break;
				for(int jj = j; jj < j+a; ++jj) {
					cnt+=B[ii][jj];
					found=true;
				}
			}			
			if(found)ans=min(ans,cnt);
		}
	}
	printf("%d\n",ans);
   return 0;
}
