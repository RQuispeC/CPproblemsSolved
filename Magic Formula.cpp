#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d,l;
	while(cin>>a>>b>>c>>d>>l )
	{
		if(a==0 && b==0 && c==0 && d==0 && l==0) break;
		int divisors=0;
		for(int i=0;i<=l;i++)
		{
			int res=a*i*i+b*i+c;
			if(res!=0)
				if(res%d==0)
					divisors++;	
		}
		cout<<divisors<<endl;
	}		
	return 0;
}

