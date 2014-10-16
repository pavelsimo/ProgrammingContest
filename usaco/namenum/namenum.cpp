/*
ID: 0000
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

int N;
bool found = false;
set<string> dict;
string a[] = {"","","ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"};

void doit(int cur, string s) {
	if(cur==N) {
		if(dict.count(s)>0) {
			printf("%s\n",s.c_str());
			found = true;
		}
	} else {
		int pos = s[cur]-'0';
		for(int i = 0; i < a[pos].size(); ++i) {
			s[cur] = a[pos][i];
			doit(cur+1,s);
		}
	}
}

void load_data() {
	string line;
	ifstream myfile("dict.txt");
	if (myfile.is_open()) {
		while ( myfile.good() ) {
			getline (myfile,line);
			if(line.size()==0) continue;
			dict.insert(line);
		}
		myfile.close();
	}
}

int main() {
	load_data();
	freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w", stdout);
	string word;
	getline(cin,word);
	N = word.size();
	doit(0,word);
	if(!found) puts("NONE");
	return 0;
}
