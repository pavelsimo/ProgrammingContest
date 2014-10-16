#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

int prices[102], freq[102];
map<string, int> fruits;

int main(int argc, char *argv[]) {
   int n, m, a, b, k;
   string name;
   cin >> n >> m;
   for(int i = 0; i < n; ++i) {
      cin >> prices[i];
   }
   for(int i = 0; i < m; ++i) {
      cin >> name;
      fruits[name]++;
   }
   k = 0;
   foreach(it, fruits) freq[k++] = it->second;
   sort(prices, prices + n);
   sort(freq, freq + k);
   a = b = 0;
   for(int i = k - 1, j = 0; i >= 0; --i, ++j) {
      a += prices[j] * freq[i];
      b += prices[n-j-1] * freq[i];
   }
   cout << a << ' ' << b << endl;
   return 0;
}

