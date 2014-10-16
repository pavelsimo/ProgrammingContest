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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

const int MAXN = 11;
int A[102], freq[102], freq2[102];

int C(int n, int m) {
    if (m > n) return 0;
    int res = 1;
    for (int i = 1; i <= m; i++)
        res = res * (n - i + 1) / i;
    return res;
}

int main(int argc, char *argv[]) {
   int TC, K;
   scanf("%d",&TC);
   while(TC-- > 0) {
      memset(freq, 0, sizeof(freq));
      memset(freq2, 0, sizeof(freq2));
      for(int i = 0; i < MAXN; ++i) {
         scanf("%d",&A[i]);
         freq[A[i]]++;
         freq2[A[i]]++;
      }
      scanf("%d",&K);
      sort(A, A + MAXN);
      for(int k = 0, i = MAXN - 1; i >= 0 && k < K; ++k, --i)
         freq[A[i]]--;
      int res = 1;
      for(int k = 0, i = MAXN - 1; i >= 0 && k < K; ++k, --i) {
         res*=C(freq2[A[i]], freq[A[i]]);
         freq[A[i]] = 0;
      }
      printf("%d\n",res);
   }
   return 0;
}
