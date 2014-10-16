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

int N, Q, P[1024];
char dict[1024][1024], query[1024];
const int MAXN = 128;

struct Trie {
   Trie *child[MAXN];
   int best;
   
   Trie() {
      best = -1;
      for(int i = 0; i < MAXN; ++i)
         child[i] = NULL;
   }
   
   ~Trie() {
      for(int i = 0; i < MAXN; ++i)
         delete child[i];
   }
   
   void addWord(const char *s, const int ind) {
        if(*s=='\0') return;
        Trie *t = child[(int)*s];
        if(child[(int)*s]==NULL) {
           t = child[(int)*s] = new Trie();  
           t->best = ind;
        } else {
           if(P[ind] > P[t->best]) t->best = ind;
        }
        t->addWord(s+1, ind);
   }
 
   string findBestRecipe(const char *s) {
      if(*s=='\0') {
        if(best >= 0 && best < N) return dict[best];
        return "NO";
      }
      Trie *t = child[(int)*s];
      if(t==NULL) return "NO";
      return t->findBestRecipe(s+1);
   }
};

int main(int argc, char *argv[]) {
   Trie *trie = new Trie();
   int priority;
   scanf("%d",&N);
   for(int i = 0; i < N; ++i) {
      scanf("%s %d",dict[i],&priority);
      P[i] = priority;
      trie->addWord(dict[i], i);
   }
   scanf("%d",&Q);
   while(Q-- > 0) {
      scanf("%s",query);
      puts(trie->findBestRecipe(query).c_str());
   }
   return 0;
}
