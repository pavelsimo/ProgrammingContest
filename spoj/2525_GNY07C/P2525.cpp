/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ GNY07C C++ "Ad Hoc" */
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

int N, M;
const int MAXN = 256;
char a[MAXN][MAXN];
bool seen[MAXN][MAXN];
int dr[] = {+0,+1,+0,-1};
int dc[] = {+1,+0,-1,+0};

int decode(char ch) {
    if(isspace(ch)) return 0;
    return ch-'A'+1;
}

void doit(string &s) {
    memset(seen,false,sizeof(seen));
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            a[i][j] = '0';
    int r=0, c=0, d=0;
    for(int i = 0; i < sz(s); ++i) {
        int bit = decode(s[i]);
        for(int j = 4; j >= 0; --j) {
            bool ok = false;
            seen[r][c]=true;
            a[r][c]=(bit&(1<<j))?'1':'0';
            for(int k = 0; k < 4; ++k) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if(nr < 0 || nr >= N || nc < 0 || nc >= M || seen[nr][nc]) {
                    d=(d+1)%4;
                    continue;
                }
                r = nr; c = nc;
                ok = true;
                break;
            }
            if(!ok) break;
        }
    }
}

int main(int argc, char *argv[]) {
    string buf, s;
    int TC;
    getline(cin,buf);
    sscanf(buf.c_str(),"%d",&TC);
    for(int tc = 1; tc <= TC; ++tc) {
        getline(cin,buf);
        size_t p1 = buf.find(' ');
        size_t p2 = buf.find(' ',p1+1);
        sscanf(buf.substr(0,p1).c_str(),"%d",&N);
        sscanf(buf.substr(p1+1,p2-p1).c_str(),"%d",&M);
        s = buf.substr(p2+1);
        doit(s);
        printf("%d ",tc);
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                putchar(a[i][j]);
        putchar('\n');
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
