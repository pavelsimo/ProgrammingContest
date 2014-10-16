/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ POUR1 C++ "Graph Theory, BFS" */
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

typedef pair<int,int> PII;

struct State {
    int a, b, dist;
    State(int _a = 0, int _b = 0, int _dist = 0) :
        a(_a), b(_b), dist(_dist) { }
};

bool D[200005];
State nxt[10];

int bfs(int a, int b, int c) {
    memset(D,false,sizeof(D));
    if(a < c && b < c) return -1;
    queue<State> Q;
    Q.push(State(0,0,0));
    D[0] = true;
    while(!Q.empty()) {
        State cur = Q.front();
        Q.pop();
        if(cur.a == c || cur.b == c)
            return cur.dist;
        int CA = a - cur.a;
        int CB = b - cur.b;
        nxt[0] = State(0,cur.b,cur.dist + 1); // empty vessel A
        nxt[1] = State(cur.a,0,cur.dist + 1); // empty vessel B
        nxt[2] = State(a,cur.b,cur.dist + 1); // filling vessel A
        nxt[3] = State(cur.a,b,cur.dist + 1); // filling vessel B
        // pouring water from A to B
        if(cur.a - CB >= 0) nxt[4] = State(cur.a-CB,b,cur.dist + 1);
        else nxt[4] = State(0,cur.b+cur.a,cur.dist + 1);
        // pouring water from B to A
        if(cur.b - CA >= 0) nxt[5] = State(a,cur.b-CA,cur.dist + 1);
        else nxt[5] = State(cur.a+cur.b,0,cur.dist + 1);
        for(int i = 0; i < 6; ++i) {
            int nxt_state;
            if(nxt[i].b == 0) nxt_state = nxt[i].a;
            else if(nxt[i].a == 0) nxt_state = nxt[i].b + 40001;
            else if(nxt[i].a == a) nxt_state = nxt[i].b + 80002;
            else nxt_state = nxt[i].a + 120003;
            if(!D[nxt_state]) {
                Q.push(nxt[i]);
                D[nxt_state] = true;
            }
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {  
    int TC, a, b, c, res;
    scanf("%d",&TC);
    while(TC-- > 0) {
        scanf("%d%d%d",&a,&b,&c);
        res = bfs(a,b,c);
        if(res >= 0) printf("%d\n",res);
        else puts("-1");
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
