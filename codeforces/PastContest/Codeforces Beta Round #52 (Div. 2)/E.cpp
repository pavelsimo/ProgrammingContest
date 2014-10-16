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

struct Domino {
   int x, h, id;
   Domino(int _x = 0, int _y = 0, int _id = 0) :
      x(_x), y(_y), id(_id) {}
   bool operator<(const Domino &T) const {
      return x < T.x;
   }
};

vector<Domino> X;

int main(int argc, char *argv[]) {
   int n, x, h;
   cin >> n;
   for(int i = 0; i < n; ++i) {
      cin >> x >> h;
      X.push_back(Domino(x, h, i));
   }
   sort(all(X));
   
   return 0;
}

