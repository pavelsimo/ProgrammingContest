/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11777  C++  "Ad Hoc" */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;

const int N = 3;
int test[N];

int main(int argc, char *argv[]) {
	int TC, grade, term1, term2, final, attendance;
	scanf("%d",&TC);
	for(int tc=1; tc<=TC; ++tc) {
		scanf("%d%d%d%d%d%d%d",&term1,&term2,&final,
			&attendance,&test[0],&test[1],&test[2]);
		sort(test,test+N);
		grade = term1+term2+final+attendance+((test[2]+test[1])/2);
		printf("Case %d: ",tc);
		if(grade>=90) puts("A");
		else if(grade>=80) puts("B");
		else if(grade>=70) puts("C");
		else if(grade>=60) puts("D");
		else puts("F");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
