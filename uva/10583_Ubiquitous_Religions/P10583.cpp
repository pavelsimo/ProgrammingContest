/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10583  C++  "Disjoint Sets" */
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

int parent[50002], size;

int find_set(int x) {
   if(x == parent[x]) 
      return x;
   return parent[x] = find_set(parent[x]);
}

void union_set(int x, int y) {
   x = find_set(x);
   y = find_set(y);
   if(x == y) return;
   size--;
   parent[y] = x;
}

int main(int argc, char *argv[]) {
   int n, m, u, v;
   for(int tc = 1; 2 == scanf("%d%d",&n,&m); ++tc) {
      if(!n && !m) break;
      for(int i = 0; i < n; ++i)
         parent[i] = i;
      size = n;
      while(m-- > 0) {
         scanf("%d%d",&u,&v);
         --u, --v;
         union_set(u,v);
      }
      printf("Case %d: %d\n",tc,size);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
