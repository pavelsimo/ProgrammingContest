/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11512  C++  "Simple Math" */
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
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)


int getscore(string &s, string &target) {
	int ans = 0;
	int pos = 0;
	while((pos=s.find(target,pos))!=string::npos) {
		ans++;
		pos++;
	}
	return ans;
}

int main(int argc, char *argv[]) {
	int TC, n, cnt, best, size;
	string s;
	scanf("%d\n",&TC);
	while(TC-- > 0) {
		set<string> vis;
		getline(cin,s);
		n=s.size();
		//cout << "string: " << s << endl;
		best = 0;
		cnt=0;
		string ans="";
		for(int i = 0; i < n; ++i) {
			for(int j = n; j >= 1; --j) {
				string t = s.substr(i,j);
				if(vis.count(t) == 0) {
					vis.insert(t);
					int score = getscore(s,t);
					if(score > 1) {
						if(t.size() > best) {
							best = t.size();
							cnt=score;
							ans = t;						
						}			
						if(t.size() == best)
							if(strcmp(t.c_str(),ans.c_str()) < 0) ans = t;
					}				
					//cout <<  t << " " << score << endl;
				}
				
			}		
		}
		
		if(ans=="") printf("No repetitions found!\n");
		else printf("%s %d\n",ans.c_str(),cnt);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

