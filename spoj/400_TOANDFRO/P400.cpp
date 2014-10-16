/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ TOANDFRO C++ "Ad Hoc" */
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
    int n;
    string s;
    while(getline(cin,s)) {
        sscanf(s.c_str(),"%d",&n);
        if(n==0) break;
        getline(cin,s);
        int d = 1;
        for(int i = 0; i < n; ++i) {
            putchar(s[i]);
            for(int j = i + 2*n - d; j < sz(s); j+=2*n - d) {
                putchar(s[j]);
                j+=d;
                if(j < sz(s)) putchar(s[j]);
            }
            d+=2;
        }
        putchar('\n');
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
