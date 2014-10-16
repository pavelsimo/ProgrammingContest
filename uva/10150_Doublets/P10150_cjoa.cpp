/* @JUDGE_ID: 1131EP  C++  "Trie+BFS" */
#include <cstdio>
#include <cstring>
#include <cassert>
 
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;
 
typedef vector<int> VI;
typedef vector<VI> VVI;
 
#define MAXWORDS 25200
 
int N;
char dict[MAXWORDS][20];
char line[100];
 
struct Trie {
   Trie *child[26];
   int end_id;
   Trie() : end_id(-1) {
      memset(child, 0, sizeof(child));
   }
   ~Trie() {
      for (char c = 'a'; c <= 'z'; ++c)
         delete child[c-'a'];
   }
   void insert(const char *s, int id) {
      if (!*s) {
         end_id = id;
         return;
      }
      Trie *t = child[*s-'a'];
      if (!t)
         t = child[*s-'a'] = new Trie();
      t->insert(s+1, id);
   }
   int find(const char *s) {
      if (!*s)
         return end_id;
      Trie *t = child[*s-'a'];
      if (!t)
         return -1;
      return t->find(s+1);
   }
};
 
VVI adj;
int D[MAXWORDS];
int P[MAXWORDS];
int bfs(int src, int dst) {
   memset(P, -1, N*sizeof(int));
   memset(D, -1, N*sizeof(int));
   D[src] = 0;
   queue<int> q;
   q.push(src);
   while (!q.empty()) {
      int cur = q.front();
      q.pop();
      if (cur == dst) return D[dst];
      for (int j = 0; j < adj[cur].size(); ++j) {
         int nxt = adj[cur][j];
         if (D[nxt] < 0) {
            D[nxt] = D[cur] + 1;
            P[nxt] = cur;
            q.push(nxt);
         }
      }
   }
   return -1;
}
 
int main(int argc, char* argv[]) {
   // read the dictionary
   for (N = 0; gets(dict[N]) && *dict[N]; ++N);
 
   // build trie with each dictionary word
   Trie trie;
   for (int i = 0; i < N; ++i)
      trie.insert(dict[i], i);
 
   adj = VVI(N);
   for (int i = 0; i < N; ++i) {
      Trie *t = &trie;
      for (char *p = dict[i]; *p; ++p) {
         char orig_ch = *p;           // save character at position p
         for (char c = 'a'; c <= 'z'; ++c) {
            // try each possible lower case letter except original value
            if (c == orig_ch) continue;
            *p = c;                   // modify character at position 
            int j = t->find(p);       // find index of word ending with substring from p
            if (j >= 0)               // found an ending position
               adj[i].push_back(j);   // push edge i -> j
         }
         *p = orig_ch;                // restore original value at position p
         t = t->child[ *p-'a' ];      // traverse down the trie
      }
   }
 
   for (int tc = 1; gets(line); ++tc) {
      char src[20], dst[20];
      if (2 != sscanf(line, "%s %s", src, dst)) break;
      int isrc = trie.find( src );    // find index of source word
      int idst = trie.find( dst );    // find index of destination word
      int res = (isrc < 0 || isrc >= N || idst < 0 || idst >= N) ?
                    -1 : bfs(isrc, idst);
      if (tc > 1)
         putchar('\n');
      if (res < 0)
         puts("No solution.");
      else {
         // build path in reverse order => use stack
         stack<int> path;
         for (int k = idst; k != isrc; k = P[k])
            path.push(k);
         // print out path
         puts(dict[isrc]);
         while (!path.empty()) {
            int k = path.top();
            puts(dict[k]);
            path.pop();
         }
      }
   }
 
   return 0;
}
