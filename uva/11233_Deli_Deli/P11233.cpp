/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  422  C++  "String Manipulation" */
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

int isvocal(char c) {
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int main(int argc, char *argv[]) {
	int n,m;
	string verb,plural;
	while(scanf("%d%d",&m,&n)==2) {
		map<string, string> irregular;
		for(int i = 0; i < m; ++i) {
			cin >> verb;
			cin >> plural;
			irregular[verb] = plural;
		}
		for(int i = 0; i < n; ++i) {
			cin >> verb;
			if(irregular.count(verb)>0) {
				cout << irregular[verb] << endl;
			} else if( verb.size() > 1 && (( !isvocal(verb[verb.size()-2]) && verb[verb.size()-1]=='y')) ) {
				cout << verb.substr(0,verb.size()-1) + "ies" << endl;
			} else if( verb[verb.size()-1]=='o' || verb[verb.size()-1]=='s' || verb[verb.size()-1]=='x') {
				cout << verb + "es" << endl;
			} else if( verb.size() > 1 && 
				( (verb[verb.size()-1]=='h' && verb[verb.size()-2]=='c')
				||(verb[verb.size()-1]=='h' && verb[verb.size()-2]=='s'))) {
				cout << verb + "es" << endl;
			} else { 
				cout << verb+"s" << endl;
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

