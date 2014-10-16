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

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;

#define DEBUG(x) cout << #x << ": " << x << endl
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define sz(a) int((a).size())

VVI vvi;
set<vector<int> > L;

int main() {
   
   int N, K, x;
   scanf("%d",&N);
   int M = N*(N-1)/2;
   vector<int> empty_set(220);
   vvi = VVI(M+1);
   for(int i = 0; i < M; ++i) {
      scanf("%d",&K);
      for(int j = 0; j < K; ++j) {
         scanf("%d",&x);
         vvi[i].push_back(x);
      }
      sort(vvi[i].begin(),vvi[i].end());
   }
   for(int i = 0; i < M; ++i) {
      for(int j = i + 1; j < M; ++j) {
          vector<int> v(220);
          set_intersection (vvi[i].begin(), vvi[i].end(), vvi[j].begin(), vvi[j].end(), v.begin());
          if(L.count(v)==0 && v!=empty_set) L.insert(v);
      }
   }
   foreach(it,L) {
      vector<int> v = *it;
      int cnt = 0;
      for(int i = 0; i < sz(v); ++i) {
         if(v[i]==0) continue;
         cnt++;
      }
      printf("%d ",cnt);
      for(int i = 0; i < sz(v); ++i) {
         if(v[i]==0) continue;
         printf("%d ",v[i]);
      }
      putchar('\n');
   }
   return 0;
}
