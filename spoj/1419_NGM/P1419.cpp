/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ NGM C++ "Ad Hoc" */
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
    int N;
    while(scanf("%d",&N)==1) {
        if(N%10==0) {
            printf("%d\n",2);
        } else {
            printf("%d\n",1);
            for(int i = 1; i <= 9; ++i) {
                if((N-i)%10==0) {
                    printf("%d\n",i);
                    break;
                }
            }
        }
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
