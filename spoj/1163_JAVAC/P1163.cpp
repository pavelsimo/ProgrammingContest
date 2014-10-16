/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ JAVAC C++ "Ad Hoc" */
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

bool isJava(string s) {
   int n = sz(s);
   if( n==0 || !isalpha(s[0]) || isupper(s[0])) return false;
   for(int i = 1; i < n; ++i)
      if(s[i]=='_') return false;
   return true;
}

bool isCpp(string s) {
   int n = sz(s);
   if( n==0 || !isalpha(s[0]) || !isalpha(s[n-1]) || isupper(s[0])) return false;
   for(int i = 1; i < n; ++i) {
      if(isupper(s[i])) return false;
      if(s[i]=='_' && s[i-1]=='_') return false;
   }
   return true;
}

int main(int argc, char *argv[]) {
   string s, res;
   while(getline(cin,s)) {
      res="Error!";
      if(isJava(s)) {
         res="";
         for(int i = sz(s)-1; i >= 0; --i) {
            char ch = tolower(s[i]);
            res = ch + res;
            if(isupper(s[i])) res = "_" + res;
         }
      } else if(isCpp(s)) {
         res="";
         for(int i = 0; i < sz(s); ++i) {
            char ch = s[i];
            if(ch=='_') {
               if(i+1 < sz(s))s[i+1]=toupper(s[i+1]);
               continue;
            }
            res+=ch;
         }
      }
      puts(res.c_str());
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

