/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10070  C++  "Ad Hoc" */
#include <iostream>
#include <cstring> 
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

bool isleapyear(ll year) {
	if(year%400LL==0LL) return true;
	if(year%100LL==0LL) return false;
	if(year%4LL==0LL) return true;
	return false;
}

bool ishuluculu(ll year) {
	return (year%15LL)==0LL;
}

bool isbulukulu(ll year) {
	return isleapyear(year) && (year%55LL)==0LL;
}

int main(int argc, char *argv[]) {
   ll n;
   int opt;
	while(scanf("%lld",&n)==1) {
      opt=0;
		if(isleapyear(n)) opt|=1;
		if(ishuluculu(n)) opt|=2;
		if(isbulukulu(n)) opt|=4;
		if(opt==0) puts("This is an ordinary year.");
		if(opt&1) puts("This is leap year.");
		if(opt&2) puts("This is huluculu festival year.");
		if(opt&4) puts("This is bulukulu festival year.");
		putchar('\n');
	}
	return 0;
}
