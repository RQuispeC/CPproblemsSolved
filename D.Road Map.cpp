#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX 50010
using namespace std;
int parents[MAX];
int n, r1,r2;
vector < int > dfs;
void DFS()
{
	int i=r2;
	while(true)
	{
		if(parents[i]==i) break;
		//cout<<i<<endl;
		dfs.push_back(i);
		i=parents[i];
	}
	dfs.push_back(i);
}
int main()
{
	cin>>n>>r1>>r2;
	r1--;r2--;
	for(int i=0;i<n;i++)
	{
		if(i!=r1)
		{
			int aux;
			cin>>aux;
			parents[i]=aux-1;
		}	
	}
	parents[r1]=r1;
	dfs.clear();
	DFS();
	parents[r2]=r2;
	for(int i=1;i<dfs.size();i++)
	{
		parents[dfs[i]]=dfs[i-1];
	}
	for(int i=0;i<n;i++)
	{
		if(i!=r2)
		{
			cout<<parents[i]+1;
			if(i+1<n) cout<<" ";
		}
	}
	cout<<endl;
}


