#include <iostream>
#include <vector>
#include <set>

using namespace std;

multiset<int> S;
vector<int> ans;
int a[100002], best;

int main(int argc, char *argv[]) {
   std::ios_base::sync_with_stdio(false);
   int n, k;
   cin >> n >> k;
   for(int i = 0; i < n; ++i)
      cin >> a[i];
   S.insert(a[0]);
   int ma = 0, lo = 0, hi = 1;
   while(true) {
      if(*S.rbegin() - *S.begin() <= k) {
         if(hi - lo > ma) {
            ma = hi - lo;
            ans.clear();
         }
         if(hi - lo == ma) 
            ans.push_back(lo);
         if(hi == n) 
            break;
         S.insert(a[hi++]);
      } else {
         S.erase(S.find(a[lo++]));
      }
   }
   cout << ma << ' ' << ans.size() << endl;
   for(int i = 0; i < (int)ans.size(); ++i)
      cout << ans[i] + 1 << ' ' << ans[i] + ma << endl;
   return 0;
}

