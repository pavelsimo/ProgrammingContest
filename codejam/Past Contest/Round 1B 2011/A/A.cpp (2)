#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

int nWP[200] , dWP[200];
double nOPW[200], dOPW[200];
double OOWP[200];
string MAT[200];

double RPI(double WP, double OPW,double OOPW2)
{
	return 0.25 * WP + 0.50 * OPW + 0.25 * OOPW2;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int TC;
	cin>>TC;
	for(int tc = 1 ; tc<=TC ; ++tc)
	{
		printf("Case #%d:\n",tc);
		int N;
		cin>>N;
		for(int i = 0; i < N; ++i)
		{
			nWP[i] = 0; dWP[i] = 0, nOPW[i]=0, dOPW[i] = 0, OOWP[i] =0;
		}
		for(int i = 0;i < N; ++i)
		{
			cin>>MAT[i];
			for(int j = 0; j < N; ++j){
				if(MAT[i][j]=='1')nWP[i]++;
				if(MAT[i][j]!='.')dWP[i]++;
			}
		}
		for(int i = 0; i < N; ++i)
		{
			for(int j = 0; j < N; ++j)
			{
				if(MAT[i][j]!='.')dOPW[i] += 1;
				if(MAT[i][j]=='1')
					nOPW[i] += double(nWP[j])/double(dWP[j]-1);
				else if(MAT[i][j]=='0')
					nOPW[i] += double(nWP[j]-1)/double(dWP[j]-1);
			}
			nOPW[i] /= dOPW[i];
			//cout<<"  "<<nOPW[i]<<endl;
		}
		for(int i = 0; i < N; ++i)
		{
		double den = 0;
			for(int j = 0; j < N; ++j)
				if(j!=i && MAT[i][j]!='.'){
					OOWP[i] += nOPW[j];
					den += 1;
				}
			OOWP[i] /= den;
			//cout<<i<<"  --> "<<OOWP[i]<<endl;
		}
		for(int i = 0; i < N; ++i)
			printf("%0.8f\n",RPI(double(nWP[i])/double(dWP[i]),nOPW[i],OOWP[i]));
	}
	return 0;
}