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

typedef long long llong;

const int INF = 0x3f3f3f3f;
const int MAXN = 1002;
int freq[MAXN][30];

int main(int argc, char *argv[]) {
   int N;
   string word, res;
   while(cin >> N) {
      memset(freq,0,sizeof(freq));   
      for(int i = 0; i < N; ++i) {
         cin >> word;
         for(int j = 0; j < sz(word); ++j)
            freq[i][word[j]-'a']++;
      }
      res = "";
      for(int i = 0; i < 26; ++i) {
         int hi = INF;
         for(int j = 0; j < N; ++j)
            hi = min(hi,freq[j][i]);
         if(hi > 0) 
            res+=string(hi,'a'+i); 
      }
      if(sz(res) > 0) 
         cout << res << endl;
      else
         cout << "no such string" << endl;
   }
   return 0;
}

