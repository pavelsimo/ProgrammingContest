#include <iostream>
#include <cmath>
#include <map>
#include <set>
using namespace std;

typedef long long llong;

map<llong,llong> square;

int main(int argc, char *argv[]) {
	
	for(llong i = 0LL; i < 46390LL; ++i)
		square[i*i] = i;	
	
	int TC, ans;
	llong x;
	set<llong> vis;
	cin >> TC;
	while(TC-- > 0) {
		cin >> x;
		vis.clear();
		llong M = (llong)sqrt(x);
		ans=0;
		for(llong k = M; k >= 0; --k) {
			llong a2 = k*k;
			llong b2 = x-a2;
			if(square.count(b2)>0) {
				if(vis.count(a2)==0 && vis.count(b2)==0) {
					ans++;
					vis.insert(a2);
					vis.insert(b2);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
