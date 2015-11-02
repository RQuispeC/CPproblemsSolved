#include<bits/stdc++.h>
using namespace std;
struct medal
{
	int a, b, c;
	medal(){}
	medal(int A, int B, int C)
	{
		a=A, b=B, c=C;
	}
};
typedef pair < string , medal > pais;
pais a[105];
int main()
{
	int c;
	while(cin>>c)
	{
		if(c<=0) break;
		int pos=0;
		for(int i=0;i<c;i++)
		{
			int x,y,z;
			cin>>a[i].first>>x>>y>>z;
			a[i].second=medal(x,y,z);
			if(a[i].first=="Canada")
				pos=i;
		}	
		bool f=1;
		for(int i=0;i<c;i++)
		{
			if(i==pos) continue;
			if(a[i].second.a>=a[pos].second.a && a[i].second.b>=a[pos].second.b && a[i].second.c>=a[pos].second.c)
				f=0;
		}	
		if(f)
			cout<<"Canada wins!"<<endl;
		else
			cout<<"Canada cannot win."<<endl;	
	}
}

