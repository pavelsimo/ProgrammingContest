/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ POLEVAL C++ "Math, Polynomial" */
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

const int MAXN = 1024;
int c[MAXN];

int main(int argc, char *argv[]) {
    int ndegree, k, tc = 0;
    llong x;
    while(scanf("%d",&ndegree)==1) {
        if(ndegree==-1) break;
        for(int i = 0; i <= ndegree; ++i)
            scanf("%d",&c[i]);
        scanf("%d",&k);
        printf("Case %d:\n",++tc);
        for(int i = 0; i < k; ++i) {
            scanf("%lld",&x);
            llong res = c[ndegree];
            llong powx = x;
            for(int j = ndegree-1; j >= 0; --j) {
                res+=powx*c[j];
                powx*=x;
            }
            printf("%lld\n",res);
        }
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
