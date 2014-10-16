/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  755  C++  "Ad Hoc" */
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

char D[256], buf[256];

int main(int argc, char *argv[]) {
   D['A'] = '2'; D['B'] = '2'; D['C'] = '2';
   D['D'] = '3'; D['E'] = '3'; D['F'] = '3';
   D['G'] = '4'; D['H'] = '4'; D['I'] = '4';
   D['J'] = '5'; D['K'] = '5'; D['L'] = '5';
   D['M'] = '6'; D['N'] = '6'; D['O'] = '6';
   D['P'] = '7'; D['R'] = '7'; D['S'] = '7';
   D['T'] = '8'; D['U'] = '8'; D['V'] = '8';
   D['W'] = '9'; D['X'] = '9'; D['Y'] = '9';
   int TC, n, m;
   gets(buf);
   sscanf(buf,"%d",&TC);
   for(int tc = 0; tc < TC; ++tc) {
      if(tc > 0) putchar('\n');
      map<string,int> m_directory;
      gets(buf);
      gets(buf);
      sscanf(buf,"%d",&n);
      for(int i = 0; i < n; ++i) {
         gets(buf);
         m = strlen(buf);
         string phone = "";
         for(int j = 0; j < m; ++j) {
            if(buf[j] == '-') continue;
            if(isalpha(buf[j])) 
               phone+=D[int(buf[j])];
            else 
               phone+=buf[j];
         }
         m_directory[phone]++;
      }
      bool duplicates = false;
      foreach(it,m_directory) {
         if(it->second > 1) {
            printf("%s %d\n",(it->first.substr(0,3) + "-" + it->first.substr(3)).c_str(),it->second);
            duplicates = true;
         }
      }
      if(!duplicates) 
         puts("No duplicates.");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

