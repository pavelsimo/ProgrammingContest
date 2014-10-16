/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11503  C++  "Disjoint Sets" */
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

const int MAXN = 100002;
map<string, int> m_name_id;
int parent[MAXN], size[MAXN];
string u[MAXN], v[MAXN];

int find_set(int x) {
   if(x == parent[x])
      return x;
   return parent[x] = find_set(parent[x]);
}

int union_set(int x, int y) {
   x = find_set(x);
   y = find_set(y);
   if(x == y) 
      return size[x];
   parent[y] = x;
   size[x] += size[y];
   return size[x];
}

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(false);
   int TC, F, n;
   cin >> TC;
   while(TC-- > 0) {
      m_name_id.clear();
      cin >> F;
      n = 0;
      for(int i = 0; i < F; ++i) {
         cin >> u[i] >> v[i];
         if(m_name_id.count(u[i]) == 0) m_name_id[u[i]] = n++;
         if(m_name_id.count(v[i]) == 0) m_name_id[v[i]] = n++;
      }
      for(int i = 0; i < n; ++i) {
         parent[i] = i;
         size[i] = 1;
      }
      for(int i = 0; i < F; ++i)
         cout << union_set(m_name_id[u[i]], m_name_id[v[i]]) << '\n';
   } 
   return 0;
}
/* @END_OF_SOURCE_CODE */
