/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11418  C++  "Backtracking" */
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

#define BUFSIZE (4*1024*1024)
bool bEOF;
int pos, end;
char buf[BUFSIZE+64];

void fill_buffer() {
   int rem = end - pos;
   if (rem < 64 && !bEOF) {
      memcpy(buf, buf+pos, rem);
      int nread = fread(buf + rem, 1, BUFSIZE - rem, stdin);
      if (!nread) bEOF = true;
      pos = 0;
      end = rem + nread;
   }
}
 
int nextInt() {
   fill_buffer();
   int res = 0;
   while (buf[pos] <= ' ' && buf[pos]) ++pos;
   bool neg = false;
   switch (buf[pos]) {
      case '-': neg = true;
      case '+': ++pos;
   }
   while (buf[pos] > ' ') 
      res = res*10+(buf[pos++]&15);
   return neg ? -res : res;
}
 
int nextString(char out[]) {
   fill_buffer();
   int n = 0;
   while (buf[pos] <= ' ' && buf[pos]) ++pos;
   while (buf[pos] > ' ') 
      out[n++] = buf[pos++];
   out[n] = 0;
   return n;
}

typedef vector<string> VS;
VS adj[27][27];
int N, seen[27], ans[27];
vector<string> a;

bool check(int letter, int problem) {
   if(sz(adj[problem][letter]) == 0) 
      return false;
   return true; 
}

void dfs(int i) {
   if(i < N) {
      for(int k = 0; k < N; ++k) {
         if(!seen[k]) {
            seen[k] = i;
            if(check(i,k))
               dfs(i + 1);
            seen[k] = 0;
         }
      }
   } else {
      for(int k = 0; k < N; ++k)
         ans[k] = seen[k];
   }
}

char word[128];
int main(int argc, char *argv[]) {
   int TC, K;
   TC = nextInt();
   memset(seen,false,sizeof(seen));
   for(int tc = 1; tc <= TC; ++tc) {
      N = nextInt();
      a.clear();
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < N; ++j) {
            adj[i][j].clear();         
         }
      }
      for(int i = 0; i < N; ++i) {
         K = nextInt();
         for(int j = 0; j < K; ++j) {
            nextString(word);            
            int nxt = tolower(word[0])-'a';
            adj[i][nxt].push_back(word);
         }
      }
      dfs(0);
      printf("Case #%d:\n",tc);
      for(int i = 0; i < N; ++i) {
         string s = adj[i][ans[i]][0];
         s[0] = toupper(s[0]);
         a.push_back(s);
      }
      sort(all(a));
      for(int i = 0; i < N; ++i)
         puts(a[i].c_str());
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
