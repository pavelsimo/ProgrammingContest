/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  159  C++  "Ad Hoc" */

// PENDING
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
#include <list>
#include <utility>
using namespace std;


int main(int argc, char *argv[]) {
	string a,b,c,d;
	int ia, ib, ic, id;
	while(cin >> a >> b >> c >> d) {
		if(a=="#") break;
		ia=ib=ic=id=-1;
		for(int i = 0; i < a.size(); ++i) {
			bool found = false;
			for(int j = 0; j < b.size(); ++j) {
				if(a[i]==b[j]) {
					ia = i;
					ib = j;
					found=true;
					break;
				}
			}
			if(found)break;
		}
		for(int i = 0; i < c.size(); ++i) {
			bool found = false;
			for(int j = 0; j < d.size(); ++j) {
				if(c[i]==d[j]) {
					ic = i;
					id = j;
					found=true;
					break;
				}
			}
			if(found)break;
		}
		// print
		
		// DEBUG
		cout << a << " " << b << " " << c << " " << d << endl;
		cout << ia << " " << ib << " " << ic << " " << id << endl;
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

