/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10235  C++  "Primes" */
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 1000000;
int prime[MAXN+10];
int emirp[MAXN+10];

int rev(int i) {
	string ans="";
	int x = i;
	while(x>0) {
		ans+=((x%10)+'0');
		x/=10;
	}
	return atoi(ans.c_str());
}

void sieve(int n) {
   for(int i = 0; i <= n; ++i) {
		prime[i] = 1;
		emirp[i] = 0;
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
	for(int i = 0; i <= n; ++i) {
		if(prime[i]) {
			int j = rev(i);
			if(i!=j) if(prime[j]) emirp[i] = 1;
		}
	}
} 

int main(int argc, char *argv[]) {
	sieve(MAXN+1);
	int n;
	while(scanf("%d",&n)==1) {
		if(emirp[n]) printf("%d is emirp.\n",n);
		else if(prime[n]) printf("%d is prime.\n",n);
		else printf("%d is not prime.\n",n);
	}	
	return 0;
}
/* @END_OF_SOURCE_CODE */
