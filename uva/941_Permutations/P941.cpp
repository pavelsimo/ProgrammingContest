/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  941  C++  "Ad Hoc, Simple Math, Recursion" */
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long llong;

llong fact(int n) {
	llong ans = 1LL;
	for(int i = 1; i <= n; ++i)
		ans*=i;
	return ans;
}

int main(int argc, char *argv[]) {
	int TC, p;
	llong x, n;
	string s, t, ans;
	cin >> TC;
	while(TC-- > 0) {
		cin >> s >> n;
		n = n+1LL; x=0LL; p=s.size()-1;
		sort(s.begin(),s.end());      
		t = s; ans = "";
		for(int i=s.size(); i>= 1; --i) {	
			int nxt = 0;
			for(int j = 0; j < i; ++j) {
				llong q = fact(p);
				if(x+q>=n) break;
				nxt++;
				x+=q;
			}
			ans+=t[nxt];
			t.erase(t.begin()+nxt);
			p--;
		}
		printf("%s\n",ans.c_str());
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
