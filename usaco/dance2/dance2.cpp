/*
ID: 11
PROG: dance2
LANG: C++
*/
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

int main() {
	freopen("dance2.in", "r", stdin);
	freopen("dance2.out", "w", stdout);
	int N, M;
	string s;
	cin >> N;
	for(int i = 0; i < N; ++i) {
		stack<char> Q;
		bool ok = true;
		cin >> M >> s;
		for(int j = 0; j < M; ++j) {
			if(s[j]=='>') {
				Q.push(s[j]);
			} else if(s[j]=='<') {
				if(!Q.empty()) {
					char ch = Q.top();
					Q.pop();
					if(ch=='<') {
						ok = false;
						break;
					}
				} else {
					ok = false;
					break;
				}
			}
		}
		if(!Q.empty()) ok = false;
		if(ok) cout << "legal" << endl;
		else cout << "illegal" << endl;
	}
	return 0;
}
