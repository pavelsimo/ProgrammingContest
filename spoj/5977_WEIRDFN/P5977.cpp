/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ WEIRDFN C++ "Ad Hoc, Priority Queue, Median" */
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
 
using namespace std;
 
#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
 
typedef long long llong;
 
const int MAXN = 200010;
llong F[MAXN];

int main(int argc, char *argv[]) {
	int TC, n; 
	llong a, b, c, res;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%lld%lld%lld%d",&a,&b,&c,&n);
		priority_queue<int> L;
		priority_queue<int, vector<int>, greater<int> > R;
		F[1] = 1LL;
		res = F[1];
		L.push(F[1]);
		for(int i = 2; i <= n; ++i) {
			if((a*L.top() + b*llong(i) + c) >= 1000000007)
				F[i] = (a*L.top() + b*llong(i) + c)%1000000007;
			else
				F[i] = (a*L.top() + b*llong(i) + c);
			res+=F[i];
			if(!R.empty() && F[i] > R.top())
				R.push(F[i]);
			else
				L.push(F[i]);
			if(sz(L) > sz(R)+1) {
				R.push(L.top());
				L.pop();
			} else if(sz(R) > sz(L)) {
				L.push(R.top());
				R.pop();
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
