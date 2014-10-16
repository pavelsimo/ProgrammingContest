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

typedef long long llong;

typedef long long llong;
typedef vector<int> VI;

const int MAXN = 32;
const int INF = 0x3f3f3f3f;
int N, A, B;
int di[] = {+0,+1,+0,-1};
int dj[] = {+1,+0,-1,+0};

string board[MAXN];
int D[MAXN][MAXN];

struct Node {
   int i, j, d;
   Node(int _i, int _j, int _d) : 
      i(_i), j(_j), d(_d) {}
};

class CNode {
   public:
      bool operator()(const Node &a, const Node &b) const {
         return a.d > b.d;
      } 
};

int dijkstra(Node src) {
   int res = 0;
   memset(D, 0x3f, sizeof(D));
   priority_queue<Node, vector<Node>, CNode> Q;
   Q.push(src);
   D[src.i][src.j] = 0;
   while(!Q.empty()) {
      Node cur = Q.top(); 
      Q.pop();
      int d = cur.d;
      res = max(res, cur.d);
      if(d <= D[cur.i][cur.j]) {
         for(int dir = 0; dir < 4; ++dir) {
            int ni = cur.i + di[dir];
            int nj = cur.j + dj[dir];
            if(ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
            int cost = (board[cur.i][cur.j] == board[ni][nj]) ? A: B;
            if(D[cur.i][cur.j] + cost < D[ni][nj]) {
               D[ni][nj] = D[cur.i][cur.j] + cost;
               Q.push(Node(ni,nj,D[ni][nj]));
            }
         }
      }
   }
   return res;
}

int main() {
    freopen("distant.in", "r", stdin);
    freopen("distant.out", "w", stdout);
    int res = 0;
    cin >> N >> A >> B;
    for(int i = 0; i < N; ++i)
       cin >> board[i];
    for(int i = 0; i < N; ++i)
       for(int j = 0; j < N; ++j)
          res = max(res, dijkstra(Node(i,j,0)));
    cout << res << endl;
    return 0;
}
