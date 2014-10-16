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
	char name[36];
	int a;
	int d;
	bool operator< (const Player &T) const {
		return strcasecmp(name,T.name) < 0;
	}
};

const int N = 10;
Player p[N];
char buf[1024];

int main(int argc, char *argv[]) {
	int TC, attack, defense, atk[5], def[5];
	gets(buf);
	sscanf(buf,"%d",&TC);
	for(int tc=1; tc<=TC; ++tc) {				
		for(int i = 0; i < N; ++i) {
			gets(buf);
			sscanf(buf,"%s %d %d",&p[i].name,&p[i].a,&p[i].d);
		}
		sort(p,p+N);
		attack = defense = 0;
		for(int a = 0; a < N; ++a) {
			for(int b = a+1; b < N; ++b) {
				for(int c = b+1; c < N; ++c) {
					for(int d = c+1; d < N; ++d) {
						for(int e = d+1; e < N; ++e) {
							int cattack = p[a].a+p[b].a+p[c].a+p[d].a+p[e].a;
							int cdefense = 0;
							for(int k = 0; k < N; ++k) {
								if(k==a||k==b||k==c||k==d||k==e) continue;
								cdefense+=p[k].d;
							}
							if(cattack > attack || (cattack == attack && cdefense > defense)) {
								attack = cattack;
								defense = cdefense;
								atk[0] = a; atk[1] = b; atk[2] = c; atk[3] = d; atk[4] = e;
								for(int k=0, j=0; k < N; ++k) {
									if(k==a||k==b||k==c||k==d||k==e) continue;
									def[j++] = k;
								}
							}
						}
					}
				}
			}
		}
		printf("Case %d:\n",tc);
		printf("(");
		for(int i = 0; i < 5; ++i) {
			if(i>0)printf(", ");
			printf("%s",p[atk[i]].name);
		}
		printf(")\n");
		printf("(");
		for(int i = 0; i < 5; ++i) {
			if(i>0)printf(", ");
			printf("%s",p[def[i]].name);
		}
		printf(")\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

