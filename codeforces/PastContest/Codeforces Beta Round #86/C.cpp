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

#define M_ADJ 1
#define M_NOUN 2
#define M_VERB 4
#define F_ADJ 8
#define F_NOUN 16
#define F_VERB 32

bool endsWith(string str, string suffix) {
   if (equal(suffix.rbegin(), suffix.rend(), str.rbegin()))
      return true;
   return false;
}

int f(string s) {
   if(endsWith(s,"lios")) return M_ADJ;
   else if(endsWith(s,"etr")) return M_NOUN;
   else if(endsWith(s,"initis")) return M_VERB;
   else if(endsWith(s,"liala")) return F_ADJ;
   else if(endsWith(s,"etra")) return F_NOUN;
   else if(endsWith(s,"inites")) return F_VERB;
   return 0;
}

vector<string> dict;
vector<int> noun;

int main(int argc, char *argv[]) {
   string buf, word;
   getline(cin,buf);
   istringstream in(buf);
   for(int i = 0; in >> word; ++i) {
      if(f(word) == M_NOUN || f(word) == F_NOUN) 
         noun.push_back(i);
      dict.push_back(word);
   }
   bool ok = true;
   if(noun.size() > 1) {
      puts("NO");
   } else if (noun.size() == 0) {
      if(dict.size() == 0) {
         puts("YES");
      } else {
         if(dict.size() == 1) {
            if(f(dict[0]) > 0) puts("YES");
            else puts("NO");
         } else {
            puts("NO");
         }
      }
   } else {
      for(int i = 0; i < sz(noun); ++i) {
         int middle = noun[i];
         int lo = i - 1 < 0 ? 0 : noun[i-1];
         int hi = i + 1 >= sz(noun) ? sz(dict) : noun[i + 1];
         bool masculine = f(dict[middle]) & 7;
         for(int j = lo; j < middle; ++j) {
            int type = f(dict[j]);
            if(!type) ok = false;
            if((type & 56) && masculine) ok = false;
            if((type & 7) && !masculine) ok = false;
            if(masculine) {
               if(type!=M_ADJ) ok = false;
            } else {
               if(type!=F_ADJ) ok = false;
            }
         }
         for(int j = middle + 1; j < hi; ++j) {
            int type = f(dict[j]);
            if(!type) ok = false;
            if((type & 56) && masculine) ok = false;
            if((type & 7) && !masculine) ok = false;
            if(masculine) {
               if(type!=M_VERB) ok = false;
            } else {
               if(type!=F_VERB) ok = false;         
            }
         }
      }
      if(ok) puts("YES");
      else puts("NO");      
   }
   return 0;
}

