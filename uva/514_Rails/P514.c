/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  514  C++  "Ad Hoc, Stack" */
#include <stdio.h>
#define MAXN 1010

int target[MAXN];

int solve(int n) {
	int stack[MAXN], top=0;
	int ans = 1;
	int a = 1;
	int b = 1;
	while(b <= n) {
		if(a == target[b]) {
			a++;
			b++;
		} else if(top && stack[top] == target[b]) {
			top--; // pop()
			b++;
		} else if(a <= n) {
			stack[++top] = a++; // push(a)
		} else {
			ans = 0;
			break;
		}
	}
	return ans;
}

int main(int argc, char *argv[]) {
	int n, i;
	while(scanf("%d",&n)==1) {
		if(n==0) break;
		i=1;
		while(scanf("%d",&target[i])==1) {
			if(target[1]==0) break;
			if(i == n) {
				printf("%s\n",solve(n)?"Yes":"No");
				i = 0;
			}
			i++;
		}
		putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

