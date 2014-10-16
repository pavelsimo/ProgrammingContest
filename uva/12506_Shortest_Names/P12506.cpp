/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12506  C++  "Tries, Prefix" */
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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

const int MAXN = 26;

struct Trie {
   Trie *child[MAXN];
   int prefixes;
   int words;
   
   Trie() {
      prefixes = 0;
      words = 0;
      for(int i = 0; i < MAXN; ++i)
         child[i] = NULL;
   }
   
   ~Trie() {
      for(int i = 0; i < MAXN; ++i)
         delete child[i];
   }
   
   void add(const char *s) {
        if(*s=='\0') {
           words++;
           return;
        }
        Trie *t = child[*s-'a'];
        if(child[*s-'a']==NULL) {
           t = child[*s-'a'] = new Trie();  
           t->prefixes = 1;
        } else {
           t->prefixes = t->prefixes + 1;
        }
        t->add(s+1);
   }

   int best_prefix_len(const char *s, int k = 0) {
      if(*s=='\0' || prefixes == 1) return k;
      Trie *t = child[*s - 'a'];
      if(t == NULL) return 0;
      return t->best_prefix_len(s+1, k+1);
   }
};

char buf[1000010];

int main(int argc, char *argv[]) { 
   int TC, N, res;
   scanf("%d",&TC);
   while(TC-- > 0) {
      Trie *trie = new Trie();
      vector<string> dict;
      scanf("%d",&N);
      for(int i = 0; i < N; ++i) {
         scanf("%s",buf);
         dict.push_back(buf);
         trie->add(buf);
      }
      res = 0;
      for(int i = 0; i < N; ++i)
         res += trie->best_prefix_len(dict[i].c_str());
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
