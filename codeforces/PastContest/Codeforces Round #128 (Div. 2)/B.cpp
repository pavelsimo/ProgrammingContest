#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 1010, INF = 0x3f3f3f3f;
int A[MAXN][MAXN];
vector<pair<int,int> > P;

int di[] = {+1,-1,+1,-1,+0,+1,+0,-1};
int dj[] = {+1,-1,-1,+1,+1,+0,-1,+0};

int main(int argc, char *argv[]) {
   int n, m, u, v, res;
   cin >> n >> m;
   memset(A, 0x3f, sizeof(A));
   for(int i = 1; i <= m; ++i) {
      cin >> u >> v;
      P.push_back(make_pair(u,v));
      A[u][v] = i;
   }
   res = INF;
   for(int k = 0; k < m; ++k) {
      int i = P[k].first;
      int j = P[k].second;
      if(i - 1 >= 1 && j - 1 >= 1 && i + 1 <= n && j + 1 <= n) {
         int temp = A[i][j];
         for(int d = 0; d < 8; ++d) {
            int ni = i + di[d];
            int nj = j + dj[d];
            temp = max(temp, A[ni][nj]);
         }
         res = min(res, temp);
      }
   }
   if(res >= INF) cout << "-1" << endl;
   else cout << res << endl;
   return 0;
}



