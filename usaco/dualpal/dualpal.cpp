/*
ID: 0000
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdio>

#define ctz(mask) ( __builtin_ctz((mask)) )
#define clz(mask) ( __builtin_clz((mask)) )

using namespace std;

string digit = "0123456789";

bool ispal(string &s) {
	int l = 0;
	int r = s.size()-1;
	if(s.size() > 1) {
		if(s[l]=='0') return false;
		if(s[r]=='0') return false;
	}
	while(l<r) {
		if(s[l]!=s[r]) return false;
		l++;
		r--;
	}
	return true;
}

string radix(int n, int b) {
	int x = n;
	string ans("");
	while(x>0) {
		int d = x%b;
		ans = digit[d] + ans;
		x/=b;
	}
	return ans;
}

int main() {
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);
	int N, S;
	scanf("%d%d",&N,&S);
	for(int i=1; N>0; ++i) {
		int cnt = 0;
		for(int b = 2; b <= 10; ++b) {
			string s = radix(S+i,b);
			if(ispal(s)) cnt++;
		}
		if(cnt>=2) {
			N--;
			printf("%d\n",S+i);
		}
	}
	return 0;
}
