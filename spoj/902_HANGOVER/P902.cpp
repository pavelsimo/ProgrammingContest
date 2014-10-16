/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ HANGOVER C++ "Ad Hoc" */
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

int main(int argc, char *argv[]) {
    double n;
    int res;
    while(scanf("%lf",&n)==1) {
        if(n==0.0) break;
        double d = 0.0;
        for(res = 0; d < n; ++res)
            d+=1.0/(res+2.0);
        printf("%d card(s)\n",res);
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
