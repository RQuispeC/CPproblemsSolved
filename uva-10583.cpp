#include<iostream>
#include<cstring>
#define MAX 50002
using namespace std;
int parents[MAX];
int find(int x)
{
	if(parents[x]==x) return x;
	else return parents[x]=find(parents[x]);
}
void Union(int x , int y)
{
	int rX=find(x);
	int rY=find(y);
	parents[rX]=rY;
}
int main()
{
	int pares,n;
	bool visited [MAX];
	int t=0;
	while(cin>>n>>pares && n!=0 && pares!=0)
	{
		memset(visited, false,sizeof(visited));
		for(int i=0;i<n;i++)
			parents[i]=i;
		for(int i=0;i<pares;i++)
		{
			int k,l;
			cin>>k>>l;
			Union(k-1,l-1);
		}
		int ans=0;
		for(int i=0;i<n;i++)
			if(parents[i]==i) ans++;	
		cout<<"Case "<<++t<<": "<<ans<<endl;		
	}		
	return 0;
}
