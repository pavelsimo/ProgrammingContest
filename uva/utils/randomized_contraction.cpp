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


typedef vector<int> VI;
typedef vector<VI> VVI;

const int MAXN = 40;
int N;

VVI contraction(VVI adj, int u, int v) {
   vector<int> temp;
   for(int i = 0; i < sz(adj[u]); ++i) {
      if(adj[u][i] == v) continue;
      temp.push_back(adj[u][i]);
   }
   temp.swap(adj[u]);
   for(int i = 0; i < sz(adj[v]); ++i) {
      if(adj[v][i] == u) continue;
      adj[u].push_back(adj[v][i]);
   }
   for(int i = 0; i < sz(adj); ++i) {
      for(int j = 0; j < sz(adj[i]); ++j) {
         if(adj[i][j] == v) adj[i][j] = u;
         else if(adj[i][j] > v) --adj[i][j];
      }
   }
   adj.erase(adj.begin() + v);
   return adj;
}

void print_adj_lst(VVI &adj) {
   for(int i = 0; i < sz(adj); ++i) {
      printf("%d: ",i + 1);
      for(int j = 0; j < sz(adj[i]); ++j) {
         printf("%d ", adj[i][j] + 1);
      }
      printf("\n");
   }
}

pair<int,int> get_rand_edge(int n) {
   int u = rand() % n;
   int v = rand() % n;
   while(u == v) {
      u = rand() % n;
      v = rand() % n;
   }
   return make_pair(u, v);
}

bool is_edge(VVI &adj, int u, int v) {
   bool c1, c2;
   c1 = c2 = false;
   for(int i = 0; i < sz(adj[u]); ++i) {
      if(adj[u][i] == v) {
         c1 = true;
         break;
      }
   }
   for(int i = 0; i < sz(adj[v]); ++i) {
      if(adj[v][i] == u) {
         c2 = true;
         break;
      }
   }
   return c1 && c2;
}

int main(int argc, char *argv[]) {
   srand(time(NULL));
   int u, v;
   string s;
   VVI adj = VVI(MAXN, VI());
   N = 0;
   while(getline(cin, s)) {
      istringstream in(s);
      in >> u;
      --u;
      ++N;
      while(in >> v) {
         --v;
         adj[u].push_back(v);
      }
   }
   int res = N;
   for(int i = 0; i < 1000; ++i) {
      VVI temp = adj;
      while(temp.size() > 2) {
         pair<int,int> redge = get_rand_edge(sz(temp));
         while(!is_edge(temp, redge.first, redge.second)) redge = get_rand_edge(sz(temp));
         if(redge.first > redge.second) swap(redge.first, redge.second);
         temp = contraction(temp,redge.first,redge.second);
         printf("(%d, %d)\n", redge.first + 1, redge.second + 1);  
      }
      print_adj_lst(temp);
      res = min(res, sz(temp[0]));
   }
   DEBUG(res);
   return 0;
}
// END CUT HERE
