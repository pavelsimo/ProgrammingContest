#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
	int t;cin>>t;
	for(int a=1; a<=t; ++a) {
		ll n,k;
		cin>>n>>k;
		ll m = (1LL<<n)-1;
		bool r=0;
		if ((k&m)==m) r=1;
		cout<<"Case #"<<a<<": "<<(r?"ON":"OFF")<<'\n';
	}
}
