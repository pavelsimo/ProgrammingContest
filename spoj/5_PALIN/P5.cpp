/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ PALIN C++ "Ad Hoc, String, Palindrome" */
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

typedef long long llong;

int main(int argc, char *argv[]) {  
   int TC;
   string s;
   getline(cin,s);
   sscanf(s.c_str(),"%d",&TC);   
   while(TC-- > 0) {
      getline(cin,s);
      int lo = 0;
      int hi = sz(s)-1;
      bool pos = false, flag = false;
      while(lo <= hi) {
         if(s[lo] < s[hi]) {
            s[hi] = s[lo];
            pos = false;
         } else if(s[lo] > s[hi]) {
            s[hi] = s[lo];
            pos = true;
         }
         if(lo+1 == hi) {
            if(!pos) {
               if(s[lo]=='9' && s[hi]=='9') {
                  s[lo] = s[hi] = '0';
                  lo--; hi++;
                  flag = true;
               }
               else s[lo]++, s[hi]++;   
            }
            break;
         } else if(lo == hi) {
            if(!pos) {
               if(s[lo]=='9') {
                  s[lo] = '0';
                  lo--; hi++;
                  flag = true;
               }
               else s[lo]++;   
            }
            break;  
         }
         lo++;
         hi--;
      }  
      if(flag) {
         bool found = false;
         while(lo >= 0 && hi < sz(s)) {
            if(s[lo]=='9') {
               s[lo] = s[hi]='0';
            } else {
               s[lo]++;
               s[hi]++;
               found = true;
               break;
            }
            lo--;
            hi++;
         }
         if(!found) {
            s[0]='1';
            s+='1';
         }
      }
      puts(s.c_str());
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
