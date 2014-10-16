/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11917  C++  "Ad Hoc" */
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

char name[32];

int main(int argc, char *argv[]) {
   int TC, N, D, x;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      map<string, int> subject;  
      scanf("%d",&N);
      for(int i = 0; i < N; ++i) {
         scanf("%s %d",name,&x);
         subject[name] = x;
      }
      scanf("%d",&D);
      scanf("%s",name);
      printf("Case %d: ",tc);
      if(!subject.count(name)) puts("Do your own homework!");
      else if(subject[name] <= D) puts("Yesss");
      else if(subject[name] <= D+5) puts("Late");
      else puts("Do your own homework!");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
