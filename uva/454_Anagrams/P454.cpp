/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  454  C++  "Ad Hoc" */
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
#include <list>
#include <utility>
using namespace std;
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

struct String {
   string key, value;
	String(string _key, string _value) : key(_key), value(_value) {}
	bool operator< (const String &T) const {
		return strcmp(value.c_str(), T.value.c_str()) < 0;
	}
};

vector<String> a;

int main(int argc, char *argv[]) {
	int TC;
	string buf;
	getline(cin,buf);
	sscanf(buf.c_str(),"%d",&TC);
	getline(cin,buf);
	for(int tc=0; tc<TC; ++tc) {
		if(tc>0)putchar('\n');
		a.clear();
		while(getline(cin,buf)) {
			string key="";
			for(int i = 0; i < buf.size(); ++i) 
				if(!isspace(buf[i])) key+=buf[i];
			if(key=="") break;
			sort(key.begin(),key.end());
			a.push_back(String(key,buf));
		}
		sort(a.begin(),a.end());
		for(int i = 0; i < a.size()-1; ++i) {
			for(int j = i+1; j < a.size(); ++j) {
				if(a[i].key==a[j].key) 
					printf("%s = %s\n",a[i].value.c_str(),a[j].value.c_str());
			}
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

