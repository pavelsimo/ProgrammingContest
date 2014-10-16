/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10282  C++  "Ad Hoc" */
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


int main(int argc, char *argv[]) {
	map<string, string> dictionary;
	string buf;
	string word, translation;
	while(getline(cin,buf)) {
      if(buf=="") break;
		istringstream token(buf);
		getline(token, word, ' ');
		getline(token, translation, ' ');
		dictionary[translation] = word;
	}
	while(getline(cin,buf))
		printf("%s\n", dictionary.count(buf) > 0 ? dictionary[buf].c_str(): "eh");
}

/* @END_OF_SOURCE_CODE */

