#include <iostream>
#include <string>
#include <set>

using namespace std;

string board[128];
set<char> deputies;
int di[] = {+0,+1,-1,+0};
int dj[] = {+1,+0,+0,-1};

int main(int argc, char *argv[]) {
   int n, m;
   char p;
   cin >> n >> m >> p;
   for(int i = 0; i < n; ++i)
      cin >> board[i];
   for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
         if(board[i][j] == p) {
            for(int d = 0; d < 4; ++d) {
               int ni = i + di[d];
               int nj = j + dj[d];
               if(ni < 0 || ni >= n || nj < 0 || nj >= m || 
                  board[ni][nj] == '.' || board[ni][nj] == p) continue;
               deputies.insert(board[ni][nj]);
            }
         }
      }
   }
   cout << deputies.size() << endl;
   return 0;
}

