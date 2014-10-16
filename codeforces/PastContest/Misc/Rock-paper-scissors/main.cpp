#include <cstring>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
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
using namespace std;

string buf[3];
char ans[]= {'F','M','S'};

int compare(string &p1, string &p2) {
	if(p1=="rock" && p2=="scissors") return 1;
	if(p2=="rock" && p1=="scissors") return -1;
	if(p1=="scissors" && p2=="paper") return 1;
	if(p2=="scissors" && p1=="paper") return -1;
	if(p1=="paper" && p2=="rock") return 1;
	if(p2=="paper" && p1=="rock") return -1;
	return 0;
}

int main() {
	getline(cin,buf[0]);
	getline(cin,buf[1]);
	getline(cin,buf[2]);
	int n = 3;
	bool found = false;
	for(int i = 0; i < n; ++i) {
		int cnt=0;
		for(int j = 0; j < n; ++j) {
			if(i==j) continue;
			if(compare(buf[i],buf[j])==1)cnt++;
		}
		if(cnt==2) {
			printf("%c\n",ans[i]);
			found=true;
			break;
		}
	}
	if(!found) printf("?\n");
   return 0;
}
