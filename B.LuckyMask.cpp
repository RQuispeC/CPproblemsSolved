#include<bits/stdc++.h>
using namespace std;
bool mayor (string a,string b)
{
	if(b.size() != a.size() )
		return a.size() > b.size();
	for(int i=0;i<a.size();i++)	
	{
		if(b[i]>a[i])
			return 0;
		else if (b[i]<a[i])
			return 1;
	}
	return 0;		
}
bool verificar1(string a , string b)
{
	for(int i=0;i<a.size();i++)
		if(a[i]>b[i])
			return 0;
	return 1;
}
string mask(int x)
{
	string ans="";
	while(x>0)
	{
		int last=x%10;
		x/=10;
		if(last==7 || last==4)
			ans= (char)(last+'0') + ans;
	}
	//cout<<ans<<endl;
	return ans;
}
int main()
{
	string a,b;
	cin>>a>>b;
	string ans;
	if(mayor(b, a))
		cout<<b<<endl;
	else
	{
		if(a == b )
		{
			string ans=b;
			bool f=0;
			for(int i=b.size()-1;i>=0;i--)
			{
				if(b[i]==4)
				{
					f=1;
					ans[i]=7;
					break;
				}
			}
			if(f)
				cout<<ans<<endl;
			else
				cout<<"1"+ans<<endl;	
		}
		else
		{
			int a1=atoi(a.c_str()), aux;
			for(int i=1;i<1e5+500;i++)
			{
				aux=a1+i;
				string Mask=mask(aux);
				//cout<<aux<<" : "<<Mask<<endl;
				if(Mask==b)
					break;
			}
			cout<<aux<<endl;
		}	
	}	
}

