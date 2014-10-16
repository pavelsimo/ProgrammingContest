/*
ID: 0000
PROG: milk
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

struct Farmer {
	int price;
	int qty;
	bool operator<(const Farmer &T) const {
		if(T.price!=price) return price < T.price;
		if(T.qty!=qty) return qty > T.qty;
		return false;
	}
};

int N, M, ans;
const int maxn = 5002;
Farmer a[maxn];

int main() {
	freopen("milk.in", "r", stdin);
	freopen("milk.out", "w", stdout);
	scanf("%d%d",&N,&M);
	for(int i = 0; i < M; ++i)
		scanf("%d%d",&a[i].price,&a[i].qty);	
	sort(a,a+M);
	ans=0;
	for(int i = 0; i < M; ++i) {
		if(N >= a[i].qty) {
			ans+=a[i].price*a[i].qty;
			N-=a[i].qty;
		} else {
			ans+=N*a[i].price;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
