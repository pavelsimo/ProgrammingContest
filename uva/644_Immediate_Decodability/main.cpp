/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  644  C++  "Ad Hoc, String Match" */
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
	string s;
	int found;
	int TC = 0;
	vector<string> code;
	while(getline(cin,s)) {
		if(s[0] == '9') {
			TC++;
			found = 0;
			REP(i,code.size()) {
				REP(j,code.size()) {
					if(i==j)continue;
					if(code[j].find(code[i]) == 0) {
						found = 1;
						break;
					}
				}
				if(found) break;
			}
			if(found) 
				printf("Set %d is not immediately decodable\n",TC);
			else
				printf("Set %d is immediately decodable\n",TC);
			code.clear();
		} else {
			code.push_back(s);
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

