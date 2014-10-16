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

struct Player {
  int id, place; 
  Player(int _id = 0, int _place = 0) :
      id(_id), place(_place) {}
  bool operator<(const Player &T) const {
     if(place != T.place) return place < T.place;
     return id < T.id;
  }
};
Player a[400002];

int main(int argc, char *argv[]) {
   int n, m;
   cin >> n;
   m = 3 * n;
   for(int i = 0; i < m; ++i) {
      cin >> a[i].id;
       a[i].place = i;
   }
   sort(a, a + m);
   //DEBUG
   for(int i = 0; i < m; ++i) {
      printf("rank #%d - player %d\n",a[i].place + 1, a[i].id);
   }
   return 0;
}

 
