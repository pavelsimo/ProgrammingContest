/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  343  C++  "Ad Hoc, Base Conversion" */
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

int radix(const string &s, const int base) {
	int n = s.size(), res=0, b=1, ch;
	for(int i = n-1; i >= 0; --i) {
		ch = isalpha(s[i])? s[i]-'A'+10: s[i]-'0';
		if(ch >= base) return -1;
		res+=ch*b;
		b*=base;
	}
	return res;
}

int main(int argc, char *argv[]) {
	string buf, a, b;
	bool found;
	while(getline(cin,buf)) {
		found = false;
		istringstream in(buf);
		in >> a >> b;
		int i, j;
		for(i = 2; i <= 36; ++i) {
			int x = radix(a,i);
			if(x<0) continue;
			for(j = 2; j <= 36; ++j) {
				int y = radix(b,j);
				if(y<0) continue;
				if(x==y) {
					found = true;
					break;
				}
			}
			if(found) break;
		}
		if(found) printf("%s (base %d) = %s (base %d)\n",a.c_str(),i,b.c_str(),j);
		else printf("%s is not equal to %s in any base 2..36\n",a.c_str(),b.c_str());
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

