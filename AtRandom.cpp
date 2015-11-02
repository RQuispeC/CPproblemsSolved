#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		bool f=1;
		int a,b;
		char c,d;
		cin>>a>>c;
		for(int i=1;i<n;i++)
		{
			cin>>b>>d;
			//cout<<a<<" "<<c<<" - "<<b<<" "<<d<<endl;
			if(a==b || c==d)
				f=0;
			a=b;
			c=d;
		}
		if(f)
			cout<<"B"<<endl;
		else
			cout<<"M"<<endl;
	}
}

