/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

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
        if(*s == '\0') {
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
    
    int count_preffixes(const char *s) {
        if(*s == '\0')
            return prefixes;
        Trie *t = child[*s-'a'];
        if(t==NULL) 
            return 0;
        return t->count_preffixes(s+1);
    }
    
    int count_words(const char *s) {
        if(*s=='\0')
            return words;
        Trie *t = child[*s-'a'];
        if(t==NULL)
            return 0;
        return t->count_words(s+1);
    }
    
    bool find(const char *s) {
        return count_words(s) > 0;
    }
};

int main(){
    int n;
    cin >> n;
    Trie trie;
    
    for(int i = 0; i < n; i++){
        string op;
        string contact;
        cin >> op >> contact;
        if(op[0] == 'a') {            
            trie.add(contact.c_str());
        } else if(op[0] == 'f') {
            int cnt = trie.count_preffixes(contact.c_str());
            cout << cnt << endl;
        }                
    }
    return 0;
}
