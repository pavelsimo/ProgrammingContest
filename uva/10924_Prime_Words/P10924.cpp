/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10924  C++  "Ad Hoc" */
#include <iostream>
#include <cstring> 
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAXN = 10000;
int prime[MAXN+2];
char buf[32];

void sieve(int n) {
   for(int i = 0; i <= n; ++i) prime[i] = 1;
   prime[0]=0;
   prime[1]=0;
   int m = (int)sqrt(n);
   for (int i=2; i<=m; i++)
      if (prime[i])
         for (int k=i*i; k<=n; k+=i)
            prime[k]=0;
} 

int main(int argc, char *argv[]) {
	sieve(MAXN);
	prime[1]=1; // i don't understand why in this problem "1" is a prime number...
	int n,cost;
	while(gets(buf)) {
		n=strlen(buf);
		cost=0;
		for(int i = 0; i < n; ++i) {
         if(buf[i] >= 'a' && buf[i] <= 'z') 
				cost+=buf[i]-'a'+1;
			else 
				cost+=buf[i]-'A'+27;
		}
		if(prime[cost]) printf("It is a prime word.\n");
		else printf("It is not a prime word.\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

