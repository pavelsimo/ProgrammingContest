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

const int MAXN = 20002, MAXC = 12;
int A[MAXN], R[MAXC], T[MAXC], N, C;
vector<int> res;

bool check() {
   for(int i = 0; i < C; ++i)
      if(R[i] != T[i])
         return false;
   return true;
}

void translate(int *X) {
   int lo = 0;
   for(int i = 0; i < C; ++i)
      if(i == 0 || X[i] < lo)
         lo = X[i];
   for(int i = 0; i < C; ++i)
      X[i]-=lo;
}

int main() {
   freopen("moosick.in", "r", stdin);
   freopen("moosick.out", "w", stdout);
   int i, j;
   scanf("%d",&N);
   for(i = 0; i < N; ++i)
      scanf("%d",&A[i]);
   scanf("%d",&C);
   for(i = 0; i < C; ++i)
      scanf("%d",&R[i]);
   translate(R);
   sort(R, R + C);
   for(i = 0; i <= N - C; ++i) {
      for(j = 0; j < C; ++j)
         T[j] = A[i + j];
      translate(T);
      sort(T, T + C);
      if(check()) res.push_back(i + 1);
   }
   printf("%d\n",sz(res));
   for(i = 0; i < sz(res); ++i)
      printf("%d\n",res[i]);
   return 0;
}
