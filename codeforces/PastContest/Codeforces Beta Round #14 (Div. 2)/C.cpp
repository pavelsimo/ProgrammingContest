#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

const int INF = 2000000000;

typedef pair<int,int> Point;

int main(int argc, char *argv[]) {
   int ind[4], X[4][2], Y[4][2], x_max, x_min, y_max, y_min;
   set<Point> S;
   x_max = y_max = 0;
   x_min = y_min = INF;
   for(int i = 0; i < 4; ++i) {
      ind[i] = i;
      for(int j = 0; j < 2; ++j) {
         cin >> X[i][j] >> Y[i][j];   
         S.insert(make_pair(X[i][j],Y[i][j]));   
         x_max = max(x_max, X[i][j]);
         y_max = max(y_max, Y[i][j]);
         x_min = min(x_min, X[i][j]);
         y_min = min(y_min, Y[i][j]);
      }
   }
   if(x_min == x_max || y_min == y_max || S.size() != 4) {
      cout << "NO" << endl;
      return 0;
   }
   do {
      bool sol = false;
      for(int i = 0; i < 4; ++i) {
         int cur = ind[i];
         int nxt = ind[(i + 1) % 4];      
         
         
      }
   } while(next_permutation(ind, ind + 4));
   
   return 0;
}

