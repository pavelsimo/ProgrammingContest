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

const int MAXN = 200020;
int V[MAXN], C[MAXN];

bool isvowel(char ch) {
   ch = tolower(ch);
   return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main(int argc, char *argv[]) {
   string s;
   cin >> s;
   memset(V,0,sizeof(V));
   memset(C,0,sizeof(C));
   for(int i = 0; i < sz(s); ++i) {
      V[i] += V[i-1 < 0 ? 0: i-1];
      C[i] += C[i-1 < 0 ? 0: i-1];
      if(isvowel(s[i])) V[i]++;
      else C[i]++;
   }
   int cnt = 0;
   int res = 0;
   for(int i = 0; i < sz(s); ++i) {
      if(V[i] <= 2*C[i]) {
         res = V[i] + C[i];
         cnt++;
      }
   }
   if(cnt) printf("%d %d\n",res,cnt);
   else puts("No solution");
   return 0;
}

