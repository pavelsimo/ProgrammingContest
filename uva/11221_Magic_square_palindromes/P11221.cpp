/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11221  C++  "Ad Hoc" */

#include <iostream>
#include <cmath>
using namespace std;

string buf;

bool is_perfect_square(int n) {
	int x = (int)floor(sqrt(n));
	return x*x==n;
}

int main(int argc, char *argv[]) {
	int TC, N, M, l, r;
	string s;
	getline(cin,buf);
	sscanf(buf.c_str(),"%d",&TC);
	for(int tc=1; tc<=TC; ++tc) {
		getline(cin,buf);
		s = "";
		for(int i = 0; i < buf.size(); ++i) {
			if(isalpha(buf[i])) 
				s+=buf[i];
		}
		N = s.size();
		bool ok = true;
		if(is_perfect_square(N)) {
			M = (int)sqrt(N);
			l = 0;
			r = N-1;
			while(l < r) {
				if(s[l]!=s[r]) {
					ok = false;
					break;
				}
				l++;
				r--;
			}
			l = 0;
			r = N-1;
			for(int i=l,j=r; i < M; ++i, --j) {
				for(int ll=i, rr=j; ll < N; ll+=M, rr-=M) {
					if(s[ll]!=s[rr]) {
						ok = false;
						break;
					}
				}
				if(!ok) break;
			}
		} else {
			ok = false;
		}
		printf("Case #%d:\n",tc);
		if(ok) printf("%d\n",M);
		else puts("No magic :(");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
