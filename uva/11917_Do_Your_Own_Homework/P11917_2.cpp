#include<stdio.h>
#include<string.h>
//#include<cmath>
//#define MAX 1000000
int main()
{
    //freopen("F:\\in.txt","r",stdin);
    char a[100][100],b[1][100];
    int i=0,j,t,d,f,m=1,g,h,w[100];
    scanf("%d",&t);
    while(t--) {
        f=1;
        h=0;
        printf("Case %d: ",m);
        scanf("%d",&j);
        for(i=0; i < j; ++i) {
            scanf("%s%d",a[i],&w[i]);
            h=h+w[i];
        }
        scanf("%d",&d);
        scanf("%s",b[0]);
      for(i=0;i<j;i++)
      if(!(strcmp(a[i],b[0]))) {
         f=0;
         break;
      }
        g=j*d;
        if(f)
                {
                        printf("Do your own homework!\n");
                        m++;
                        continue;
                }
        else
        {
            if(h<=g)
            printf("Yesss\n");
            else
            {
                if(h<=g+5)
                printf("Late\n");
                else
                printf("Do your own homework!\n");
 
            }
 
        }
        m++;
    }
        return 0;
}
