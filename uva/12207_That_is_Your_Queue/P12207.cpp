/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12207  C++  "Ad Hoc" */
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

char buf[128], dummy[16];
list<int> Q;
map<int,list<int>::iterator> M;

int main(int argc, char *argv[]) {
   int P, C, k;
   int tc = 0;
   while(gets(buf)) {
      if(2 != sscanf(buf,"%d%d",&P,&C)) break;
      if(!P && !C) break;
      Q.clear();
      M.clear();
      printf("Case %d:\n",++tc);
      for(int i = 1; i <= min(P,C); ++i)
         M[i] = Q.insert(Q.end(),i);
      while(C-- > 0) {
         gets(buf);
         if(buf[0]=='N') {
            k = Q.front();
            printf("%d\n",k);
            Q.pop_front();
            M[k] = Q.insert(Q.end(),k);
         } else if(buf[0]=='E') {
            sscanf(buf,"%s %d",dummy,&k);
            if(M.count(k) == 0) {
               M[k] = Q.insert(Q.begin(),k);
            } else {
               Q.erase(M[k]);
               M[k] = Q.insert(Q.begin(),k);
            }
         }  
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
