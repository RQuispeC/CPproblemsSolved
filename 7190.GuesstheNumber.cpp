#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
#define MAX 22
using namespace std;
int main()
{
	bool primos[MAX];
	memset(primos, true, sizeof primos);
	primos[0]=false;
	for(int i=2;i*i<=MAX;i++)
		for(int j=2*i;j<MAX;j=j+i)
			primos[j]=false;
	long long fact[MAX];
	fact[0]=1;
	for(int i=1;i<MAX;i++)
		fact[i]=fact[i-1]*i;	
	string num;
	while(cin>>num)
	{
		if(num=="*") break;
		vector < int > a;//numeros multiplos
		vector < int > b;//numeros no multiplos
		a.clear();
		b.clear();
		for(int i=0;i<num.size();i++)
			if(num[i]=='Y') a.push_back(i+1);
			else b.push_back(i+1);	
		long long ans=fact[num.size()];
		for(int i=0;i<b.size();i++)
			ans/=b[i];
		for(int i=a.size()-1;i>=0;i--)
		{
			if(!primos[a[i]])
			{
				//factorizar
				int n=a[i];
				int facto [ 50 ];
				int numFact=0;
				for(int i=2;i*i<=n;i++)
				{
					while(n%i==0)
					{
						n=n/i;
						facto[numFact++]=i;
					}
				}
				if(n>1)	facto[numFact++]=n;
				//decrementar ans
				for(int i=0;i<numFact;i++)
				{
					long long aux=ans/facto[i];
					bool flag=true;
					for(int i=0;i<a.size() && flag;i++)
						if(aux % a[i] != 0 ) flag=false;
					if(flag) ans=aux;	 
				}
			}
		}
		bool flag=true;
		for(int i=0;i<b.size() && flag;i++)
			if(ans%b[i]==0) flag=false;	
		if(flag)
			cout<<ans<<endl;			
		else
			cout<<-1<<endl;
	}
}

