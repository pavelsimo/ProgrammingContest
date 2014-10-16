/* Source Code */
#include <stdio.h>
#define MAXsize 1000000
#define MAXN 1001
typedef struct Sumsub
{
        int s,x,y;
};
Sumsub plus[MAXsize]={0};
int n,sub[MAXN]={0},m=0;
void Qsort(int *a,int x,int y)
{
     if(x>=y) return;
     int p=x,q=y,F=a[p];
     while(p<q)
     {
        while(p<q && a[q]>F)
           q--;
        if(p<q) a[p++]=a[q];
        while(p<q && a[p]<F)
           p++;
        if(p<q) a[q--]=a[p];
     }
     a[p]=F;
     Qsort(a,x,p-1);
     Qsort(a,p+1,y);
}
void Quicks(Sumsub *a,int x,int y)
{
     if(x>=y) return;
     int p=x,q=y;
     Sumsub F=a[p];
     while(p<q)
     {
        while(p<q && a[q].s>F.s)
           q--;
        if(p<q) a[p++]=a[q];
        while(p<q && a[p].s<F.s)
           p++;
        if(p<q) a[q--]=a[p];
     }
     a[p]=F;
     Quicks(a,x,p-1);
     Quicks(a,p+1,y);
}
bool diff(int a,int b,int c,int d)
{
     if(a==c||a==d) return false;
     if(b==c||b==d) return false;
     return true;
}
bool Found(int ans,int i,int j)
{
     int l=0,r=m-1,mid,k;
     while(l<=r)
     {
        mid=(l+r)>>1;
        if(ans==plus[mid].s)
        {
           if(diff(i,j,plus[mid].x,plus[mid].y))
           return true;
           for(int k=mid-1;k>=0;k--)
              if(ans==plus[k].s)
              {
                 if(diff(i,j,plus[k].x,plus[k].y)) return true;
              }else break;
           for(int k=mid+1;k<m;k++)
              if(ans==plus[k].s)
              {
                 if(diff(i,j,plus[k].x,plus[k].y)) return true;
              }else break;
        }
        if(ans>plus[mid].s) l=mid+1;
        else                r=mid-1;
     }
     return false;
}
void Maxsub()
{
     for(int i=n-1;i>0;i--)
        for(int j=0;j<i;j++)
        {
           if(Found(sub[i]-sub[j],i,j))
           {
              printf("%d\n",sub[i]);
              return;
           }
        }
     printf("no solution\n");
}
int main()
{
    while(scanf("%d",&n)==1)
    {
       if(!n) break;
       for(int i=0;i<n;i++)
          scanf("%d",&sub[i]);
       Qsort(sub,0,n-1);
       m=0;
       for(int i=0;i<n-1;i++)
          for(int j=i+1;j<n;j++)
          {
             plus[m].s=sub[i]+sub[j];
             plus[m].x=i;
             plus[m++].y=j;
          }
       Quicks(plus,0,m-1);
       Maxsub();
    }
    return 0;
}
