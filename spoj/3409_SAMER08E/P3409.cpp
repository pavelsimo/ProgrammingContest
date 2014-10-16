/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ SAMER08E C++ "Ad Hoc" */
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

int month_day[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int D, M, Y, C;
int PD, PM, PY, PC;


bool isleapy(int n) {
    if(n%400==0) return true;
    if(n%100==0) return false;
    if(n%4==0) return true;
    return false;
}

int main(int argc, char *argv[]) {  
    int N, days, sum;
    while(scanf("%d",&N)==1) {
        if(N==0) break;
        PD = PM = PY = PC = -1;
        days = sum = 0;
        for(int i = 0; i < N; ++i) {
            scanf("%d%d%d%d",&D,&M,&Y,&C);
            if(isleapy(Y)) month_day[2] = 29;
            if(PD >= 0) {
                int d = PD, m = PM, y = PY;
                ++d;
                if(d > month_day[m]) {
                    d = 1;
                    ++m;
                }
                if(m > 12) {
                    m = 1;
                    ++y;
                }
                if(d==D && M==m && y==Y) {
                    ++days;
                    sum+=C-PC;
                }
            }
            PD = D; PM = M; PY = Y; PC = C;
            month_day[2] = 28;
        }
        printf("%d %d\n",days,sum);
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
