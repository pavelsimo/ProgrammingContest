/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  1160  C++  "Graph Theory, Disjoint Set" */
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

const int MAXN = 100100;
int P[MAXN], rank[MAXN];

void make_set(int x) {
   P[x] = x;
   rank[x] = 0;
}

int find_set(int x) {
   if(x != P[x]) 
      P[x] = find_set(P[x]);
   return P[x];
}

void merge(int x, int y) {
   int a = find_set(x);
   int b = find_set(y);
   if(rank[a] > rank[b]) 
      P[b] = a;
   else 
      P[a] = b;
   if(rank[a] == rank[b]) 
      rank[b] = rank[b] + 1;  
}

char buf[256];
int main(int argc, char *argv[]) {
   int res, u, v;
   while(gets(buf)) {
      if(2 != sscanf(buf,"%d%d",&u,&v));
      for(int i = 0; i < MAXN; ++i)
         make_set(i);
      merge(u,v);
      res = 0;
      while(gets(buf)) {
         if(2 != sscanf(buf,"%d%d",&u,&v)) break;
         if(find_set(u)==find_set(v))
            res++;
         else
            merge(u,v);         
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
