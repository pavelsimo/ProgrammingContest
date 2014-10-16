/*
ID: 0000
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio> 
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

const int maxn = 12;
bool D[maxn];
int v[maxn];

int main() {
   //freopen("crypt1.in", "r", stdin);
   //freopen("crypt1.out", "w", stdout);
   int N, elem, ans=0;
   scanf("%d",&N);
   for(int i=0; i < N; ++i) {
      scanf("%d",&elem);
      v[i]=elem;
      D[elem]=true;
   }
   for(int a = 0; a < N; ++a)
   for(int b = 0; b < N; ++b)
   for(int c = 0; c < N; ++c)
   for(int d = 0; d < N; ++d)
   for(int e = 0; e < N; ++e) {
      int va, vb, vc, vd, ve, ec, eb, ea, dc, db, da, x, x1, x2, x3, x4;
      va = v[a]; vb = v[b]; vc = v[c];
      vd = v[d];  ve = v[e];
      int n1 = (va*100 + vb*10 + vc);
      int n2 = (vd*10 + ve);
      int n3 = (n1)*ve;
      int n4 = (n1)*vd;
      if(n3 < 100 || n3 > 999) continue;
      if(n4 < 100 || n4 > 999) continue;
      ec = (n3/100)%10;
      eb = (n3/10)%10; 
      ea = (n3)%10;
      dc = (n4/100)%10;
      db = (n4/10)%10;  
      da = (n4)%10;
      if(!D[ec] || !D[eb] || !D[ea] || !D[dc] || !D[db] || !D[da]) continue;
      x = (n1)*(n2);
      if(x >= 1000 && x <= 9999) {
         x1=(x/1000)%10;
         x2=(x/100)%10;
         x3=(x/10)%10;
         x4=x%10;
         if(!D[x1] || !D[x2] || !D[x3] || !D[x4]) continue;
         ans++;
      }
   }
   printf("%d\n",ans);
}
