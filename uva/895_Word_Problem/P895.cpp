/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  895  C++  "Ad Hoc, Frequency" */
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

string buf;
int dict[1002][26];
int freq[26];

int main(int argc, char *argv[]) {
   int N;
   char ch;
   for(N=0; getline(cin,buf); ++N) {
      if(buf[0]=='#') break;
      for(int i = 0; i < sz(buf); ++i)
         dict[N][buf[i]-'a']++;
   }
   while(getline(cin,buf)) {
      if(buf[0]=='#') break;
      memset(freq,0,sizeof(freq));
      istringstream in(buf);
      while(in >> ch)
         freq[ch-'a']++;
      int res = 0;
      for(int i = 0; i < N; ++i) {
         bool ok = true;
         for(int j = 0; j < 26; ++j) {
            if(freq[j] < dict[i][j]) {
               ok = false;
               break;
            }
         }
         if(ok) res++;
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
