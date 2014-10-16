#include <cstring>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
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
using namespace std;

char buf[3][64];
int n = 6;
string a[6] = {"ABC","ACB","BAC","BCA","CAB","CBA"};

bool compare(string &s, char A, char B, char opt) {
	int x = s.find(A);
	int y = s.find(B);
   if(opt=='>') return x > y;
   return x < y;
}

int main() {
	gets(buf[0]);
	gets(buf[1]);
	gets(buf[2]);
	bool found = false;
	for(int i = 0; i < n; ++i) {
		bool ok = true;
      for(int j = 0; j < 3; ++j) {
			if(!compare(a[i],buf[j][0],buf[j][2],buf[j][1])) {
				ok = false;
				break;
			}
		}
		if(ok) {
			cout << a[i] << endl;
			found=true;
			break;
		}
	}
	if(!found) cout << "Impossible" << endl;
   return 0;
}
