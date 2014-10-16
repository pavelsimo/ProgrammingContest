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

int freq[26];
const string pattern = "HACKERCUP";
int main(int argc, char *argv[]) {   
   string s;
   int TC, res, i;
   getline(cin,s);
   sscanf(s.c_str(),"%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      memset(freq,0,sizeof(freq));
      getline(cin,s);
      for(i = 0; i < sz(s); ++i)
         if(isalpha(s[i]))
            freq[s[i]-'A']++;
      res = 0;
      while(true) {
         for(i = 0; i < sz(pattern); ++i) {
            if(freq[pattern[i]-'A'] == 0) break;
            freq[pattern[i]-'A']--;
         }
         if(i < sz(pattern)) break;
         res++;
      }
      printf("Case #%d: %d\n",tc,res);
   }
   return 0;
}

