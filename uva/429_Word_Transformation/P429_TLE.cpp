/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  429  C++  "Graph Theory, BFS" */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
#define BITCOUNT(mask) ( __builtin_popcount((mask)) )
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

typedef pair<string,int> node;
set<string> dictionary;

int bfs(string &src, string &dest) {
	set<string> vis;
	queue<node> q;
	q.push(make_pair(src,0));
	while(!q.empty()) {
		node s = q.front();
		q.pop();
		if(s.first == dest) return s.second;
		string ns = s.first;
		for(int i = 0; i < s.first.size(); ++i) {
			for(char ch = 'a'; ch <= 'z'; ++ch) {
				if(ch!=ns[i]) {
					char t = ns[i];
					ns[i] = ch;
					if(vis.count(ns)==0 && dictionary.count(ns) > 0) {
						vis.insert(ns);
						q.push(make_pair(ns,s.second+1));
					}
					ns[i] = t;
				}
			}
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	int TC, done=0;
	string buf;
	string src, dest;
	scanf("%d\n",&TC);
	for(int tc=0; tc < TC; ++tc) {
		if(tc!=0) putchar('\n');
		done = 0;
		while(getline(cin,buf)) {
			if(buf[0]=='*') {
				while(getline(cin,buf)) {
					if(buf.size()==0) break;
					istringstream ncin(buf);
					getline(ncin,src,' ');
					getline(ncin,dest,' ');
					done=1;
					printf("%s %s %d\n",src.c_str(),dest.c_str(),bfs(src,dest));
				}
				dictionary.clear();
				if(done) break;
			}
			if(done) break;
			dictionary.insert(buf);
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
