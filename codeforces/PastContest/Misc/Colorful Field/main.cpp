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
using namespace std;

typedef vector<int> VI;

const char *fruits[] = {
	"Carrots", "Kiwis", "Grapes"
};

VI A;

int main() {
	int n, m, k, t, r, c;
	scanf("%d%d%d%d",&n,&m,&k,&t);
	for(int i = 0; i < k; ++i) {
		scanf("%d%d",&r,&c);
		int p = (r-1)*m+c;
		A.push_back(p);
	}
	sort(A.begin(),A.end());
	for(int i = 0; i < t; ++i) {
		scanf("%d%d",&r,&c);
		int p = (r-1)*m+c;
		if(binary_search(A.begin(),A.end(),p)) {
			puts("Waste");
		} else {
			int d = int(lower_bound(A.begin(),A.end(),p) - A.begin());
			int q = (p-d-1)%3;
			puts(fruits[q]);
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
