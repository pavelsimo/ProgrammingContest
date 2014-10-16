/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11730 C++  "Graph Theory, BFS" */
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

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> node;
ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) { 
  _sieve_size = upperbound+1; 
  bs.reset(); bs.flip(); 
  bs.set(0, false); 
  bs.set(1, false);
  for (ll i = 2; i <= _sieve_size; i++) 
  if (bs.test((size_t)i)) {
    for (ll j = i * i; j <= _sieve_size; j += i) bs.set((size_t)j, false);
    primes.push_back((int)i);
  }
}

int bfs(int src, int dst) {
	set<int> vis;
	queue<node> q;
	q.push(make_pair(src,0));
	vis.insert(src);
	while(!q.empty()) {
		node cur = q.front();
		q.pop();
		if(cur.first == dst) return cur.second;
		if(cur.first > 1000) continue;
		for(int i = 0; i < primes.size(); ++i) {
         if(primes[i] > cur.first/2) break;
			if((cur.first%primes[i])==0) {
				int ns = cur.first+primes[i];
				if(vis.count(ns)==0) {
					vis.insert(ns);
					q.push(make_pair(ns,cur.second+1));
				}
			}
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	sieve(1000);
	int S, T, tc=0;
	while(scanf("%d%d",&S,&T)==2) {
		if(S==0||T==0) break;
		printf("Case %d: %d\n",++tc,bfs(S,T));
	}	
	return 0;
}
/* @END_OF_SOURCE_CODE */

