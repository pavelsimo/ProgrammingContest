/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  443  C++  "Ad Hoc, Number Theory" */
#include <iostream>
#include <cstring> 
#include <set>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

const int maxn = 5842;
typedef long long LL;
typedef pair<LL,int> node;
LL dp[maxn+10];

int main(int argc, char *argv[]) {
	priority_queue<node, vector<node>, greater<node> > Q;
	Q.push(make_pair(1LL,2));
	for(int i = 1; i <= maxn; ++i) {
      node cur = Q.top();
		Q.pop();
		switch(cur.second) {
			case 2: Q.push(make_pair(cur.first*2LL,2));
			case 3: Q.push(make_pair(cur.first*3LL,3));
			case 5: Q.push(make_pair(cur.first*5LL,5));
			case 7: Q.push(make_pair(cur.first*7LL,7));
      }
		dp[i] = cur.first;
   }
	int n;
	string s;
	while(scanf("%d",&n)==1) {
		if(n==0) break;
		s ="";
		if((n%100)>=11 && (n%100)<=13) s="th";
      else if((n%10)==1) s="st";
		else if((n%10)==2) s="nd";
		else if((n%10)==3) s="rd";
		else s = "th";
		printf("The %d%s humble number is %lld.\n",n,s.c_str(),dp[n]);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

