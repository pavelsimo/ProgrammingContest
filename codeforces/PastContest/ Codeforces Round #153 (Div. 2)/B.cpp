#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <deque>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <sys/time.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }



typedef long long llong;
 
const int MAXN = 100020;
llong tree1[MAXN], tree2[MAXN], 
   A[MAXN], B[MAXN], mi[MAXN], ma[MAXN];
int n;
set<int> S;
 
llong read(llong *tree, int idx){
 llong sum = 0;
 while (idx > 0){
  sum += tree[idx];
  idx -= (idx & -idx);
 }
 return sum;
}
 
void update(llong *tree, int idx ,llong val){
 while (idx <= MAXN){
  tree[idx] += val;
  idx += (idx & -idx);
 }
}

bool is_sorted() {
   bool inc = true, dec = true;
   for(int i = 1; i < n; ++i) {
      if(A[i - 1] > A[i]) inc = false;
      if(A[i - 1] < A[i]) dec = false;
   }
   return inc || dec;
}

int main(int argc, char *argv[]) { 
   //ios_base::sync_with_stdio(false);
   //cin.tie(NULL);
   cin >> n;
   if(n <= 2) {
      cout << -1 << endl; 
   } else {
      for(int i = 0; i < n; ++i) {
         cin >> A[i];
         B[i] = A[i];
         S.insert(A[i]);
      }
      sort(B, B + n);
      for(int i = 0; i < n; ++i) {
         int rank = int(lower_bound(B, B + n, A[i]) - B);
         A[i] = rank + 1;
      }
      if(sz(S) >= 2) {
         if(is_sorted()) {
            // wrong look for the indexes of two different elements...
            cout << 1 << " " << 2 << endl;
         } else {
            llong ma_val = 0;
            for(int i = 0; i < n; ++i) {
               mi[i] = read(tree1, A[i] + 1);
               ma_val = max(ma_val, A[i]);
               update(tree1, A[i], 1);
            }
            for(int i = n - 1; i >= 0; --i) {
               ma[i] = read(tree2, ma_val) - read(tree2, A[i]);
               update(tree2, A[i], 1);
            }
            for(int i = 0; i < n; ++i) {
               printf("%lld (%lld) %lld\n",mi[i], A[i], ma[i]);
            }
         }
      } else {
         cout << -1 << endl;
      }
   }
   return 0;
}
