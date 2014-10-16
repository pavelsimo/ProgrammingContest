/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ CPRMT C++ "Ad Hoc, Frequency" */
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

int f1[26], f2[26];
int main(int argc, char *argv[]) {
   string a, b;
   while(cin >> a >> b) {
      memset(f1,0,sizeof(f1));
      memset(f2,0,sizeof(f2));
      for(int i = 0; i < sz(a); ++i) f1[a[i]-'a']++;
      for(int i = 0; i < sz(b); ++i) f2[b[i]-'a']++;
      for(char ch = 'a'; ch <= 'z'; ++ch) {
         for(int i = 0; i < min(f1[ch-'a'],f2[ch-'a']); ++i) 
            putchar(ch);
      }
      putchar('\n');
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

