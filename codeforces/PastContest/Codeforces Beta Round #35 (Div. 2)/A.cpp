#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n, a[4], x, y;
int main(int argc, char *argv[]) { 
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   scanf("%d",&n);
   memset(a, 0, sizeof(a));
   a[n] = 1;
   while(2 == scanf("%d%d", &x,&y))
      swap(a[x], a[y]);
   for(int i = 1; i <= 3; ++i)
      if(a[i]) printf("%d\n",i);
   return 0;
}

