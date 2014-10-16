/*
ID: 7
PROG: cowcheck
LANG: C++
*/
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
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define sz(a) int((a).size())

const int MAXN = 1000010;
int rval[MAXN];

int main() {
   freopen("cowcheck.in", "r", stdin);
   freopen("cowcheck.out", "w", stdout);
   int M, N, TC, r=0, c=0, hi;
   scanf("%d%d",&M,&N);
   scanf("%d",&TC);
   memset(rval,-1,sizeof(rval));
   hi = max(M,N);
   rval[c] = r;
   while(true) {
      r+=1; c+=2;
      while(c < hi && rval[c]!=-1)
         r++,c++;
      if(c >= hi) break;
      rval[c] = r;
   }
   while(TC-- > 0) {
      scanf("%d%d",&r,&c);  
      if(r > c) swap(r,c);
      printf("%s\n",rval[c]==r?"Farmer John":"Bessie");
   }
   return 0;
}
