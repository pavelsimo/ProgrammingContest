/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  140  C++  "Brute Force, Permutations" */
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

typedef vector<char> VC;
typedef vector<VC> VVC;
const int INF = 0x3f3f3f3f;
VVC adj;
char s[32], res[32];

int main(int argc, char *argv[]) {
   int cnt, best, N;
   char u;
   string buf, token, v;
   while(getline(cin,buf)) {
      if(buf[0]=='#') break;      
      adj = VVC(27);
      istringstream in(buf);
      while(getline(in,token,';')) {
         size_t pos = token.find(':');
         u = token.substr(0,pos)[0];
         v = token.substr(pos+1);
         for(int i = 0; i < sz(v); ++i) {
            adj[u-'A'].push_back(v[i]);
            adj[v[i]-'A'].push_back(u);
         }
      }
      N = 0;
      for(int i = 0; i < sz(adj); ++i) {
         if(sz(adj[i]) > 0) {
            s[N]=('A'+i);
            N++;
         }
      }
      s[N] = '\0';
      cnt = INF;
      do {      
         best = 0;   
         for(int i = 0; i < N; ++i) {
            for(int j = 0; j < sz(adj[s[i]-'A']); ++j)
               best = max(best, abs(int(strchr(s,adj[s[i]-'A'][j]) - s) - i));
         }
         if(best < cnt) {
            strcpy(res,s);
            cnt = best;   
         }
      } while(next_permutation(s,s+N));
      for(int i = 0; i < N; ++i)
         printf("%c ",res[i]);
      printf("-> %d\n",cnt);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
