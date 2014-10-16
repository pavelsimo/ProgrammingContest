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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

typedef long long llong;

llong memo[502], DP[502];

// bottom-down memoization
llong f(int n) {
	if(n == 0) return 0;
	if(n == 1) return 1;
	if(memo[n] != -1) return memo[n];
	memo[n] = f(n-1) + f(n-2);
	return memo[n];
}

// top-down
llong f2(int n) {
	DP[0] = 0;
	DP[1] = 1;
	for(int i = 2; i <= n; ++i)
		DP[i] = DP[i-1] + DP[i-2];
	return DP[n];
}

int N;


// peso de los objectos
int W[] = {2, 10, 5, 8};

// valor de cada objecto
int V[] = {10, 4, 8, 20};

// 0 .. N-1
int rec(int n, int c) {
	if(n >= N) return 0;
	int res = 0;
	res = max(res, rec(n + 1, c));
	if(c >= W[n])
		res = max(res, rec(n + 1, c - W[n]) + V[n]);
	return res;
}

int main(int argc, char *argv[]) { 
   memset(memo, -1, sizeof(memo));
   DEBUG(f(52));   
   DEBUG(f2(52));   
   N = 4; // cantidad de objectos
   DEBUG(rec(0, 10));
   return 0;
}
