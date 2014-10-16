#include <cstdio>
#include <stack>
using namespace std;

#define SIZE 130

int main(int argc, char *argv[]) {
	
	int TC, ok, N;
	char c, buf[SIZE];
	scanf("%d\n",&TC);
	while ( TC-- > 0 ) {
		stack<char> a;
		ok = 1;
		gets(buf);
		N = strlen(buf);
		for(int i = 0; i < N; ++i) {
			c = buf[i];
			if ( c == '(' ) a.push('(');
			if ( c == '[' ) a.push('[');
			
			if ( c == ')' ) { 
				if ( a.empty() || a.top() == '[' ) { 
					ok = 0;
					break;
				}
				a.pop();
			}
			if ( c == ']' ) {
				if ( a.empty() || a.top() == '(' ) { 
					ok = 0;
					break;
				}
				a.pop();
			}
		}
		if ( a.empty() && ok ) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}
