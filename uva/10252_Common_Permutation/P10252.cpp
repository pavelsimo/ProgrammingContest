/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10252  C++  "Ad Hoc, Frequency" */
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

char s1[1024], s2[1024];
int freq1[26], freq2[26];

int main(int argc, char *argv[]) {
   int N, M;
   while(gets(s1)) {
      gets(s2);
      N = strlen(s1);
      M = strlen(s2);
      memset(freq1,0,sizeof(freq1));
      memset(freq2,0,sizeof(freq2));
      for(int i = 0; i < N; ++i) 
         freq1[s1[i]-'a']++;
      for(int i = 0; i < M; ++i) 
         freq2[s2[i]-'a']++;
      for(int i = 0; i < 26; ++i) {
         for(int j = 0; j < min(freq1[i],freq2[i]); ++j)
            putchar('a' + i);
      }
      putchar('\n');
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
