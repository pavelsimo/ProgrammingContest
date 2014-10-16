/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11661  C++  "Ad Hoc" */
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

char s[2000020];
int main(int argc, char *argv[]) {
   int N, res, k;
   char prev;
   while(gets(s)) {
      sscanf(s,"%d",&N);
      if(!N) break;
      gets(s);
      prev = '.';
      res = N;
      for(k = 0; k < N; ++k) {
         if(s[k]!='.') 
            break;
      }
      int cnt = 0;
      for(int i = k; i < N; ++i) {
         if(s[i] == 'Z') {
            res = 0;
            break;
         }
         if(s[i] == 'R') {
            if(prev == 'D') 
               res = min(res,cnt);
            cnt = 0;
         }
         if(s[i] == 'D') {
            if(prev == 'R') 
               res = min(res,cnt);
            cnt = 0;
         }
         cnt++;
         if(s[i]!='.') 
            prev = s[i];
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
