#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int a, b ,n;
vector < int >  sea;
vector < pair < int , int > > lista[15];
bool visited [15];
int search(int x)
{
	for(int i=0;i<sea.size();i++)
		if(sea[i]==x)
			return i;
	return -1;		
}
bool dfs(int x, int w)
{
	visited[x]=true;
	if(binary_search(sea.begin(), sea.end(), x))
	{
		//cout<<x<<"  sea"<<endl;
		return true;
	}
	bool ans=false;	
	for(int i=0;i<lista[x].size() && !ans;i++)
	{
		if(!visited[lista[x][i].first] && lista[x][i].second < w)
			return false;
		else if(!visited[lista[x][i].first] && lista[x][i].second >= w)
			ans=ans || dfs(lista[x][i].first,w);
	}
	//cout<<x<<": "<<(ans?"tru":"fas")<<endl;
	return ans;
}
int main()
{
	while(cin>>n>>a>>b)
	{
		if(n<=0 && a<=0 && b<=0) break;
		sea.clear();
		for(int i=0;i<n;i++)
			lista[i].clear();
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				int aux;
				scanf("%d", &aux);
				if(aux>0)
				lista[i].push_back(make_pair(j  ,aux));
				//lista[j].push_back(make_pair(i  ,aux));
			}
		for(int i=0;i<a;i++)
		{
			int aux;
			scanf("%d", &aux);
			sea.push_back(aux);
		}
		sort(sea.begin(), sea.end());	
		bool flag =true;
		for(int i=0;i<b ;i++)
		{
			int city, w;
			cin>>city>>w;
			if(!binary_search(sea.begin(), sea.end(), city))
			{
				memset(visited, false, sizeof(visited));
				if (!dfs(city, w))
					flag=false;
			}
		}
		if(flag )
			cout<<"SAFE"<<endl;
		else	
			cout<<"FLOOD!!!"<<endl;
	}
}

