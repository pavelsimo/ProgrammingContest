/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  353  C++  "String Manipulation */
#include <iostream>
#include <sstream>
#include <functional>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

int ispal(string &s) {
	int n = s.size();
	int m = n/2;
	if(n==1) return 1;
	FOR(i,0,m) 
		if(s[i]!=s[n-i-1]) 
			return 0;
	return 1;
}


int main(int argc, char *argv[]) {
	string buf;
	int ans;
	while(getline(cin,buf)) {
		set<string> vis;
		int n = buf.size();
		ans=0;
		for(int i = 0 ; i < n; ++i) {
			for(int j = i+1; j <= n; ++j) {
				string s = buf.substr(i,j-i);
				if(ispal(s) && vis.count(s)==0) {
					vis.insert(s);
					ans++;
				}
			}
		}
		printf("The string '%s' contains %d palindromes.\n",buf.c_str(),ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

