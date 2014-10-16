/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12015  C++  "Ad Hoc, Data Structure" */
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

const int MAXN = 10;
int relevance[MAXN];
string web[MAXN];

int main(int argc, char *argv[]) {
   int TC, score, best;
   string buf, s;
   getline(cin,buf);
   sscanf(buf.c_str(),"%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      best = 0;
      for(int i = 0; i < MAXN; ++i) {
         getline(cin,buf);   
         istringstream in(buf);
         in >> s >> score;
         web[i] = s;
         relevance[i] = score;
         best = max(best,score);
      }
      printf("Case #%d:\n",tc);
      for(int i = 0; i < MAXN; ++i) {
         if(relevance[i]==best) 
            puts(web[i].c_str());
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
