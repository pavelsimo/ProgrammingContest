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

const int MAXN = 10;
int freq[MAXN];

int C(int n, int m) {
    if (m > n) return 0;
    int res = 1;
    for (int i = 1; i <= m; i++)
        res = res * (n - i + 1) / i;
    return res;
}

int main(int argc, char *argv[]) {
   int X, N, i, j, res = 0;
   string s;
   cin >> X >> N;
   for(i = 0; i < N; ++i) {
      cin >> s;
      memset(freq,0,sizeof(freq));
      for(j = 0; j < sz(s); ++j)
         if(s[j] == '0') 
            freq[j <= 35 ? j/4 : 8-((j-36)/2)]++;
      for(j = 0; j < 9; ++j)
         res+=C(freq[j], X);
   }
   cout << res << endl;      
   return 0;
}

