#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n==0)
	{
		cout<<"10"<<endl;
	}
	else
	{
		string ans="";
		while(true)
		{
			if(n<=9)
			{
				ans+=char(n+'0');
				break;
			}	
			for(int i=9;i>=2;i--)
			{
				//cout<<n<<" : "<<i<<endl;
				if(n%i==0)
				{
					//cout<<"asa"<<endl;
					ans+=char(i+'0');
					n=n/i;
					i=10;
					if(n<10)
						break;
				}
			}
			if(n>=11)
			{
				ans="";
				break;
			}
			
		}
		if(ans=="")
			cout<<-1<<endl;
		else
		{
			char a[500];
			for(int i=0;i<ans.size();i++)
				a[i]=ans[i];
			sort(a, a+ans.size());
			string aux="";	
			for(int i=0;i<ans.size();i++)
				aux+=a[i];
			cout<<aux<<endl;
		}
	}	
}
