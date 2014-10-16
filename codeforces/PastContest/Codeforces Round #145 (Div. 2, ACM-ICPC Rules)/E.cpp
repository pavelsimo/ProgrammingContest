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
//#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

struct Team {
   string name;
   int rank;
};

int sz[128];
vector<Team> basket[128];
vector<Team> groups[128];
int nteams, a, x, b, c;
Team A[128];

bool cmp(const Team &a, const Team &b) {
   return a.rank > b.rank;
}

int getrand() {
   return (x * a + b) %  c;
}

template<typename T>
void rpl(vector<T> &A, int g_ind, int ind) {
   for(int i = ind; i < sz[g_ind] - 1; ++i)
      A[i] = A[i + 1];
}

int main(int argc, char *argv[]) { 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
   cin >> nteams >> x >> a >> b >> c;
   for(int i = 0; i < nteams; ++i)
      cin >> A[i].name >> A[i].rank;
   sort(A, A + nteams, cmp);
   int m = nteams/4;   
   for(int i = 0; i < nteams; ++i) {
      sz[i/m] = m;
      basket[i/m].push_back(A[i]);
   }
   for(int i = 0; i < nteams; ++i) {
      int y = getrand();
      int basket_ind = i % 4;
      int group_ind = i / 4;
      int k = y % sz[basket_ind];
      groups[group_ind].push_back(basket[basket_ind][k]);
      rpl(basket[basket_ind], basket_ind, k);
      --sz[basket_ind];
      x = y;
   }
   for(int i = 0; i < m; ++i) {
      cout << "Group " << char('A' + i) << ":" << endl;
      for(int j = 0; j < (int)groups[i].size(); ++j)
         cout << groups[i][j].name.c_str() << endl;
   }
   return 0;
}

