#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int NCARDS = 16;
const int BAD_MAGICIAN = -1;
const int VOLUNTEER_CHEATED = -2;

int freq[22];

int solve() {
  int cnt_winners = 0;
  int card = 0;
  for(int i = 1; i <= NCARDS; ++i) {
    if(freq[i] >= 2) {
      card = i;
      cnt_winners++;
    }
  }
  if(cnt_winners > 1) return BAD_MAGICIAN;
  else if(cnt_winners == 0) return VOLUNTEER_CHEATED;
  return card;
}

int main() {
  int TC, a1, a2, x;
  cin >> TC;
  for(int tc = 1; tc <= TC; ++tc) {
    memset(freq, 0, sizeof(freq));
    cin >> a1;
    for(int row = 1; row <= 4; ++row) {
      for(int col = 1; col <= 4; ++col) {
        cin >> x;
        if(row == a1) freq[x]++;
      }
    }
    cin >> a2;
    for(int row = 1; row <= 4; ++row) {
      for(int col = 1; col <= 4; ++col) {
        cin >> x;
        if(row == a2) freq[x]++;
      }
    }
    int ans = solve();
    cout << "Case #" << tc << ": ";
    if (ans == BAD_MAGICIAN) cout << "Bad magician!" << endl;
    else if(ans == VOLUNTEER_CHEATED) cout << "Volunteer cheated!" << endl;
    else cout << ans << endl;
  }
  return 0;
}
