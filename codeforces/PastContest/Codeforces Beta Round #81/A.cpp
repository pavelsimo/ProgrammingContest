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

char name[128];
map<string,int> S;

int main(int argc, char *argv[]) {
   int N, M, exp, temp, x;
   scanf("%d %d %d.%d",&N,&M,&temp,&x);
   for(int i = 0; i < N; ++i) {
      scanf("%s %d",name,&exp);
      int val = (x * exp)/100;
      if(val >= 100) S[name] = val;
   }
   for(int i = 0; i < M; ++i) {
      scanf("%s",name);
      if(S.count(name)==0) S[name] = 0;
   }
   cout << sz(S) << endl;
   foreach(it,S)
      cout << it->first << ' ' << it->second << endl;
   return 0;
}

