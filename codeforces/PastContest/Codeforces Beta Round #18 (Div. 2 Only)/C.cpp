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

const int MAXN = 100002;
llong a[MAXN];

int main(int argc, char *argv[]) {
   int n, res = 0;
   cin >> n;
   for(int i = 0; i < n; ++i)
      cin >> a[i];
   for(int i = 1; i < n; ++i)
      a[i] += a[i-1];
   for(int i = 0; i < n - 1; ++i) {
      if(a[i] == a[n-1] - a[i]) 
         res++;  
   }
   cout << res << endl;
   return 0;
}

