/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  113  C++  "Simple Math" */
#include <iostream>
#include <cstring> 
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
/*
float 32 6~7 10^(-37) ~  10^38
double 64 15~16 10^(-307)   ~   10^308
long double 128 18~19 10^(-4931)  ~  10 ^ 4932
*/
int main(int argc, char *argv[]) {	
	double n,p;
	while(scanf("%lf%lf",&n,&p)==2) {
		printf("%.0lf\n",pow(p,1.0/n));
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

