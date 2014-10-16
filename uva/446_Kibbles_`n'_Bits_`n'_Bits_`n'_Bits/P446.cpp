/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  446  C++  "Ad Hoc, Base Conversion" */
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

string buf, a, b, opt;

string ConvertToBinary(const int n) {
	string res = "";
	for(int i = 12; i >= 0; --i) {
		if(n&(1<<i)) res+='1';
		else res+='0';
	}
	return res;
}

int ConvertToBase10(const string &number) {
	int n = number.size(), b=1, res=0, cur;
	for(int i = n-1; i >= 0; --i) {
		cur=isalpha(number[i])?number[i]-'A'+10:number[i]-'0';
		res+=cur*b;
		b*=16;
	}
	return res;
}

int main(int argc, char *argv[]) {
	int TC, x, y, ans;
	getline(cin,buf);
	sscanf(buf.c_str(),"%d",&TC);
	while(TC-- > 0) {
		getline(cin,buf);
		istringstream in(buf);
		in >> a >> opt >> b;
		x = ConvertToBase10(a);
		y = ConvertToBase10(b);
		switch(opt[0]) {
			case '+': ans = x + y; break;
			case '-': ans = x - y; break;
		}
		printf("%s %c %s = %d\n",ConvertToBinary(x).c_str(),opt[0],ConvertToBinary(y).c_str(),ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
