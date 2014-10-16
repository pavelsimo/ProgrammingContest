
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
long tree[302];
bool flag[302];
int main()
{
long N,I,J,m,s,test,S,D,b;
char ch;
/*
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
*/
while(scanf("%ld",&N)==1){

vector<long> v[302];

for(I=1;I<=N;I++){
scanf("%ld",&m);
while(scanf("%ld",&s)==1){
if(s<0)
s=-s;
v[m].push_back(s);
if(getchar()=='\n')
break;
}

}

printf("-----\n");
scanf("%ld",&test);
for(I=1;I<=test;I++)
{
queue<long> Q;
vector<long> path;

scanf("%ld %ld",&S,&D);
Q.push(S);
tree[S]=-1;
while( !Q.empty() )
{
b=Q.front();
Q.pop();
flag[b]=1;
if(b==D)
{
tree[D]=b;
break;
}
for(J=0;J<v[b].size();J++)
{
if(flag[v[b][J]]==0)
{
if(v[b][J]==D)
{
tree[D]=b;
flag[D]=1;
break;
}
flag[v[b][J]]=1;
Q.push(v[b][J]);
tree[v[b][J]]=b;
}
}
}

if(flag[D]==1){

path.push_back(D);

while( tree[D]!=-1 ){
D=tree[D];
path.push_back(D);
}

for(J=path.size()-1;J>=1;J--)
printf("%ld ",path[J]);
printf("%ld\n",path[0]);

}
else
printf("connection impossible\n");

for(J=0;J<=N;J++){
flag[J]=0;
tree[J]=0;
}


}


}



return 0;
}