/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  161  C++  "Ad Hoc, Time" */
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

const int MAXN = 18000;
int freq[MAXN + 20];

int main(int argc, char *argv[]) {
   memset(freq,0,sizeof(freq));
   string buf;
   int N, K = 0, st = MAXN;
   while(getline(cin,buf)) {
      if(buf.find("0 0 0") != string::npos) break;
      istringstream in(buf);
      while(in >> N) {
         if(N == 0) {
            bool found = false;
            for(int i = st; i <= MAXN; ++i) {
               if(freq[i] == K) {
                  found = true;
                  int H = i/3600;
                  int M = (i - H*3600)/60;
                  int S = i - H*3600 - M*60;
                  printf("%02d:%02d:%02d\n",H,M,S);
                  break;
               }
            }
            if(!found) puts("Signals fail to synchronise in 5 hours");
            memset(freq,0,sizeof(freq));      
            K = 0;
            st = MAXN;      
         } else {
            st = min(st,N+N);
            K++;
            for(int i = 0; i <= MAXN; ++i) {
               int j;
               for(j = 0; i + j <= MAXN && j < N-5; ++j) freq[i+j]++;
               i = i + j + N + 4;
            }
         }
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
