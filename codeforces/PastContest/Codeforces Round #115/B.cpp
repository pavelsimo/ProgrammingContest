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

map<string, int> m;
vector<pair<string, int> > X;

int main(int argc, char *argv[]) {
   int n, rank;
   string name;
   cin >> n;
   for(int i = 0; i < n; ++i) {
      cin >> name >> rank;
      m[name] = max(m[name], rank);
   }
   foreach(it, m)
      X.push_back(make_pair(it->first, it->second));
   int N = sz(X);
   cout << N << endl;
   for(int i = 0; i < sz(X); ++i) {
      int k = 0;
      for(int j = 0; j < sz(X); ++j) {
         if(i == j) continue;
         if(X[i].second < X[j].second) k++;
      }
      cout << X[i].first;
      if(100 * k > N * 50) cout << " noob" << endl;
      else if(100 * k > N * 20) cout << " random" << endl;
      else if(100 * k > N * 10) cout << " average" << endl;
      else if(100 * k > N * 1) cout << " hardcore" << endl;
      else cout << " pro" << endl;
   }
   return 0;
}

