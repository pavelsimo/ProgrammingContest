/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ VPALIN C++ "Trie, Data Structures" */
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
  Trie *child[26];
  int words;
  Trie() {
     words = 0;
     for(int i = 0; i < 26; ++i)
        child[i] = NULL;
  }
  ~Trie() {
     for(int i = 0; i < 26; ++i)
        delete child[i];
  }
  void insert(const char *s) {
      if(*s=='\0') {
         words++;
         return;
      }
      if(child[*s-'a']==NULL)
         child[*s-'a'] = new Trie();
      child[*s-'a']->insert(s+1);
  }
  int find(const char *s) {
      if(*s=='\0') 
         return words;
      if(child[*s-'a']==NULL)
         return -1;
      return child[*s-'a']->find(s+1);
  }
  int score(const char *s) {
     if(*s=='\0') 
         return words;
     if(child[*s-'a']==NULL)
         return 0;
     return words + child[*s-'a']->score(s+1);
  }
};

const int MAXN = 1024;
string buf, word, s;
vector<string> dict;

int main(int argc, char *argv[]) {
   Trie trie;
   int N, M;
   getline(cin,buf);
   sscanf(buf.c_str(),"%d",&N);
   for(int i = 0; i < N; ++i) {
      getline(cin,buf);
      istringstream in(buf);
      in >> M;
      in >> word;
      s = word;
      reverse(all(s));
      trie.insert(s.c_str());
      dict.push_back(word);
   }
   //DEBUG
   for(int i = 0; i < sz(dict); ++i) {
      puts(dict[i].c_str());
      DEBUG(trie.score(dict[i].c_str()));
   }
      
   return 0;
}
/* @END_OF_SOURCE_CODE */
