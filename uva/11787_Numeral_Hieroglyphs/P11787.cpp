/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11787  C++  "Ad Hoc" */
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

const int P[] = {1,10,100,1000,10000,100000,1000000};
const string pattern = "BUSPFTM";

int main(int argc, char *argv[]) {
   int TC, cnt, res;
   bool flag, desc, ok;
   string s;
   getline(cin,s);
   sscanf(s.c_str(),"%d",&TC);
   while(TC-- > 0) {
      getline(cin,s);   
      char prev = '@';
      ok = flag = desc = true;
      res = cnt = 0;
      for(int i = 0; i < sz(s); ++i) {
         if(i == 0 || s[i]==prev) {
            cnt++;
         } else {
            cnt = 1;
            if(flag) {
               desc = pattern.find(s[i]) < pattern.find(prev);
               flag = false;
            } else {
               if(desc != (pattern.find(s[i]) < pattern.find(prev))) {
                  ok = false;
                  break;
               }
            }
         }
         if(cnt > 9) {
            ok = false;
            break;
         }
         int j = pattern.find(s[i]);
         res+=P[j];
         prev = s[i]; 
      }
      if(ok) printf("%d\n",res);
      else puts("error");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
