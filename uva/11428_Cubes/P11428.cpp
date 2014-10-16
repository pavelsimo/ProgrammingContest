/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11428  C++  "Ad Hoc, Simple Math" */
#include <iostream>
#include <cmath>
using namespace std;

bool is_perfect_cube(int n) {
    int root = round(pow(n,1.0/3.0));
    return n == root*root*root;
}
		  
int main(int argc, char *argv[]) {
   int N, x, y;
	while(scanf("%d",&N)==1) {
		if(N==0) break;
		bool found = false;
		for(x = 0; x <= 100; ++x) {
			int y3 = x*x*x-N;
         if(is_perfect_cube(y3)) {
				y = round(pow(y3,1.0/3.0));
				found = true;
				break;
			}
		}
		if(found) printf("%d %d\n",x,y);
		else puts("No solution");
	}	
	return 0;
}
/* @END_OF_SOURCE_CODE */
