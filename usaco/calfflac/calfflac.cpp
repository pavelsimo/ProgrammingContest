/*
ID: 0000
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio> 
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

char buf[90], s[25010];
bool space[25010];
int n, maxi=0, maxj=0, best=0;

void ispal(char *a, int l, int r, int d) {
	int c = 0;
	while(l >= 0 && r < n) {
		if(!isalpha(a[l])) {
			l--;
			continue;
		}
		if(!isalpha(a[r])) {
			r++;
			continue;
		}
		if(tolower(a[l])!=tolower(a[r])) break;
		l--;
		r++;
		c+=2;
	}
	c+=d;
	if(c > best) {
		l=l+1;
		r=r-1;
		while(!isalpha(a[l]))l++;
		while(!isalpha(a[r]))r--;
		maxi = l; maxj = r;
		best = c;
	}
}

int main() {
	FILE *fin, *fout;
	fin = fopen("calfflac.in", "r");
	fout = fopen("calfflac.out", "w");
	int sz, s_sz;
	while(fgets(buf,90,fin)) {
		s_sz=strlen(s);
		sz = strlen(buf);
		if(buf[sz-1]=='\n') {
			buf[sz-1]=0;
			space[s_sz-1+sz]=true;
		}
		strcat(s,buf);
	}
	n=strlen(s);
	for(int i = 0; i < n-1; ++i) {
		if(isalpha(s[i]) && isalpha(s[i+1]))
			ispal(s,i,i+1,0);
		if(i+2 < n && isalpha(s[i+1]))
			ispal(s,i,i+2,1);
	}
	fprintf(fout,"%d\n",best);
	for(int i = maxi; i <= maxj; ++i) {
		if(space[i]) fprintf(fout,"\n");
		fprintf(fout,"%c",s[i]);
	}
	fprintf(fout,"\n");
	exit(0);
}
