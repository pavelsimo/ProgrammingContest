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

typedef long long llong;
vector<int> pos;

int main(int argc, char *argv[]) {
   int k;
   llong res = 0;
   string s;
   cin >> k >> s;
   if(k == 0) {
      llong cnt = 0;
      for(int i = 0; i < sz(s); ++i) {
         if(s[i] == '0') cnt++;
         else {
            res+=(cnt*(cnt+1LL))/2LL;
            cnt = 0;
         }
      }
      res+=(cnt*(cnt+1LL))/2LL;
   } else {
      for(int i = 0; i < sz(s); ++i)
         if(s[i] == '1') 
            pos.push_back(i);
      for(int i = 0; i + k - 1 < sz(pos); ++i) {
         int j = i + k - 1;
         int rz = j + 1 >= sz(pos) ? sz(s) - 1 - pos[j]: pos[j + 1] - pos[j] - 1;
         int lz = i - 1 >= 0 ? pos[i] - pos[i - 1] - 1: pos[i];
         res += llong(lz + 1) * llong(rz + 1);
      }      
   }
   cout << res << endl;
   return 0;
}
