#include<stdio.h>
long i,casos,n,m,dos[65],tres[65],a0,b0,c0,mod=10007;
long long d,t,sgn,A,B,C,s;
int main(){ 
   dos[1]=2;
   tres[1]=3;
   for (i=2;i<65;i++){
      dos[i]=(dos[i-1]*dos[i-1]) % mod;
      tres[i]=(tres[i-1]*tres[i-1]) % mod;
   }
      scanf("%ld%ld%ld%ld",&n,&a0,&b0,&c0);
      A=2*a0-b0-c0;
      B=-a0+2*b0-c0;
      C=-a0-b0+2*c0;
      s=(a0+b0+c0)%mod;            
      if (n>0){
		 m=n;
         d=1;
         t=1;
         i=0;
         while (m>0){
             i++;
             if (m%2==1)
                d=(d*dos[i]) % mod;
             m/=2;
		 }
         m=n-1;
         i=0;
         while (m>0){
             i++;
             if (m%2==1)
                t=(t*tres[i]) % mod;
             m/=2;
		 }
         if (n%2==0)
            sgn=1;
         else
            sgn=-1;   
		 A=((t*(d*s+sgn*A)) % mod+mod)%mod;		
		 B=((t*(d*s+sgn*B)) % mod+mod)%mod;
		 C=((t*(d*s+sgn*C)) % mod+mod)%mod;
         printf("%lld %lld %lld\n",A,B,C);
	  }
	  else
         printf("%ld %ld %ld\n",a0,b0,c0);
} 