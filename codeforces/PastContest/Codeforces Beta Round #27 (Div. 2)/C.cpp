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

typedef long long llong;

int a[100002], diff[100002];

int main(int argc, char *argv[]) {
   int N;
   cin >> N;
   for(int i = 0; i < N; ++i) {
	   cin >> a[i];
   }
   for(int i = 0; i < N - 1; ++i) {
	   diff[i] = a[i + 1] - a[i];
	   DEBUG(diff[i]);
   }
   return 0;
}

