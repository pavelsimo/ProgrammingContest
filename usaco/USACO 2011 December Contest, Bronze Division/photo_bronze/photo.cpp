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

const int MAXN = 20002;
int A[MAXN], P[5][MAXN];

bool cmp(int a, int b) {
   int cnt = 0;
   for(int i = 0; i < 5; ++i)
      cnt+=P[i][a]<P[i][b];
   return cnt >= 3;
}

int main() {
   //freopen("photo.in", "r", stdin);
   //freopen("photo.out", "w", stdout);
   int N, k;
   scanf("%d",&N);
   for(int i = 0; i < 5; ++i) {
      for(int j = 0; j < N; ++j) {
         scanf("%d",&k);
         --k;
         P[i][k] = j;
         A[j] = k;
      }
   }
   sort(A, A + N, cmp);
   for(int i = 0; i < N; ++i)
      printf("%d\n",A[i] + 1);
   return 0;
}
