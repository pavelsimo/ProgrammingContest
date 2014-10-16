//============================================================================
// Name        : code.cpp
// Author      : Vlade087
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<ctype.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<string.h>
#include<algorithm>
#include <complex>
#define maxn 100005
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define mset memset
using namespace std;
int test,n,m,c1,t1,c2,t2;
double dp[25][25];
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		memset( dp, 0, sizeof dp );
		dp[0][0] = 1.0;

		double yes = 1.0 / m;
		double no = 1 - yes;

		for( int i = 0; i < n; ++i )
			for( int j = 0; j <= i; ++j ) {
				dp[i+1][j] += dp[i][j] * no;
				dp[i+1][j+1] += dp[i][j] * yes;
			}

		scanf("%d%d%d%d",&c1,&t1,&c2,&t2);
		double dj = 0;
		for( int i = c1; i <= n; ++i )
				dj += dp[n][i];
		double wt = 0;
		for( int i = c2; i <= n; ++i )
			wt += dp[n][i];
		dj = 1 - dj;
		double res = 0.5*(wt + dj);
		printf("%.2lf\n",res);
	}
  return 0;
}

