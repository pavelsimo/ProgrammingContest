#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long int64;

const int MAXN = 100020;
int64 a[MAXN], b[MAXN];
vector<pair<int64,int64> > ans;

int main(int argc, char *argv[]) { 
   int i, j;
   int64 n, m, x, y;
   cin >> n >> m >> x >> y;
   for(i = 0; i < n; ++i) cin >> a[i];
   for(i = 0; i < m; ++i) cin >> b[i];
   i = j = 0;
   while(i < n && j < m) {
      if(b[j] >= a[i] - x && b[j] <= a[i] + y) {
         ans.push_back(make_pair(i + 1, j + 1));
         i++;
         j++;
      } else if(a[i] + y < b[j]) {
         i++;
      } else {
         j++;
      }
   }
   cout << ans.size() << endl;
   for(i = 0; i < (int)(ans.size()); ++i)
      cout << ans[i].first << ' ' << ans[i].second << endl;
   return 0;
}

