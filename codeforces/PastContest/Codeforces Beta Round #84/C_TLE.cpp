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
typedef pair<llong,string> PII;

int main(int argc, char *argv[]) {
   int N;
   cin >> N;
   priority_queue<PII, vector<PII>, greater<PII> > Q;
   Q.push(PII(4,"4"));
   Q.push(PII(7,"7"));
   while(!Q.empty()) {
      PII cur = Q.top(); 
      Q.pop();
      if(cur.first == N) {
         cout << cur.second << endl;
         return 0;
      }
      if(cur.first > N) continue;
      Q.push(PII(cur.first + 4, cur.second + "4"));
      Q.push(PII(cur.first + 7, cur.second + "7"));
   }
   cout << "-1" << endl;
   return 0;
}

