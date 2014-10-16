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
   int n;
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
   
   void addWord(const char *s, int _n = 0) {
        if(*s=='\0') {
           n = _n;
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
   
   int find(const char *s) {
      if(countWords(s) > 0) return n;
      return -1;
   }
};

string complement(string s) {
   string res = "";
   for(int i = 0; i < sz(s); ++i) {
      if(s[i] == '1') res+='0';
      else res+='1';  
   }
   return res;
}

string tobin(int n) {
   string res = "";
   int i, j;
   for(i = 31; i >= 0; --i) {
      if(n & (1<<i)) break;
   }
   for(j = i; j >= 0; --j) {
      if(n & (1<<j)) res+='1';
      else res+='0';
   }
   return res;
}

int A[1000020];

int main() {  
   Trie *trie = new Trie();  
   int N;
   cin >> N;
   for(int i = 0; i < N; ++i) {
      cin >> A[i];
      trie->addWord(tobin(A[i]).c_str(), A[i]);
   }
   for(int i = 0; i < N; ++i) {
      cout << trie->find(complement(tobin(A[i])).c_str()) << endl;
   }
   return 0;
}


