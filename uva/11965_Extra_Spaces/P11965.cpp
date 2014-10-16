/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11965  C++  "Ad Hoc" */
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
#define pb push_back

int main(int argc, char *argv[]) {
   int TC, N;
   string buf;
   getline(cin,buf);
   sscanf(buf.c_str(),"%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      getline(cin,buf);
      sscanf(buf.c_str(),"%d",&N);
      if(tc > 1) putchar('\n');
      printf("Case %d:\n",tc);
      for(int i = 0; i < N; ++i) {
         getline(cin,buf);
         for(int j = 0; j < sz(buf); ++j) {
            if(isspace(buf[j]) && j+1 < sz(buf)) {
               if(!isspace(buf[j+1])) {
                  putchar(buf[j]);   
               }
            } else {
                 putchar(buf[j]); 
            }
         }
         putchar('\n');
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
