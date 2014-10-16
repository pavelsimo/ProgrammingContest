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

const int MAXP = 2000;
vector<bool> P;
vector<int> primes;

void sieve() {
   P = vector<bool>(MAXP + 2, true);
   P[0] = P[1] = false;
   for(int i = 2; i <= MAXP; ++i) {
      if(P[i]) {
         primes.push_back(i);
         for(int j = i * i; j <= MAXP; j+=i) 
            P[j] = false;
      }
   }
}

int freq[26], freqP[MAXP];
int main(int argc, char *argv[]) {
   sieve();
   string s;
   cin >> s;
   for(int i = 0; i < sz(s); ++i) 
      freq[s[i]-'a']++;
   // DEBUG
   for(int i = 0; i < 26; ++i) {
      if(freq[i] > 0)
         printf("F[%c] = %d\n",'a'+i,freq[i]);
   }
   for(int i = 0; i < sz(primes); ++i) {
      int p = primes[i];
      if(p >= sz(s)) break;
      for(int j = 1; j <= sz(s); ++j) {
         if(p >= sz(s)) break;
         freqP[primes[i]]++;
         p = primes[i]*(j+1);
      }
      DEBUG(freqP[primes[i]]);
   }
   return 0;
}

