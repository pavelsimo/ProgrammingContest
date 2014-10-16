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

typedef pair<string,string> ss;
const string dst = "123456789";
char buf[32];
int a[3][3];

template <typename T> string tostr(const T& t) { 
	ostringstream os; 
	os<<t; 
	return os.str(); 
}

void hshift(string &s, int row) {
	int pos = row*3;
	char a=s[pos], b=s[pos+1], c=s[pos+2];
	s[pos]=c; s[pos+1]=a; s[pos+2]=b;
}

void vshift(string &s, int col) {
	int pos = col;
	char a=s[pos], b=s[pos+3], c=s[pos+6];
	s[pos]=b; s[pos+3]=c; s[pos+6]=a;
}

map<string,int> D;
void bfs(string &src) {
   D.clear();
	queue<ss> Q;
	Q.push(ss(src,""));
	D[src]=0;
	bool found = false;
	while(!Q.empty()) {
		ss cur = Q.front(); Q.pop();
		if(cur.first==dst) { 
			printf("%d %s\n",D[cur.first],cur.second.c_str());
			found = true;
			break;
		}
		for(int k = 0; k < 2; ++k) {
			for(int i = 0; i < 3; ++i) {
				string ns = cur.first;
				if(k)hshift(ns,i);
				else vshift(ns,i);
				if(D.count(ns)==0) {
					D[ns] = D[cur.first]+1;
					string path = cur.second; 
					char ch = (k)?'H':'V';
					char num = '1'+i;
					path+=ch;
					path+=num;
					Q.push(ss(ns,path));
				}
			}		
		}
	}
	if(!found) puts("Not solvable");
}

int main(int argc, char *argv[]) {
	string src;
	while(scanf("%d%d%d%d%d%d%d%d%d",
		&a[0][0],&a[0][1],&a[0][2],
		&a[1][0],&a[1][1],&a[1][2],
		&a[2][0],&a[2][1],&a[2][2])==9) {
		src="";
		for(int i = 0; i < 3; ++i) {
			for(int j = 0; j < 3; ++j) {
				src+=tostr(a[i][j]);
			}
		}
		bfs(src);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

