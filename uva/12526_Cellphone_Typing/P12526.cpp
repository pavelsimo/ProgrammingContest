/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12526  C++  "Tries, Strings, Prefix" */
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

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

   int get_key_strokes(const char *s, int k = 0) {
      if(*s=='\0') return k;
      Trie *t = child[*s - 'a'];
      if(t == NULL) return 0;
      return t->get_key_strokes(s+1, (prefixes == t->prefixes) ? k: k + 1);
   }
};

char buf[1000010];

int main(int argc, char *argv[]) {
   int N, strokes;
   while(1 == scanf("%d",&N)) {
      Trie *trie = new Trie();
      vector<string> dict;
      for(int i = 0; i < N; ++i) {
         scanf("%s",buf);
         dict.push_back(buf);
         trie->add(buf);
      }
      strokes = 0;
      for(int i = 0; i < N; ++i)
         strokes += trie->get_key_strokes(dict[i].c_str());
      printf("%.2lf\n", double(strokes) / N);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
