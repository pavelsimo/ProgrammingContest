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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

struct Racer {
  string name;
  int pts; 
  Racer(string _name, int _pts) : name(_name), pts(_pts) {}
  bool operator<(const Racer &T) const {
     if(T.pts!=pts) return T.pts > pts;
     if(T.name!=name) return T.name > name;
     return false;
  }
};

const int MAXN = 100020;
map<string,int> m_index;
vector<Racer> L;
vector<int> P;

int main(int argc, char *argv[]) {
   string buf, name, target;
   int N, M, pts, src=0;
   cin >> N;
   for(int i = 0; i < N; ++i) {
      cin >> name >> pts;
      L.push_back(Racer(name,pts));
   }
   cin >> M;
   int first = 0;
   int last = 987654321;
   for(int i = 0; i < M; ++i) {
      cin >> pts;
      first=max(first,pts);
      last=min(last,pts);
   }   
   cin >> target;
   sort(all(L));
   for(int i = 0; i < N; ++i) {
      printf("%d ",L[i].pts);
      P.push_back(L[i].pts);
      if(L[i].name==target)
         src=i;
   }
   putchar('\n');
   DEBUG(P[src]);
   DEBUG(first);
   DEBUG(last);
   int lower = int(upper_bound(all(P),P[src]+first) - P.begin());
   int upper = int(lower_bound(all(P),P[src]+last) - P.begin());
   DEBUG(lower);
   DEBUG(upper);
   return 0;
}
