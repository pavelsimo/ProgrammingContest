/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ GNY07D C++ "Ad Hoc" */
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

const int MAXN = 1024;
char a[MAXN][MAXN];
bool seen[MAXN][MAXN];
int N, M;
int dr[] = {+0,+1,+0,-1};
int dc[] = {+1,+0,-1,+0};

char encode(int x) {
    if(x==0) return ' ';
    return 'A'+x-1;
}

void decode() {
    memset(seen,false,sizeof(seen));
    int r=0, c=0, d=0, b=4, x=0;
    bool ok = true;
    while(true) {
        seen[r][c] = true;
        if(b < 0) {
            putchar(encode(x));
            x=0; b=4;
        }
        x = (a[r][c]-'0') ? x|(1<<b): x;
        b--;
        if(!ok) break;
        ok = false;
        for(int k = 0; k < 4; ++k) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M || seen[nr][nc]) {
                d=(d+1)%4;
                continue;
            }
            ok = true;
            r = nr; c = nc;
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    string buf, s, t;
    int TC;
    getline(cin,buf);
    sscanf(buf.c_str(),"%d",&TC);
    for(int tc = 1; tc <= TC; ++tc) {
        getline(cin,buf);
        istringstream in(buf);
        in >> N >> M >> s;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                a[i][j] = s[i*M+j];
        printf("%d ",tc);
        decode();
        putchar('\n');
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
