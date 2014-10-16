#include <iostream>
#include <algorithm>

using namespace std;

struct Dragon {
   int x, y;
};

bool cmp(const Dragon a, const Dragon b) {
   if(a.x != b.x) 
      return a.x < b.x;
   return a.y > b.y;
}

Dragon d[10002];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int s, n;
   cin >> s >> n;
   for(int i = 0; i < n; ++i)
      cin >> d[i].x >> d[i].y;
   sort(d, d + n, cmp);
   for(int i = 0; i < n; ++i) {
      if(s > d[i].x) {
         s += d[i].y;
      } else {
         cout << "NO" << endl;
         return 0;
      }
   }
   cout << "YES" << endl;
   return 0;
}

