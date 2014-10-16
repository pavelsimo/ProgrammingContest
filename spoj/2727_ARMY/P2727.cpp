/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ ARMY C++ "Ad Hoc" */
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
    int TC, NG, NM, g_army, m_army, power;
    scanf("%d",&TC);
    while(TC-- > 0) {
        scanf("%d%d",&NG,&NM);
        g_army = m_army = 0;
        while(NG-- > 0) {
            scanf("%d",&power);
            g_army = max(g_army,power);
        }
        while(NM-- > 0) {
            scanf("%d",&power);
            m_army = max(m_army,power);            
        }
        if(g_army >= m_army) puts("Godzilla");
        else puts("MechaGodzilla");
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
