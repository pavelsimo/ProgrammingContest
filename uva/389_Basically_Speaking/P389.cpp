/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  389  C++  "Ad Hoc, Base Conversion" */
#include <iostream>
#include <cstring> 
#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
#include <bitset>
#include <utility>
using namespace std;

typedef long long llong;
string digit = "0123456789ABCDEFGHIJK";

llong ConvertToBase10(const string &number, const llong base) {
	llong res = 0LL, b=1LL, cur;
	int n = number.size();
	for(int i = n-1; i >= 0; --i) {
		cur=isalpha(number[i])?number[i]-'A'+10:number[i]-'0';
		if(cur>=base) return -1;
		res+=b*cur;
		b*=base;
	}
	return res;
}

string radix(const llong n, const llong base) {
	llong x = n;
	string res = "";
	while(x>0LL) {
		int d = x%base;
		res = digit[d] + res;
		x/=base;
	}
	return res==""?"0":res;
}

int main(int argc, char *argv[]) {
	string ans, buf, s;
	llong x, bsrc, bdst;
	while(getline(cin,buf)) {
		istringstream in(buf);
		in >> s >> bsrc >> bdst;
		x = ConvertToBase10(s,bsrc);
		ans = "ERROR";
		if(x>=0) {
			ans = radix(x,bdst);
			if(ans.size() < 8) printf("%7s\n",ans.c_str());
			else printf("%7s\n","ERROR");
		} else {
			printf("%7s\n","ERROR");
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
