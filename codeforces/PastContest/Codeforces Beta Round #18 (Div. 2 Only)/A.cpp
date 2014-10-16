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

typedef pair<int,int> Point;
#define x first
#define y second
vector<pair<int, int> > P;

int dist(Point a, Point b) {
   int dx = a.x - b.x;
   int dy = a.y - b.y;
   return dx * dx + dy * dy;
}

bool is_right(Point a, Point b, Point c) {
   int A = dist(a, b);
   int B = dist(a, c);
   int C = dist(b, c);
   if(A == 0 || B == 0 || C == 0) return false;
   int T[3];
   T[0] = A; T[1] = B; T[2] = C;
   sort(T, T + 3);
   return T[0] + T[1] == T[2];
}

int main(int argc, char *argv[]) { 
   int xi, yi;
   for(int i = 0; i < 3; ++i) {
      cin >> xi >> yi;
      P.push_back(make_pair(xi,yi));
   }
   if(is_right(P[0], P[1], P[2])) {
      cout << "RIGHT" << endl;
      return 0;
   }
   for(int i = 0; i < 3; ++i) {
      for(int j = -1; j <= 1; j+=2) {
         P[i].x += j;
         if(is_right(P[0], P[1], P[2])) {
            cout << "ALMOST" << endl;
            return 0;
         }
         P[i].x -= j;
         P[i].y += j;
         if(is_right(P[0], P[1], P[2])) {
            cout << "ALMOST" << endl;
            return 0;
         }
         P[i].y -= j;
      }
   }
   cout << "NEITHER" << endl;
   return 0;
}

