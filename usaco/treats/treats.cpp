/*
ID: 13
PROG: treats
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
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
using namespace std;

int N, M;
typedef pair<int,int> pii;
bool row[50];
bool col[50];
int B[50][50];
set<int> L;


pii getNext() {
	int best = -1;
	int r = -1;
	int c = -1;
	for(int i = 0; i < M; ++i) {
		for(int j = 0; j < N; ++j) {
			if(row[i] && col[i]) continue;
			if(L.count(B[i][j])==0 && B[i][j] > best) {
				best = B[i][j];
				r = i;
				c = j;
			}
		}
	}
	L.insert(best);
	return pii(r,c);
}

int main() {
	freopen("treats.in", "r", stdin);
	freopen("treats.out", "w", stdout);
	scanf("%d%d",&N,&M);
	for(int i = 0; i < M; ++i) {
		for(int j = 0; j < N; ++j) {
			scanf("%d",&B[i][j]);
		}
	}
	
	while(true) {
		pii cur = getNext();
		int nr = cur.first;
		int nc = cur.second;
		if(nr<0 && nc <0) break;
		for(int r = 0; r < M; ++r) {			
			if(!row[r]) {
				row[r] = true;
				for(int c = 0; c < N; ++c) {
					int t = B[r][c];
					B[r][c] = B[nr][c];
					B[nr][c] = t;
				}
			}
		}
		for(int c = 0; c < N; ++c) {			
			if(!col[c]) {
				col[c] = true;
				for(int r = 0; r < M; ++r) {
					int t = B[r][c];
					B[r][c] = B[r][nc];
					B[r][nc] = t;
				}
			}
		}
	}
	
	for(int i = 0; i < M; ++i) {
		for(int j = 0; j < N; ++j) {
			if(j > 0) putchar(' ');
			printf("%d",B[i][j]);
		}
		putchar('\n');
	}
	return 0;
}
