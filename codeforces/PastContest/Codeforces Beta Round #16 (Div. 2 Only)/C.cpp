#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef long long llong;

int main(int argc, char *argv[]) {
   int a, b, x, y;
   cin >> a >> b >> x >> y;
   int g = __gcd(x, y);
   x/=g;
   y/=g;
   int mi = min(a/x, b/y);
   cout << mi * x << ' ' << mi * y << endl;
   return 0;
}

