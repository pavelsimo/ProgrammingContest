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

#define BITCOUNT(n) __builtin_popcount(n)

const int MAXN = 22;
int N, A[MAXN], res;

bool check(int x, int y) {
   for(; x > 0 && y > 0; x/=10, y/=10) {
      if(x%10 + y%10 >= 10) 
         return false; 
   }
   return true;
}

void rec(int cur, int sum, int cnt) {
   if(cnt > res) res = cnt;
   if(cur >= N || cnt + N - cur <= res) return;
   if(check(sum,A[cur]))
      rec(cur + 1, sum + A[cur], cnt + 1);
   rec(cur + 1, sum, cnt);
}

int main() {
   //freopen("escape.in", "r", stdin);
   //freopen("escape.out", "w", stdout);
   scanf("%d",&N);
   for(int i = 0; i < N; ++i)
      scanf("%d",&A[i]);
   res = 0;
   rec(0,0,0); 
   printf("%d\n",res);
   return 0;
}
