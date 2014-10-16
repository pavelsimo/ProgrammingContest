#include <iostream>
using namespace std;

typedef long long llong;

llong f(llong x, llong k) {
	if(k==0LL) return 1LL;
	if(k&1) {
		return ((f(x,k-1)%10)*(x%10))%10;
	} else {
		llong t = f(x,k>>1)%10;
		return (t*t)%10;
	}
}

int main(int argc, char *argv[]) {
	int TC;
	llong base, exp;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%lld%lld",&base,&exp);
		printf("%lld\n",f(base,exp));
	}
	return 0;
}
