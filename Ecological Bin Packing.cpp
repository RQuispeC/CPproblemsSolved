#include<bits/stdc++.h>
#define INF 1e9
using namespace std;
int main()
{
	string ans [6]={"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
	int a[9];
	while(cin>>a[0])
	{
		for(int i=1;i<9;i++)
			cin>>a[i];
		int tot=INF, ind=-1;
		for(int i=0;i<6;i++)
		{
			if(i==0)
			{
				int cost=a[3]+a[6]+a[2]+a[8]+a[1]+a[4];
				if(cost<tot)
				{
					tot=cost;
					ind=i;
				}
			}
			else if(i==1)
			{
				int cost=a[3]+a[6]+a[1]+a[7]+a[2]+a[5];
				if(cost<tot)
				{
					tot=cost;
					ind=i;
				}			
			}
			else if(i==2)
			{
				int cost=a[5]+a[8]+a[0]+a[6]+a[1]+a[4];
				if(cost<tot)
				{
					tot=cost;
					ind=i;
				}			
			}
			else if(i==3)
			{
				int cost=a[5]+a[8]+a[1]+a[7]+a[0]+a[3];
				if(cost<tot)
				{
					tot=cost;
					ind=i;
				}			
			}
			else if(i==4)
			{
				int cost=a[4]+a[7]+a[0]+a[6]+a[2]+a[5];
				if(cost<tot)
				{
					tot=cost;
					ind=i;
				}			
			}
			else //if(i==5)
			{
				int cost=a[4]+a[7]+a[2]+a[8]+a[0]+a[3];
				if(cost<tot)
				{
					tot=cost;
					ind=i;
				}			
			}			
		}
		cout<<ans[ind]<<" "<<tot<<endl;
	}
}


