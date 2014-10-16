#include <algorithm>
#include <cassert>
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
   
   void addWord(const char *s) {
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
        t->addWord(s+1);
   }
    
   int countPreffixes(const char *s) {
      if(*s=='\0')
        return prefixes;
      Trie *t = child[*s-'a'];
      if(t==NULL) 
         return 0;
      return t->countPreffixes(s+1);
   }
   
   int countWords(const char *s) {
      if(*s=='\0')
         return words;
      Trie *t = child[*s-'a'];
      if(t==NULL)
         return 0;
      return t->countWords(s+1);
   }
   
   bool find(const char *s) {
      return countWords(s) > 0;
   }
};




int main() {
   Trie *trie = new Trie();
   trie->addWord("pavel");
   trie->addWord("pavlok");
   trie->addWord("paval");
   trie->addWord("padk");
   trie->addWord("paq");
   trie->addWord("jose");
   trie->addWord("breada");
   trie->addWord("brenda");
   trie->addWord("brenda");
   if(trie->find("brenda")) puts("found");
   if(trie->find("paq")) puts("found");
   DEBUG(trie->countPreffixes("pa"));
   DEBUG(trie->countPreffixes("pav"));
   DEBUG(trie->countPreffixes("pavel"));
   DEBUG(trie->countWords("brenda"));
   return 0;
}
