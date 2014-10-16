/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10533  C++  "Primes" */
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <vector>
using namespace std;

const int MAXN = 1000000;
int prime[MAXN+10];
int digitPrimes[MAXN+10];

int sumDigits(int i) {
	int x = i;
	int ans = 0;
	while(x>0) {
		ans+=x%10;
		x/=10;
	}
	return ans;
}

void sieve(int n) {
   for(int i = 0; i <= n; ++i) {
		prime[i] = 1;
		digitPrimes[i] = 0;
	}
   prime[0]=0;
   prime[1]=0;
   int m = (int)sqrt(n);
   for (int i=2; i<=m; i++) {
      if (prime[i]) {
			for (int k=i*i; k<=n; k+=i) {
				prime[k]=0;	
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
      digitPrimes[i] = digitPrimes[i-1];
      if(prime[i])
          if(prime[sumDigits(i)]) digitPrimes[i]++;
	}
} 

int main(int argc, char *argv[]) {
	sieve(MAXN+1);
	int TC, start, end, x, y, ans;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%d%d",&x,&y);
		start = min(x,y);
		end = max(x,y);
		ans = digitPrimes[end]-digitPrimes[start-1 < 0? 0 : start-1];
		printf("%d\n",ans);
	}	
	return 0;
}
/* @END_OF_SOURCE_CODE */
