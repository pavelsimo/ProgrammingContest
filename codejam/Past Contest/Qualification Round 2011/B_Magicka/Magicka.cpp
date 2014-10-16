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

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;

#define DEBUG(x) cout << #x << ": " << x << endl
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define sz(a) int((a).size())


bool m_opposed[256][256];
char m_combined[256][256];

int main() {
   int TC, C, D, N;
   string combined, opposed, s, res;
   cin >> TC;
   int tc = 1;
   while(TC-- > 0) {
      memset(m_opposed,false,sizeof(m_opposed));
      memset(m_combined,0,sizeof(m_combined));
      combined = opposed = s = res = "";
      cin >> C;
      while(C-- > 0) {
         cin >> combined; 
         m_combined[int(combined[0])][int(combined[1])] = combined[2];
         m_combined[int(combined[1])][int(combined[0])] = combined[2];
      }
      cin >> D;
      while(D-- > 0) {
         cin >> opposed;
         m_opposed[int(opposed[0])][int(opposed[1])] = true;
         m_opposed[int(opposed[1])][int(opposed[0])] = true;            
      }
      cin >> N;
      if(N > 0) cin >> s;
      for(int i = 0; i < sz(s); ++i) {
         if(sz(res)==0) {
            res+=s[i];
         } else {
            int p = s[i];
            int q = res[sz(res)-1];
            if(m_combined[p][q]!=0) {
               char ch = m_combined[p][q];
               res.erase(sz(res)-1);
               res+=ch;
            } else {
               bool found = false;
               int q = s[i];
               for(int j = 0; j < sz(res); ++j) {
                  int p = res[j];
                  if(m_opposed[p][q]) {
                     res = "";
                     found = true;
                     break;  
                  }
               }
               if(!found) res+=s[i];
            }
         }
      }
      printf("Case #%d: [",tc++);
      for(int i = 0; i < sz(res); ++i) {
         if(i > 0) printf(", ");
         printf("%c",res[i]);
      }
      printf("]\n");
   }
   return 0;
}
