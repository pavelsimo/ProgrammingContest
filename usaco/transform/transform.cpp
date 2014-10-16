/*
ID: 0000
PROG: transform
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
const int maxn = 12;
char a[maxn][maxn];
char b[maxn][maxn];

bool DegreeRotation90() {
	for(int i = 0; i < N; ++i)
	for(int j = 0; j < N; ++j) 
		if(a[i][j] != b[j][N-i-1]) 
			return false;
	return true;
}

bool DegreeRotation180() {	
	for(int i = 0; i < N; ++i) 
	for(int j = 0; j < N; ++j)
		if(a[i][j] != b[N-i-1][N-j-1])
			return false;
	return true;
}

bool DegreeRotation270() {	
	for(int i = 0; i < N; ++i)
	for(int j = 0; j < N; ++j)
		if(a[i][j] != b[N-j-1][i])
			return false;
	return true;
}


bool Reflection() {	
	for(int i = 0; i < N; ++i)
	for(int j = 0; j < N; ++j)
		if(a[i][j] != b[i][N-j-1])
			return false;
	return true;
}

bool Combination() {	
	char c[maxn][maxn];
	for(int i = 0; i < N; ++i)
	for(int j = 0; j < N; ++j)
		c[i][j] = a[i][N-j-1]; // reflection
	bool d90 = true;
	bool d180 = true;
	bool d270 = true;
	for(int i = 0; i < N; ++i)
	for(int j = 0; j < N; ++j) {
		if(c[i][j] != b[j][N-i-1]) d90 = false;
		if(c[i][j] != b[N-i-1][N-j-1]) d180 = false;
		if(c[i][j] != b[N-j-1][i]) d270 = false;
	}
	return d90||d180||d270;
}


bool NoChange() {	
	for(int i = 0; i < N; ++i)
	for(int j = 0; j < N; ++j)
		if(a[i][j] != b[i][j])
			return false;
	return true;
}

int Transformation() {
	if(DegreeRotation90()) return 1;	
	if(DegreeRotation180()) return 2;
	if(DegreeRotation270()) return 3;
	if(Reflection()) return 4;
	if(Combination()) return 5;
	if(NoChange()) return 6;	
	return 7;
}


int main() {
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);
	scanf("%d",&N);
	for(int i = 0; i < N; ++i)
		scanf("%s",&a[i]);
	for(int i = 0; i < N; ++i)
		scanf("%s",&b[i]);	
	printf("%d\n",Transformation());
	return 0;
}
