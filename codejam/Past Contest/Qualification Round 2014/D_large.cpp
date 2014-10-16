#include <iostream>
#include <cstdio>
#include <cfloat>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())

const int MAXN = 1002;
int N, M;
bool ken_chosed[MAXN], naomi_chosed[MAXN];
vector<double> naomi_blocks, ken_blocks;

typedef vector<int> VI;

VI v_left, v_right, edges[MAXN];
bool seen[MAXN];

bool dfs(int cur) {
   if(seen[cur]) return false;
   seen[cur] = true;
   for(int v = 0; v < sz(edges[cur]); ++v) {
      int nxt = edges[cur][v];
      if(v_right[nxt]==-1 || dfs(v_right[nxt])) {
         v_left[cur] = nxt;
         v_right[nxt] = cur;
         return true;
      } 
   }
   return false;
}

int bipartite_matching() {
   int res = 0;
   bool aug_path_found;
   while(true) {
      memset(seen,false,sizeof(seen));
      aug_path_found = false;
      for(int i = 0; i < N; ++i) {
          if(v_left[i] == -1 && dfs(i))
             aug_path_found = true;
      }
      if(!aug_path_found) break;
   }
   for(int i = 0; i < N; ++i) {
      if(v_left[i]!=-1)
         res++;
   }
   return res;
}

void print_array(vector<double> &a) {
  for(int i = 0; i < N; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}

bool check_naomi_wins(double naomi_block) {
  for(int i = 0; i < N; ++i) {
    if(!ken_chosed[i]) {
      if(ken_blocks[i] > naomi_block) {
        ken_chosed[i] = true;
        return false;
      }
    }
  }
  return true;
}

int play_war() {
  memset(ken_chosed, false, sizeof(ken_chosed));
  int naomi_score = 0;

  for(int i = 0; i < N; ++i) {
    if(check_naomi_wins(naomi_blocks[i])) {
      naomi_score++;
    }
  }
  return naomi_score;
}

int play_deceitful_war() {
  memset(seen,false,sizeof(seen));
  for(int i = 0; i < MAXN; ++i) edges[i].clear();
  v_left  = VI(MAXN, -1);
  v_right = VI(MAXN, -1);
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      if(naomi_blocks[i] > ken_blocks[j]) {
        edges[i].push_back(j);
      }
    }
  }
  return bipartite_matching();
}

int main() {
  int TC;
  double block;
  cin >> TC;
  for(int tc = 1; tc <= TC; ++tc) {
    ken_blocks.clear();
    naomi_blocks.clear();
    cin >> N;
    M = N;
    for(int i = 0; i < N; ++i) {
      cin >> block;
      naomi_blocks.push_back(block);
    }
    for(int i = 0; i < N; ++i) {
      cin >> block;
      ken_blocks.push_back(block);
    }
    sort(naomi_blocks.begin(), naomi_blocks.end());
    sort(ken_blocks.begin(), ken_blocks.end());
    printf("Case #%d: %d %d\n", tc, play_deceitful_war(), play_war());
  }
  return 0;
}
