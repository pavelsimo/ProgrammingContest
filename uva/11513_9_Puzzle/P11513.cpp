/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11513  C++  "Graph Theory, BFS" */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

char buf[32];
int a[3][3];

void hshift(string &s, int row) {
	int pos = row*3;
	char a=s[pos], b=s[pos+1], c=s[pos+2];
	s[pos]=b; s[pos+1]=c; s[pos+2]=a;
}

void vshift(string &s, int col) {
	int pos = col;
	char a=s[pos], b=s[pos+3], c=s[pos+6];
	s[pos]=c; s[pos+3]=a; s[pos+6]=b;
}

map<string, pair<int,string> > D;
void bfs(string &src) {
   D.clear();
	queue<string> Q;
	Q.push(src);
	D[src]=make_pair(0,"");
	while(!Q.empty()) {
		string cur = Q.front(); Q.pop();
		for(int k = 0; k < 2; ++k) {
			for(int i = 0; i < 3; ++i) {
				string ns = cur;
				if(k) vshift(ns,i);
				else hshift(ns,i);
				if(D.count(ns)==0) {
					Q.push(ns);
					D[ns] = make_pair(D[cur].first+1,string(1,(k)?'V':'H')+string(1,'1'+i)+D[cur].second);
				}
			}		
		}
	}
}

int main(int argc, char *argv[]) {
	string src="123456789";
	bfs(src);
	while(scanf("%d%d%d%d%d%d%d%d%d",
		&a[0][0],&a[0][1],&a[0][2],
		&a[1][0],&a[1][1],&a[1][2],
		&a[2][0],&a[2][1],&a[2][2])==9) {
		sprintf(buf,"%d%d%d%d%d%d%d%d%d",a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
		string dst(buf);
		if(!D.count(dst)) puts("Not solvable");
		else printf("%d %s\n",D[dst].first,D[dst].second.c_str());
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

