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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

const int MAXN = 22;

int N, visted_node_cnt;
bool visited[MAXN];
int adj[MAXN][MAXN], adj2[MAXN][MAXN];
bool is_solution = true;

void copy_adj_mat() {
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      adj2[i][j] = adj[i][j];
    }
  }
}

void create_new_adj_mat(int bitmask) {
  for(int i = 0; i < N; ++i) {
    if(bitmask & (1 << i)) {
      for(int j = 0; j < N; ++j) {
        adj2[i][j] = adj2[j][i] = 0;
      }
    }
  }
}

void dfs(int i) {
  visited[i] = true;
  visted_node_cnt++;
  
  int cnt = 0;
  for(int j = 0; j < N; ++j) {
    if(!visited[j] && adj2[i][j]) cnt++;
  }
  if(cnt != 2 && cnt != 0) {
    is_solution = false;
  }
  
  for(int j = 0; j < N; ++j) {
    if(!visited[j] && adj2[i][j]) dfs(j);
  }
}

int main(int argc, char *argv[]) { 
  int TC;
  cin >> TC;
  for(int tc = 1; tc <= TC; ++tc) {
    int xi, yi; 
    memset(adj, 0, sizeof(adj));
    memset(adj2, 0, sizeof(adj2));
    cin >> N;
    for(int i = 0; i < N - 1; ++i) {
      cin >> xi >> yi;
      --xi; --yi;
      adj[xi][yi] = adj[yi][xi] = 1;
    }
    int ans = N;
    for(int i = 0; i < (1 << N); ++i) {
      int del_cnt = __builtin_popcount(i);
      copy_adj_mat();
      create_new_adj_mat(i);
      
      for(int j = 0; j < N; ++j) {
        is_solution = true;
        memset(visited, false, sizeof(visited));
        visted_node_cnt = 0;
        dfs(j);
        if(visted_node_cnt == N - del_cnt && is_solution) {
          ans = min(del_cnt, ans);
        }
      }
    }
    printf("Case #%d: %d\n", tc, ans);
  }
  return 0;
}
