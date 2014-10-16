#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()

typedef long long llong;

vector<pair<llong,llong> > X;
vector<llong> ans;

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(0);
   llong n, mem, lo, hi, xi, yi;
   cin >> n >> mem >> lo >> hi;
   for(int i = 0; i < n; ++i) {
      cin >> xi >> yi;
      X.push_back(make_pair(xi * lo + yi * hi, i + 1));
   }
   sort(all(X));
   for(int i = 0; i < n; ++i) {
      llong t = X[i].first;
      if(mem >= t) 
         mem-=t, ans.push_back(X[i].second);
   }
   cout << sz(ans) << endl;
   for(int i = 0; i < sz(ans); ++i) {
      if(i > 0) cout << ' ';
      cout << ans[i];
   }
   cout << endl;
   return 0;
}
