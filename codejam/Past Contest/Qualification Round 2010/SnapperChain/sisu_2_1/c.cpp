#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

ll R,K,N;
ll gs[1<<16];
int next[1<<16];
int gett[1<<16];
int done[1<<16];
ll curs[1<<16];

int main()
{
	int t;cin>>t;
	for(int a=1; a<=t; ++a) {
		cin>>R>>K>>N;
		for(int i=0; i<N; ++i) cin>>gs[i];
		for(int i=0; i<N; ++i) {
			int c=0;
			int j;
			int g;
			for(j=i,g=0; c<=K && j-i<=N; ++j) c+=gs[j%N];
			next[i] = (j+N-1)%N;
//			gett[i] = g-1;
			gett[i] = c-gs[next[i]];
//			cout<<"get "<<g-1<<'\n';
//			cout<<"to "<<i<<' '<<next[i]<<'\n';
		}

		ll r=0;
		int i;
		memset(done,-1,sizeof(done));
		int c=0;
		for(i=0; i<R; ++i) {
			if (done[c]>=0) break;
			done[c]=i;
			curs[c]=r;
			r += gett[c];
			c = next[c];
//			cout<<"asd "<<r<<' '<<c<<'\n';
		}
		int s = R-i;
		int cc = i-done[c];
		ll rr = r-curs[c];
		int cnt = s/cc;
		i += cc*cnt;
		r += rr*cnt;
		for(; i<R; ++i) {
			r += gett[c];
			c = next[c];
		}
		cout<<"Case #"<<a<<": "<<r<<'\n';
	}
}
