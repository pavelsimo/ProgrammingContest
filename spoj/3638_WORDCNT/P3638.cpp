/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ WORDCNT C++ "Ad Hoc" */
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
    int TC, res, cnt, prev;
    string s, word;
    getline(cin,s);
    sscanf(s.c_str(),"%d",&TC);
    while(TC-- > 0) {
        getline(cin,s);
        istringstream in(s);
        res=prev=cnt=0;
        while(in >> word) {
            if(prev==sz(word)) cnt++;
            else cnt = 1;
            res = max(res,cnt);
            prev = sz(word);
        }
        printf("%d\n",res);
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
