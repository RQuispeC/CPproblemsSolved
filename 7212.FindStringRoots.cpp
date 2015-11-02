#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		if(s=="*") break;
		int n=s.size();
		int ans=n+12;
		for(int i=1;i*i<=n;i++)
		{
			if(n%i==0)
			{
				string aux="";
				for(int j=0;j<i;j++)
				{
					aux+=s[j];
				}
				bool flag=true;
				for(int j=0;j<n && flag;j+=i)
				{
					string part=s.substr(j,i);
					if(part!=aux) flag=false;
				}
				if(flag) ans=min(ans, i);
				
				aux="";
				for(int j=0;j<n/i;j++)
				{
					aux+=s[j];
				}
				int temp=n/i;				
				flag=true;
				for(int j=0;j<n && flag;j+=temp)
				{
					string part=s.substr(j,temp);
					if(part!=aux) flag=false;
				}
				if(flag) ans=min(ans, temp);
			}
		}
		ans=n/ans;
		cout<<ans<<endl;
	}
}


