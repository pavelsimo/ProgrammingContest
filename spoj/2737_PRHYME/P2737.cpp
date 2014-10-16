/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ PRHYME C++ "Trie, Data Structures, Trees" */
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

typedef vector<int> VI;

const int MAXN = 250010;
const int B_SIZE = 32;
char dict[MAXN][B_SIZE];
char s[B_SIZE], s2[B_SIZE];

struct Trie {
   Trie *child[26];
   int end_id;
   VI seen;
   Trie() {
      end_id = 0;
      for(int i = 0; i < 26; ++i)
         child[i] = NULL;
   }
   ~Trie() {
      for(int i = 0; i < 26; ++i)
         delete child[i];     
   }
   void addWord(const char *s, int id) {
      if(*s=='\0') {
         end_id = id;
         return;
      }
      if(child[*s-'a']==NULL)
         child[*s-'a'] = new Trie();
      child[*s-'a']->seen.push_back(id);
      child[*s-'a']->addWord(s+1,id);
   }
   vector<int> getWords(const char *s) {
      if(*s=='\0')
         return seen;
      if(child[*s-'a']==NULL)
         return VI(0);
      return child[*s-'a']->getWords(s+1);
   }
};


int main(int argc, char *argv[]) {
   int N;
   string ans;
   Trie trie;
   for(N = 0; gets(dict[N]) && *dict[N]; ++N) {
      strcpy(s,dict[N]);
      reverse(s,s+strlen(s));
      trie.addWord(s,N);
   }
   while(gets(s)) {
      char ans[B_SIZE] = "";
      for(char *p = s; *p; ++p) {
         if(ans[0]!='\0') break;
         strcpy(s2,p);
         reverse(s2,s2+strlen(s2));
         VI idx = trie.getWords(s2);
         for(int i = 0; i < sz(idx); ++i) {
            if(strcmp(s,dict[idx[i]])==0) continue;
            if(ans[0]=='\0' || strcmp(dict[idx[i]],ans) < 0) 
               strcpy(ans,dict[idx[i]]);
         }
      }
      puts(ans);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
