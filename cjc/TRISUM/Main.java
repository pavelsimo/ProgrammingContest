import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {
	static int i,casos,n,m,a0,b0,c0,mod=10007;
	static int dos[] = new int[65],tres[] = new int[65];
	static long d,t,sgn,A,B,C,s;
	public static void main(String args[]) throws Exception{
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		
		
		   dos[1]=2;
		   tres[1]=3;
		   for (i=2;i<65;i++){
		      dos[i]=(dos[i-1]*dos[i-1]) % mod;
		      tres[i]=(tres[i-1]*tres[i-1]) % mod;
		   }
		   
		   StringTokenizer str = new StringTokenizer(r.readLine());
		   n = Integer.parseInt(str.nextToken());
		   a0 = Integer.parseInt(str.nextToken());
		   b0 = Integer.parseInt(str.nextToken());
		   c0 = Integer.parseInt(str.nextToken());
		   
		   
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
		       
		       System.out.println(A+" "+B+" "+C);
			  }
			  else
				  System.out.println(a0+" "+b0+" "+c0);
		
	}
}
