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

int size;
int parent[102];

int find_set(int x) {
   if(parent[x] == x) 
      return x;
   return parent[x] = find_set(parent[x]);
}


bool union_set(int x, int y) {
   x = find_set(x);
   y = find_set(y);
   if(x == y) return false;
   --size;
   parent[x] = y;
   return true;
}

int X[102], Y[102];

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(false);
   int n;
   cin >> n;
   size = n;
   for(int i = 0; i < n; ++i) {
      cin >> X[i] >> Y[i];
      --X[i]; --Y[i];
      parent[i] = i;
   }
   for(int i = 0; i < n - 1; ++i) {
      for(int j = i + 1; j < n; ++j) {
         if(X[i] == X[j] || Y[i] == Y[j])
            union_set(i,j);
      }
   }
   cout << size - 1 << endl;
   return 0;
}

