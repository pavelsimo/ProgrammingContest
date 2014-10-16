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

const int MAXN = 1024;
char a[MAXN], b[MAXN];
int lcp[MAXN], S[MAXN], N, na;
set<string> X;

bool cmp(const int i, const int j) {
   return strcmp(a + i, a + j) < 0;
}

int solve() {
   int ma = 0;
   for(int i = 0; i < N; ++i)
      S[i] = i;
   sort(S, S + N, cmp);
   lcp[0] = 0;
   for(int i = 1; i < N; ++i) {
      int j;
      for(j = 0; j < min(N - S[i], N - S[i-1]); ++j) {
         if(*(a + S[i] + j) != *(a + S[i-1] + j)) 
            break;
      }
      lcp[i] = j;
      if(lcp[i] > ma && 
         ((S[i] < na && S[i-1] > na) || 
          (S[i-1] < na && S[i] > na))) {
         ma = lcp[i];
      }
   }
   if(!ma) return 0;
   for(int i = 1; i < N; ++i) {
      if(lcp[i] == ma && 
         ((S[i] < na && S[i-1] > na) || 
          (S[i-1] < na && S[i] > na))) {
         string s = "";
         for(int j = 0; j < ma; ++j)
            s += *(a + S[i] + j);
         X.insert(s);
      }
   }
   foreach(it,X) printf("%s\n", (*it).c_str());
   return 1;
}

int main(int argc, char *argv[]) { 
   int tc = 0;
   while(gets(a) && gets(b)) {
      if(tc) printf("\n");
      X.clear();
      na = strlen(a);
      strcat(a, "."), strcat(a, b);
      N = strlen(a);
      if(!solve()) printf("No common sequence.\n");
      gets(b);
      tc++;
   }
   return 0;
}

