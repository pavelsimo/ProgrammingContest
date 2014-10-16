/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11239  C++  "Sorting" */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

using namespace std;

struct Project {
	string name;
	int n;
	Project(const string &_name) : 
		name(_name), n(0) {}
	bool operator< (const Project &t) const {
		if ( n != t.n ) 
			return t.n < n;
		return strcasecmp(name.c_str(), t.name.c_str()) < 0;
	}
};

int main(int argc, char *argv[]) {
	int k = 0;
	map<string, string> M;
	map<string, int> idx; 
	vector<Project> LP;
	set<string> blacklst;
	string s, group;
	while(getline(cin,s)) {
		if ( s[0] == '0' ) {
			break;
		} else if( s[0] == '1') {
			FORE(M,it) {
				string student = it->first;
				if(blacklst.find(student) == blacklst.end()) {
					string g = it->second;
					LP[idx[g]].n++;
				}
			}
			sort(LP.begin(),LP.end());
			REP(i,LP.size())
				printf("%s %d\n",LP[i].name.c_str(),LP[i].n);
			k = 0;
			M.clear();
			idx.clear();
			LP.clear();
			blacklst.clear();
		} else if(s[0] >= 'A' && s[0] <= 'Z') {			
			group = s;
			Project x(group);
			LP.push_back(x);
			idx[group] = k++;
		} else {
			if(M.find(s) != M.end()) {
				if(M[s] != group) blacklst.insert(s);
			} else {
				M[s] = group;
			}
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

