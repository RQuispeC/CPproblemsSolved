#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAX 30002
using namespace std;
int parents[MAX];
int find(int i)
{
	if(parents[i]==i)
		return i;
	else
		return parents[i]=find(parents[i]);
}
void Union(int x, int y)
{
	int rootX=find(x);
	int rootY=find(y);
	parents[rootX]=rootY;
}
int main()
{
	int n, m, tested;
	scanf("%d",&tested);
	while(tested--)
	{
		scanf("%d %d", &n, &m);
		for(int i=1;i<=n;i++)
			parents[i]=i;
		for(int i=0;i<m;i++)
		{
			int x, y;
			scanf("%d %d", &x , &y);
			Union(x, y);
		}
		int max=0;
		for(int i=1;i<=n;i++)
		{
			int cont=0;
			for(int j=1;j<=n;j++)
				if(find(parents[i])==find(parents[j]))
					cont++;
			if(cont>max)
				max=cont;
		}
		cout<<max<<endl;
	}
	return 0;
}

