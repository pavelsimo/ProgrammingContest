/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10070  C++  "Ad Hoc" */
#include <iostream>
#include <cstring> 
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

bool isleapyear(int year) {
	if(year%400==0) return true;
	if(year%100==0) return false;
	if(year%4==0) return true;
	return false;
}

bool ishuluculu(int year) {
	return (year%15)==0;
}

bool isbulukulu(int year) {
	return isleapyear(year) && (year%55)==0;
}

int main(int argc, char *argv[]) {
   int n, opt;
	while(scanf("%d",&n)==1) {
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
