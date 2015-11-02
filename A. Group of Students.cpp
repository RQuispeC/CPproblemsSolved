#include <iostream>
#include <cstring>
#define MAX 105
using namespace std;
int a[MAX];
int main()
{
	int m;
	cin>>m;
	int total=0;
	for(int i=1;i<=m;i++)
	{
		int aux;
		cin>>aux;
		a[i]=aux;
		total+=aux;
	}
	int x,y;
	cin>>x>>y;
	if(x>total) 
	{
		cout<<0<<endl;
		return 0;
	}
	int beginers=0;
	int i=1;
	while(true)
	{
		beginers+=a[i];
		i++;
		if((beginers>=x && beginers<=y) || i>m)
			break;
	}
	int pro=total-beginers;
	if(pro>=x && pro<=y)
		cout<<i<<endl;
	else
	{
		bool flag=true;
		while(true)
		{
			pro-=a[i];
			beginers+=a[i];
			i++;
			if(pro>=x && pro<=y) 
				if(beginers>=x && beginers<=y)
					break;
				else
				{
					flag=false;
					break;
				}
			if(beginers>=total || i>m)
			{
				flag=false;
				break;
			}	
		}
		if(flag)
			cout<<i<<endl;
		else
			cout<<0<<endl;
	}	
}
