/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10928  C++  "Graph Theory" */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;

const int maxn = 1024, INF=1000000000;
int out_deg[maxn];
string buf;
vector<int> a;

int main(int argc, char *argv[]) {
	int TC, N, u, v, best;
	getline(cin,buf);
	sscanf(buf.c_str(),"%d",&TC);
	for(int tc=0; tc<TC; ++tc) {
		getline(cin,buf); 
		sscanf(buf.c_str(),"%d",&N);
		memset(out_deg,0,sizeof(out_deg));
		a.clear();
		best=INF;
		for(u = 1; u <= N; ++u) {
			getline(cin,buf);
			istringstream in(buf);
			while(in >> v)
				++out_deg[u];
			best=min(best,out_deg[u]);
		}
		for(int i = 1; i <= N; ++i) {
			if(out_deg[i]==best) 
				a.push_back(i);
		}
		for(int i = 0; i < a.size(); ++i) {
			if(i>0)putchar(' ');
			printf("%d",a[i]);
		}
		putchar('\n');
		getline(cin,buf);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
