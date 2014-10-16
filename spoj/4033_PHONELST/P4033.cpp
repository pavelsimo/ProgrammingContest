/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ PHONELST C++ "Trie, Data Structures, Trees" */
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

struct Trie {
   
   Trie *child[10];  
   int prefixes;
   int words;
   
   Trie() {
      prefixes = 0;
      words = 0;
      for(int i = 0; i < 10; ++i)
         child[i] = NULL;
   }
   
   ~Trie() {
      for(int i = 0; i < 10; ++i)
         delete child[i];
   }
   
   void addWord(const char *s) {
      if(*s=='\0') {
         words++;
         return;
      }
      if(child[*s-'0']==NULL) {
         child[*s-'0'] = new Trie();
         child[*s-'0']->prefixes = 1;
      } else {
         child[*s-'0']->prefixes = child[*s-'0']->prefixes + 1;
      }
      child[*s-'0']->addWord(s+1);
   }
   
   int countPreffixes(const char *s) {
      if(*s=='\0')
         return prefixes;
      if(child[*s-'0']==NULL)
         return 0;
      return child[*s-'0']->countPreffixes(s+1);
   }
};


const int MAXN = 10010;
const int MAXM = 16;
char buf[MAXM];
char phone_num[MAXN][MAXM];

int main(int argc, char *argv[]) {
   int TC, N;
   gets(buf);
   sscanf(buf,"%d",&TC);
   while(TC-- > 0) {
      Trie *trie = new Trie();
      gets(buf);
      sscanf(buf,"%d",&N);
      for(int i = 0; i < N; ++i) {
         gets(phone_num[i]);
         trie->addWord(phone_num[i]);
      }
      bool ok = true;
      for(int i = 0; i < N; ++i) {
         if(trie->countPreffixes(phone_num[i]) > 1) {
            ok = false;
            break;
         }
      }
      if(ok) puts("YES");
      else puts("NO");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
