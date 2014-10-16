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

typedef long long llong;

struct event {
   int ind;      // Index of rectangle in rects
   bool type;    // Type of event: 0 = Lower-left ; 1 = Upper-right
   event() {};
   event(int ind, int type) : ind(ind), type(type) {};
};

struct point {
   int x, y;
};

int n, e; // n = number of rectangles; e = number of edges
point rects [1000][2];  // Each rectangle consists of 2 points: [0] = lower-left ; [1] = upper-right
event events_v [2000];  // Events of horizontal sweep line
event events_h [2000];  // Events of vertical sweep line
bool compare_x(event a, event b) { return rects[a.ind][a.type].x<rects[b.ind][b.type].x; }
bool compare_y(event a, event b) { return rects[a.ind][a.type].y<rects[b.ind][b.type].y; }
bool in_set [10000];    // Boolean array in place of balanced binary tree (set)
long long area;         // The output: Area of the union

int main() {   /// x -> v; y -> h
   scanf("%d", &n);
   for (int i=0;i<n;++i) {
           scanf("%d %d %d %d", &rects[i][1].x, &rects[i][1].y,   // Lower-left coordinate
                                &rects[i][0].x, &rects[i][0].y);  // Upper-right coordinate
           events_v[e] = event(i, 0);
           events_h[e++] = event(i, 0);
           events_v[e] = event(i, 1);
           events_h[e++] = event(i, 1);
   }
   sort(events_v, events_v+e, compare_x);
   sort(events_h, events_h+e, compare_y);  // Pre-sort set of horizontal edges
   in_set[events_v[0].ind] = 1;
   for (int i=1;i<e;++i) {  // Vertical sweep line
           event c = events_v[i];
           int cnt = 0;  // Counter to indicate how many rectangles are currently overlapping
           // Delta_x: Distance between current sweep line and previous sweep line
           int delta_x = rects[c.ind][c.type].x - rects[events_v[i-1].ind][events_v[i-1].type].x;
           int begin_y;
           if (delta_x==0) continue;
           for (int j=0;j<e;++j) if (in_set[events_h[j].ind]==1) {  // Horizontal sweep line
                   if (events_h[j].type==0) {
                           if (cnt==0) begin_y = rects[events_h[j].ind][0].y;  // Block starts
                           ++cnt;
                   } else {
                           --cnt;
                           if (cnt==0) { // Block ends
                                   int delta_y = (rects[events_h[j].ind][1].y-begin_y);
                                   area+=delta_x * delta_y;
                           }
                   }
           }
           in_set[c.ind] = (c.type==0);
   }
   printf("%lld\n", area);
   return 0;
}


