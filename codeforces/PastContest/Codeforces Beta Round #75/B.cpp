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

const int MAXN = 2000000;
int a[MAXN];

int main(int argc, char *argv[]) {
   string s;
   getline(cin,s);
   int N = sz(s);
   memset(a,-1,sizeof(a));
   for(int i = 0; i < N; ++i) {
      if(s[N-i-1]=='1') 
         a[i]=1;
      else 
         a[i]=0;
   }
   int ans = 0;
   for(int i = 0; i <= N+1; ++i) {
      if(a[i]==1 && a[i+1]==-1) break;
      if(a[i]==1) {
         int j;
         for(j = i + 1; j <= N+1; ++j)
            if(a[j]!=1) break;
         a[j] = 1;
         ans+=j-i+1;
         i = j-1;
      } else if(a[i]==0) {
         ans++;   
      }
   }
   printf("%d\n",ans);
   return 0;
}

