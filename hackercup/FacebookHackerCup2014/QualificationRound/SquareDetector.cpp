#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

string B[32];

bool is_possible(int si, int sj, int ei, int ej) {
   for(int i = si; i <= ei; ++i) {
      for(int j = sj; j <= ej; ++j) {
         if(B[i][j] == '.') return false;
      }
   }
   return true;
}

int main() {
   int TC, N;
   cin >> TC;
   for(int tc = 1; tc <= TC; ++tc) {
      cin >> N;
      for(int i = 0; i < N; ++i)
         cin >> B[i];
      int cnt = 0;
      int ma = 0;
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < N; ++j) {
            if(B[i][j] == '#') {
               cnt++;
               for(int k = 0; k < N; ++k) {
                  int ii = i + k;
                  int jj = j + k;
                  if(ii >= N || jj >= N) continue;
                  if(is_possible(i,j,ii,jj))
                     ma = max(ma, (k+1) * (k+1));
               }
            }           
         }
      }
      //cout << "max=" << ma << endl;
      //cout << "cnt=" << cnt << endl;
      cout << "Case #" << tc << ": " << (ma == cnt ? "YES" : "NO") << endl;
   }
   return 0;
}
