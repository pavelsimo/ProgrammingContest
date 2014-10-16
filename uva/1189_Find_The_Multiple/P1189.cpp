/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  1189  C++  "Ad Hoc, Math" */
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

typedef pair<string,int> State;
bool seen[202];

int main(int argc, char *argv[]) {
   int N;
   while(1 == scanf("%d",&N)) {
      if(!N) break;
      memset(seen,false,sizeof(seen));
      queue<State> Q;
      Q.push(make_pair("1",1%N));
      while(!Q.empty()) {
         State cur = Q.front();
         Q.pop();
         int mod = cur.second;
         string s = cur.first;
         if(!mod) {
            puts(s.c_str());
            break;
         }
         if(seen[mod]) continue;
         seen[mod] = true;
         Q.push(make_pair(s + "0", (mod * 10) % N));
         Q.push(make_pair(s + "1", (mod * 10 + 1) % N));
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
