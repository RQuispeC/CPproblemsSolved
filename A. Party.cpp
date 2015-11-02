#include<iostream>
#include<cstring>
#include<cmath>
#define MAX 2014
using namespace std;
//altura del arbol
int parents[MAX];
int hight[MAX];
int n;
int find(int x)
{
	if(parents[x]==x) 
		return 0;
	if(hight[x]!=-1)
		return hight[x];
	else
		return hight[x]=1+find(parents[x]);
}
int main()
{
	cin>>n;
	memset(hight, -1, sizeof hight);
	for(int i=0;i<n;i++)
		parents[i]=i;	
	for(int i=0;i<n;i++)
	{
		int aux;
		cin>>aux;
		if(aux>0)
			parents[i]=aux-1;
	}		
	int ans=0;
	for(int i=0;i<n;i++)
		ans=max(ans,find(i));		
	cout<<ans+1<<endl;	
}
