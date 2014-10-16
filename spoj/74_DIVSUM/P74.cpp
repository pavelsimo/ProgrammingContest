/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ DIVSUM C++ "Math, Number Theory, Primes, Sieve" */
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

const int MAXN = 500020;
int D[MAXN];

void sieve(int n) {
    D[1] = 0;
    D[0] = 0;    
    for(int i = 2; i < n; ++i) D[i] = 1;
    for(int i = 2; i < n; ++i) {
        for(int j = i + i; j < n; j+=i) D[j]+=i;
    }
}

int main(int argc, char *argv[]) {
    sieve(500010);
    int TC, n;
    scanf("%d",&TC);
    while(TC-- > 0) {
        scanf("%d",&n);
        printf("%d\n",D[n]);
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
