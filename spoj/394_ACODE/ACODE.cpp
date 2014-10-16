#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

typedef long long LL;
const int maxn = 5010;
LL memo[maxn];
string s;

LL d(int k, int n) {
	if(k>=n) return 1LL;
	if(memo[k] >= 0) return memo[k];
	if(s[k] == '0') return 0;
	if(k+1 < n) {
		int c = ((s[k]-'0')*10)+(s[k+1]-'0');
		if(c >= 1 && c <= 26) 
			return memo[k] = d(k+1,n) + d(k+2,n);
	}
	return memo[k] = d(k+1,n);
}

int main(int argc, char *argv[]) {

	while(getline(cin,s)) {
      memset(memo,-1,sizeof(memo));        
		if(s[0]=='0') break;
		cout <<  d(0,s.size()) << endl;
	}
	return 0;
}
