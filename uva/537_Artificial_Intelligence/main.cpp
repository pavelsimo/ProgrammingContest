/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  537  C++  "String Manipulation, Simple Math" */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

int main(int argc, char *argv[]) {
	int TC, pos, search, end, nunit;
	double T, P, U, I, prefix;
	char ch, unit[3];
	string line, s;
	scanf("%d\n",&TC);
	pos = 0;
	REP(tc,TC) {
		getline(cin,line);
		pos = 0;
		T = P = U = I = 0.0;
		while((search = line.find('=',pos)) != string::npos) {
			pos = search-1;
			end = pos;
			while(true) {
				end++;
				if(line[end]=='A'
					|| line[end]=='W' 
					|| line[end]=='V') break;
			}
			s = line.substr(pos,end-pos+1);
			sscanf(s.c_str(),"%c=%lf%s",&ch,&T,&unit);
			prefix = 1.0;
			if(strlen(unit) > 1) {
				if(unit[0]=='m') prefix = 10E-4;
				else if(unit[0]=='k') prefix = 10E2;
				else if(unit[0]=='M') prefix = 10E5;
			}
			if(ch=='P') P = T*prefix;
			else if(ch=='U') U = T*prefix;
			else if(ch=='I') I = T*prefix;
			pos = end+1;
		}
		printf("Problem #%d\n",tc+1);
		if(P==0.0)
			printf("P=%.2lfW\n",U*I);
		else if(I==0.0)
			printf("I=%.2lfA\n",P/U);
		else if(U==0.0)
			printf("U=%.2lfV\n",P/I);
		putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

