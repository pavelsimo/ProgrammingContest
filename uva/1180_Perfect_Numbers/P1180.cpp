/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  1180  C++  "Number Theory, Perfect Numbers" */
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

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef long long llong;

typedef unsigned long long ullong;

vector<int> primes;

const unsigned int MAXP = 100;

bool sieve[MAXP+1];
#define NOTPRIME(b) (sieve[(b)])

void sieve_erastothenes() {
   register unsigned int p;
   primes.clear();
   primes.reserve((int) ceil((MAXP+1)/log(MAXP+1)*(1 + 1.2762/log(MAXP+1))));
   sieve[0] = sieve[1] = true;
   for (p = 2; ; ++p) {
      ullong p2 = ((ullong) p) * ((ullong) p);
      if (p2 > MAXP) break;
      if (NOTPRIME(p)) continue;
      primes.push_back(p);
      for (ullong k = p2; k <= MAXP; k += p)
         sieve[k] = true;
   }
   for (; p <= MAXP; ++p) {
      if (NOTPRIME(p)) continue;
      primes.push_back(p);
   }
}

typedef long long llong;

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   sieve_erastothenes();
   int N;
   llong p;
   string s, token;
   getline(cin, s); 
   sscanf(s.c_str(), "%d", &N);
   getline(cin, s); 
   istringstream in(s);
   for(int i = 0; i < N; ++i) {
      getline(in, token, ',');
      sscanf(token.c_str(), "%lld", &p);
      // Euclid proved that 2^p−1(2^p−1) is an even perfect number 
      // whenever 2^p−1 is prime, where p is a prime number
      // (Euclid, Prop. IX.36).
      if(binary_search(all(primes), p) 
         && binary_search(all(primes), (1LL << p) - 1LL)) {
         cout << "Yes" << '\n';
      } else {
         cout << "No" << '\n';
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
