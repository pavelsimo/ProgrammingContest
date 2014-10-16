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

int main() {
	set<int> a;
	for(int i = 1; i <= 510; ++i)
		a.insert((i*(i+1))/2);
	int n;
	while(scanf("%d",&n)==1) {
		if(a.count(n) > 0) puts("YES");
		else puts("NO");
	}
   return 0;
}
