/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  355  C++  "Ad Hoc, Base Conversion" */
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
	int n = number.size();
	llong res=0LL, b=1LL, cur;
	for(int i = n-1; i >= 0; --i) {
		cur = isalpha(number[i]) ? number[i]-'A'+10: number[i]-'0';
		if(cur >= base) return -1LL;
		res+=cur*b;
		b*=base;
	}
	return res;
}

string radix(const llong n, const llong base) {
	string res="";
	llong x = n;
	while(x>0LL) {
		int d = x%base;
		res = digit[d] + res;
		x/=base;
	}
	return res=="" ? "0" : res;
}

int main(int argc, char *argv[]) {
	string buf, s;
	llong x, bsrc, bdst;
	while(getline(cin,buf)) {
		istringstream in(buf);
		in >> bsrc >> bdst >> s;
		x = ConvertToBase10(s,bsrc);
		if(x>=0LL)
			printf("%s base %lld = %s base %lld\n",s.c_str(),bsrc,radix(x,bdst).c_str(),bdst);
		else
			printf("%s is an illegal base %lld number\n",s.c_str(),bsrc);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

