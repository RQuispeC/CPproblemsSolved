#include<iostream>
using namespace std;
int longsec(unsigned int  n)
{
	int leng=0;
	do
	{
		if(n%2!=0)//n impar
			n=n*3+1;
		else
			n=n/2;
		leng++;
	}while(n!=1);
	return leng;

}
int main()
{
	int a, b;
	cin>>a>>b;
	while(a!=0 && b!=0)
	{
		int mayor, menor; 
		if(a>b)
		{
			mayor=a;
			menor=b;
		}
		else
		{
			mayor=b;
			menor=a;
		}
		int maxn=0, max=0;
		for(int i=menor;i<=mayor;i++)
		{
			int p=longsec(i);
			if(p>max)
			{
				max=p;
				maxn=i;
			}
		}
		cout<<"Between "<<menor<<" and "<<mayor<<", "<<maxn<<" generates the longest sequence of "<<max<<" values."<<endl;
		cin>>a>>b;
	}
	return 0;
}
//http://www.zator.com/Cpp/E2_2_4.htm
