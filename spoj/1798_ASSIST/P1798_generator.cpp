/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ ASSIST C++ "Ad Hoc, Simulation" */
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <deque>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <sys/time.h>
 
using namespace std;
 
#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
 
const int MAXN = 40000;
vector<bool> a;
 
 
int main(int argc, char *argv[]) {
	for(int i = 0; i <= MAXN; ++i)
		a.push_back(true);
	for(int i = 2; i < MAXN; ++i) {
		if(!a[i]) continue;
		int cnt = i;
		//DEBUG(cnt);
		for(int j = i + 1; j < MAXN; ++j) {
			if(!a[j]) continue;
			cnt--;
			if(cnt <= 0) {
				//DEBUG(j);
				a[j] = false;
				cnt = i;
			}
		}
	}
	int k = 0;
	for(int i = 2; i < MAXN; ++i) {
		if(a[i]) {
			printf("%d,",i);
			k++;
			if(k%10==0) putchar('\n');
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
