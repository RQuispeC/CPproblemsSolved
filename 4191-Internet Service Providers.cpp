#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,c;
	while(cin>>n>>c)
	{
		if(n==0)
			cout<<0<<endl;
		else
		{
			int maxi=c/n;
			if(maxi%2==0)
				cout<<maxi/2<<endl;
			else
			{
				maxi=maxi/2;
				int ansMin = maxi*(c-n*maxi);
				maxi++;
				int ansMax = maxi*(c-n*maxi);
				if(ansMin >= ansMax)
					cout<<maxi-1<<endl;
				else
					cout<<maxi<<endl;	
			}	
		}	
	}
}

