import java.util.Scanner;
import java.math.BigInteger;
public class BInnaDimaAndSong
{
	public static void main (String args[]) 
	{
	  Scanner r=new Scanner(System.in);	
	  int n=r.nextInt();
	  int [] a= new int[n];
	  int [] b= new int[n];
	  for(int i=0;i<n;i++)
	  	a[i]=r.nextInt();
	  for(int i=0;i<n;i++)
	  	b[i]=r.nextInt();	
	  BigInteger ans=new BigInteger("0");
	  BigInteger neg=new BigInteger("-1");
	  for(int i=0;i<n;i++)
	  {
	  		if(2*a[i]>=b[i])
	  		{
	  			int aux1=b[i]/2;
	  			int aux2=b[i]-aux1;
	  			if(aux1>0 && aux2>0)
	  			{
		  			BigInteger x=BigInteger.valueOf(aux1);
		  			BigInteger y=BigInteger.valueOf(aux2);
		  			//System.out.println(x+"  :  "+ y + "  = "+ x.multiply(y));
		  			ans=ans.add(x.multiply(y));
				}
				else	
					ans=ans.add(neg);  		
	  		}
	  		else
	  		{
	  			ans=ans.add(neg);
			}	  
	  }
	  System.out.println(ans);
	}
}	
