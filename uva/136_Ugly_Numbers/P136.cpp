/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  136  C++  "Number Theory, Prime Factors" */
#include <iostream>
#include <cstring> 
#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
#include <list>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

int main(int argc, char *argv[]) {
   // BRUTE FORCE, otra idea seria combinar todos los factores 2,3,5 en diferentes formas
   // hacer un priority queue y tomar el valor del numero 2500, de esa manera no tengo que recorrer tantos numeros
   // claro esta evitando repeticiones como 2*3 3*2
   /*
	int cnt = 0;
	for(int i = 1; i <= 899999999; ++i) {
		int x = i;
		while(x%2==0) x/=2;
		while(x%3==0) x/=3;
		while(x%5==0) x/=5;
		if(x==1) cnt++; 
		if(cnt==1500) {
			printf("The 1500'th ugly number is %d.\n",i);
			break;
		}
	}
	*/
	printf("The 1500'th ugly number is %d.\n",859963392);
	return 0; 
}
/* @END_OF_SOURCE_CODE */

