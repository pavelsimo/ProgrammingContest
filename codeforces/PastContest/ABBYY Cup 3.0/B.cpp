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

const int MAXN = 2002;

int a[MAXN], parent[MAXN], size[MAXN];
vector<int> groups;
int N;

int find_set(int x) {
   if(x != parent[x]) parent[x] = find_set(parent[x]);
   return parent[x];
}
 
bool union_set(int x, int y) {
   x = find_set(x); y = find_set(y);
   if(x == y) // cycle
      return false;
   parent[x] = y;
   size[y] += size[x];
   return true;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int x;
   groups.clear();
   cin >> N >> x;
   for(int i = 1; i <= N; ++i) {
      parent[i] = i; 
      size[i] = 1;
   }
   for(int i = 1; i <= N; ++i) {
      cin >> a[i];
      if(a[i] == 0) continue;
      union_set(a[i], i);
   }
   set<int> S;
   for(int i = 1; i <= N; ++i) {
      int g = find_set(i);
      if(S.count(g) == 0) {
         groups.push_back(size[g]);
         S.insert(g);
      }
   }
   for(int i = 1; i <= N; ++i) {
      
   }
   return 0;
}
