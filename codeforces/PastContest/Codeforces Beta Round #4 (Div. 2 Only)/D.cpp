#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()

typedef pair<int,pair<int,int> > Card;

const int MAXN = 5002;
int DP[MAXN], P[MAXN];
vector<Card> A, ans;

int main(int argc, char *argv[]) {
   int n, W, H, w, h, ma;
   cin >> n >> W >> H;
   for(int i = 0; i < n; ++i) {
      cin >> w >> h;
      if(w > W && h > H)
         A.push_back(make_pair(w,make_pair(h,i)));
   }
   if((int)A.size() == 0) {
      cout << "0" << endl;
      return 0;
   }
   sort(all(A));
   ma = 0;
   for(int i = 0; i < sz(A); ++i) {
      int wi = A[i].first;
      int hi = A[i].second.first;
      DP[i] = 1;
      P[i] = -1;
      for(int j = 0; j < i; ++j) {
         int wj = A[j].first;
         int hj = A[j].second.first;
         if(wi > wj && hi > hj) {
            if(DP[j] + 1 > DP[i]) {
               DP[i] = DP[j] + 1;
               P[i] = j;
            }
         }
      }
      if(DP[i] > DP[ma])
         ma = i;
   }
   for(int i = ma; i >= 0; i = P[i]) 
      ans.push_back(A[i]);
   cout << sz(ans) << endl;
   for(int i = sz(ans) - 1; i >= 0; --i)
      cout << ans[i].second.second + 1 << ' ';
   cout << endl;
   return 0;
}

