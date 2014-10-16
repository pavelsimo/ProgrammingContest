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
#include <fstream>
#include <sys/time.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

typedef long long llong;

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

Trie *trie;


void load_dictionary() {
   trie = new Trie();
   string word;
   ifstream f("garbled_email_dictionary.txt");
   if (f.is_open()) {
      while ( f.good() ) {
         getline (f,word);
         trie->addWord(word.c_str());
         //cout << line << endl;
      }
      f.close();
   }
}

string S;

int rec(int cur, string s, int change) {
   if(cur == sz(S)) 
      return 0;
   int res = sz(S);
   if(trie->countPreffixes(s.c_str())) {
      res = min(res, rec(cur + 1, "", 0));
      res = min(res, rec(cur + 1, s + S[cur], change - 1));
   }
   if(change == 0) {
      for(int ch = 'a'; ch <= 'z'; ++ch) {
         string ns = s;
         ns += ch;
         if(trie->countPreffixes(ns.c_str()) > 0)
            res = min(res, rec(cur + 1, ns, 5) + 1);
      }      
   }      
   return res;
}

int main(int argc, char *argv[]) { 
   load_dictionary();
   int TC;
   cin >> TC;
   for(int tc = 1; tc <= TC; ++tc) {
      cin >> S;
      cout << "Case #" << tc << ": " << rec(0, "", 0) << endl;
   }
   return 0;
}
