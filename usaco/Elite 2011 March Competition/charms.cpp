/*
ID: 11
PROG: charms
LANG: C++
*/
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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define pb push_back

int main() {
    freopen("charms.in", "r", stdin);
	 freopen("charms.out", "w", stdout);
    int L, C, N, S, P;
    scanf("%d%d%d",&L,&C,&N);
    for(int i = 0; i < C; ++i) {
       scanf("%d%d",&S,&P);
       printf("%d\n",abs(N-P)+S);
    }
    return 0;
}
