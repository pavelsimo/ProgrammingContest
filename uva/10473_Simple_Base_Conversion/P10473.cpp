/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10473  C++  "Ad Hoc, Base Conversion" */
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

string buf, digit = "0123456789ABCDEFGHIJK";

string ConvertToHexadecimal(const int n) {
	int x = n;
	string res = "";
	while(x>0) {
		int d = x%16;
		res = digit[d] + res;
		x/=16;
	}
	return res==""?"0":res;
}

int ConvertToDecimal(const string &number) {
	int n = number.size(), res=0, b=1, cur;
	for(int i = n-1; i >= 2; --i) {
		cur = isalpha(number[i])?number[i]-'A'+10:number[i]-'0';
		res+= cur*b;
		b*=16;
	}
	return res;
}

int main(int argc, char *argv[]) {
	int x;
	while(getline(cin,buf)) {
		if(buf[0]=='-') break;
		if(buf.size() > 1) {
			if(buf[0]=='0' && buf[1]=='x') printf("%d\n",ConvertToDecimal(buf));
			else printf("0x%s\n",ConvertToHexadecimal(atoi(buf.c_str())).c_str());
		} else {
			printf("0x%s\n",ConvertToHexadecimal(atoi(buf.c_str())).c_str());
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
