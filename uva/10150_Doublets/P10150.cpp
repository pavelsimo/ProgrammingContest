/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10150 C++  "Graph Theory, BFS" */
#include <iostream>
#include <cstring> 
#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
#include <bitset>
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

struct String {
	string s;
	int id;
	String(string _s="", int _id=0): s(_s), id(_id){ }
	bool operator<(const String& obj) const {
		return s < obj.s;
	}
};

const int maxn = 25150;
const int size = 17;
char buf[128];
char src[32];
char dst[32];
string dict[maxn];
vector<string> word[17];
map<string,int> index;
vector<vector<int>> adj;


/*
TODO: 
 - Adjacent Matrix Data Structure
 - Create Adjacent Matrix
 - Implement BFS Search
*/

int bfs(int src, int dst) {
	

	return 0;
}

void doit() {
	for(int i = 2; i < size; ++i) {
		vector<String> 
	
		for(int j = 0; j < i; ++j) {
			
		
		}
	}
}

int find(string s) {
	int L = s.size();
	int lo = 0, hi = word[L].size();
	while(lo<=hi) {
		int mid = (lo+hi)/2;
		if(word[L][mid] < s)
			lo = mid+1;
		else if(word[L][mid] > s)
			hi = mid;
		else 
			return mid;
	}
	return -1;
}

int main(int argc, char *argv[]) {
	int n, isrc, idst;
	for(n = 0; gets(buf) && *buf; ++n) {
		string nw = string(buf);
		dict[n] = nw;
		word[nw.size()].push_back(nw);
		index[nw] = n;
	}
	for(int i = 0; i < size; ++i) sort(word[i].begin(),word[i].end());
	
	// DEBUG
	for(int i = 0; i < size; ++i) {
		printf("size=%d\n",i);
		for(int j = 0; j < word[i].size(); ++j)
			cout << word[i][j] << " ";
		putchar('\n');
	}
		
	// create adjacent list
	doit();
	
	while(gets(buf)) {
		if(sscanf(buf,"%s %s",&src,&dst)!=2) break;
		isrc = find(string(src));
		idst = find(string(dst));
		
		// DEBUG
		cout << src << " " << "isrc=" << isrc << endl;
		cout << dst << " " <<  "idst=" << idst << endl;
		if(bfs(isrc,idst)) {
			
		} else {
		
		}
	}
	
	return 0;
}
/* @END_OF_SOURCE_CODE */

