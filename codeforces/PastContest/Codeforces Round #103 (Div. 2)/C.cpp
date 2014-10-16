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

int freq1[26];
int freq2[100010][26];
int qm[100010];

int main(int argc, char *argv[]) {
   string s, p;
   cin >> s >> p;
   memset(freq1,0,sizeof(freq1));
   memset(freq2,0,sizeof(freq2));
   memset(qm,0,sizeof(qm));
   for(int i = 0; i < sz(p); ++i)
      freq1[p[i]-'a']++;
   if(isalpha(s[0]))
      freq2[0][s[0]-'a']++;
   else
      qm[0]++;
   for(int i = 1; i < sz(s); ++i) {
      qm[i] = qm[i-1];
      for(int j = 0; j < 26; ++j)
         freq2[i][j]+=freq2[i-1][j];
      if(s[i]=='?') qm[i]++;
      else freq2[i][s[i]-'a']++;
   }
   int res = 0;
   for(int i = 0; i < sz(s); ++i) {
      if(i+sz(p)-1 < sz(s)) {
         bool ok = true;
         int lo = i-1 < 0 ? 0: qm[i-1];
         int hi = qm[i+sz(p)-1];
         int cntQM = hi-lo;
         for(int j = 0; j < 26; ++j) {
            int lo2 = i-1 < 0 ? 0: freq2[i - 1][j];
            int hi2 = freq2[i+sz(p)-1][j];
            int F = hi2-lo2;
            if(F == freq1[j]) continue;
            if(abs(F-freq1[j]) <= cntQM) {
               cntQM-=abs(F-freq1[j]);
            } else {
               ok = false;
               break;
            }
         }
         if(ok) res++;
      }
   }
   cout << res << endl;
   return 0;
}

