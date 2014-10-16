/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ ANARC08E C++ "Ad Hoc" */
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
    int A, B;
    while(scanf("%d%d",&A,&B)==2) {
        if(A==-1 && B==-1) break;
        if(A==1 || B==1) printf("%d+%d=%d\n",A,B,A+B);
        else printf("%d+%d!=%d\n",A,B,A+B);
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
