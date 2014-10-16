/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11804  C++  "Brute Force" */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

using namespace std;

struct Player {
	char name[32];
	int a;
	int d;
	bool operator< (const Player &T) const {
		if(T.a!=a) return T.a < a;
		if(T.d!=d) return T.d > d;
		return strcasecmp(name,T.name) < 0;
	}
};

struct cmp {
	bool operator()(const Player &a, const Player &b) const {
		return strcasecmp(a.name,b.name) < 0;
	}
};

const int N = 10;
Player p[N];
char buf[1024];

int main(int argc, char *argv[]) {
	int TC;
	gets(buf);
	sscanf(buf,"%d",&TC);
	for(int tc=1; tc<=TC; ++tc) {				
		for(int i = 0; i < N; ++i) {
			gets(buf);
			sscanf(buf,"%s %d %d",&p[i].name,&p[i].a,&p[i].d);
		}
		sort(p,p+N);
		sort(p,p+5,cmp());
		sort(p+5,p+10,cmp());
		printf("Case %d:\n",tc);
		printf("(");
		for(int i = 0; i < 5; ++i) {
			if(i>0)printf(", ");
			printf("%s",p[i].name);
		}
		printf(")\n");
		printf("(");
		for(int i = 5; i < 10; ++i) {
			if(i>5)printf(", ");
			printf("%s",p[i].name);
		}
		printf(")\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

