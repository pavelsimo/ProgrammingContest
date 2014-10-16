/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10622  C++  "Math, Prime Factor" */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef long long llong;

map<int,int> PF;
int main(int argc, char *argv[]) {
   llong n;
   int res;
   while(1 == scanf("%lld", &n)) {
      if(!n) break;
      llong x = (n >= 0) ? n: -n;
      PF.clear();
      for(llong i = 2; i * i <= x; ++i) {
         while(x % i == 0) {
            PF[i]++;
            x/=i;
         }
      }
      if(x > 1) PF[x]++;
      for(res = 32; res >= 1; --res) {
         bool found = true;
         foreach(it,PF) {
            if(it->second % res != 0) {
               found = false;   
               break;
            }
         }
         if(n >= 0 && found) break;
         else if(n < 0 && found && (res % 2 == 1)) break;
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
