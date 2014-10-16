#include <iostream>
#include <cstdio>
#include <cfloat>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

int N;
bool ken_chosed[102], naomi_chosed[102];
vector<double> naomi_blocks, ken_blocks;

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
  sort(naomi_blocks.begin(), naomi_blocks.end());
  sort(ken_blocks.begin(), ken_blocks.end());
  for(int i = 0; i < N; ++i) {
    if(check_naomi_wins(naomi_blocks[i])) {
      naomi_score++;
    }
  }
  return naomi_score;
}

int memo[1024][1024];

int play_deceitful_war(int naomi, int ken) {
  if(naomi == 1023 && ken == 1023) return 0;
  int naomi_score = 0;
  if(memo[naomi][ken] != -1) return memo[naomi][ken];
  for(int i = 0; i < N; ++i) {
    if(!(naomi & (1<<i))) {
      for(int j = 0; j < N; ++j) {
        if(!(ken & (1<<j))) {
          int nnaomi = naomi | (1<<i);
          int nken = ken | (1<<j);
          if (naomi_blocks[i] > ken_blocks[j]) {
              naomi_score = max(naomi_score, play_deceitful_war(nnaomi, nken) + 1);
          } else {
              naomi_score = max(naomi_score, play_deceitful_war(nnaomi, nken));
          } 
        }
      }
    }
  }
  return memo[naomi][ken] = naomi_score;
}

int main() {
  int TC;
  double block;
  cin >> TC;
  for(int tc = 1; tc <= TC; ++tc) {
    ken_blocks.clear();
    naomi_blocks.clear();
    cin >> N;
    for(int i = 0; i < N; ++i) {
      cin >> block;
      naomi_blocks.push_back(block);
    }
    for(int i = 0; i < N; ++i) {
      cin >> block;
      ken_blocks.push_back(block);
    }
    memset(memo, -1, sizeof(memo));
    printf("Case #%d: %d %d\n", tc, play_deceitful_war(0,0), play_war());
  }
  return 0;
}
