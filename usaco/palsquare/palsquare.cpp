/*
ID: 0000
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

int N = 300;
string digit = "0123456789ABCDEFGHIJK";

bool ispal(string &s) {
	int l = 0;
	int r = s.size()-1;
	while(l < r) {
		if(s[l]!=s[r]) 
			return false;
		l++;
		r--;
	}
	return true;
}

string radix(int n, int base) {
	int x=n, k=0;
	string ans("");
	while(x>0) {
		int d = x%base;
		ans = digit[d] + ans;
		x/=base;
	}
	return ans;
}


int main() {
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);
	int b;
	scanf("%d",&b);
	for(int i = 1; i <= N; ++i) {
		string num = radix(i*i,b);
		if(ispal(num))
			printf("%s %s\n",radix(i,b).c_str(),num.c_str());
	}
	return 0;
}
