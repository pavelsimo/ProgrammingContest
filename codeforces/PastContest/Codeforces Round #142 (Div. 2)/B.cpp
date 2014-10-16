#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()

typedef long long llong;

const int MAXN = 2000000;
bool primes[MAXN];
vector<llong> P, tprimes;

void preprocess() {
   for(int i = 0; i < MAXN; ++i)
      primes[i] = true;
   primes[0] = primes[1] = false;
   for(int i = 2; i < MAXN; ++i) {
      if(primes[i]) {
         P.push_back(i);
         for(int j = i + i; j < MAXN; j+=i)
            primes[j] = false;
      }
   }   
   for(int i = 0; i < sz(P); ++i)
      tprimes.push_back(P[i]*P[i]);
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   preprocess();
   int n;
   llong x;
   cin >> n;
   while(n-- > 0) {
      cin >> x;
      cout << (binary_search(all(tprimes), x) ? "YES" : "NO") << endl;
   }
   return 0;
}

