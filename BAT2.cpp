#include<bits/stdc++.h>
#define MAX 105
using namespace std;
typedef vector < int > vi;
vector < vi > lista1, lista2, l1 , l2;
int n, memo[MAX][MAX], a[MAX], b[MAX], m1[MAX], m2[MAX];
int dp(int u, int v) // u --> lista1, v --> lista2 
{
	if(memo[u][v] != -1 ) return memo[u][v];
	int ans=2;
	vi  ve;
	bool f=1;
	//if(u < v )
	{
		for(int i=0;i<lista1[u].size();i++)
		{
			int adj=lista1[u][i];
			ans=max(ans, 1 + dp(adj, v));
			ve.push_back(adj);
			ve.push_back(v);
			ve.push_back(memo[adj][v]);
		}
	}
	//else 
	{	
		f=0;
		for(int i=0;i<lista2[v].size();i++)
		{
			int adj=lista2[v][i];
			ans=max(ans, 1 + dp(u, adj));
			ve.push_back(u);
			ve.push_back(adj);
			ve.push_back(memo[u][adj]);
		}
	}
	/*if(f && lista2[v].size())
	{
		for(int i=0;i<lista2[v].size();i++)
		{
			int adj=lista2[v][i];
			ans=max(ans, 1 + dp(u, adj));
			ve.push_back(u);
			ve.push_back(adj);
			ve.push_back(memo[u][adj]);
		}
	}
	if(!f && lista1[u].size())
	{
		for(int i=0;i<lista1[u].size();i++)
		{
			int adj=lista1[u][i];
			ans=max(ans, 1 + dp(adj, v));
			ve.push_back(adj);
			ve.push_back(v);
			ve.push_back(memo[adj][v]);
		}
	}*/
	cout<< u +1<<" : "<<v+1<<endl;	
	for(int i=0;i<ve.size();i+=3)
		cout<<"--> "<<ve[i]+1<<" . "<<ve[i+1]+1<<" : "<<ve[i+2]<<endl;
	if(u==v) ans--;
	//cout<<u+1<<" : "<<v+1<<" -- >"<<ans<<endl;
	return memo[u][v]=ans;
}
int f1(int u)
{
	if(m1[u] != -1) return m1[u];
	int ans=0;
	for(int i=0;i<l1[u].size();i++)
	{
		int v=l1[u][i];
		ans=max(ans, 1 + f1(v));
	}
	for(int i=0;i<l1[u].size();i++)
	{
		int v=l1[u][i];
		if(f1(v) == ans -1 )
			lista1[u].push_back(v);
	}
	return m1[u]=ans;
}
int f2(int u)
{
	if(m2[u] != -1) return m2[u];
	int ans=0;
	for(int i=0;i<l2[u].size();i++)
	{
		int v=l2[u][i];
		ans=max(ans, 1 + f2(v));
	}
	for(int i=0;i<l2[u].size();i++)
	{
		int v=l2[u][i];
		if(f2(v) == ans -1 )
			lista2[u].push_back(v);
	}
	return m2[u]=ans;
}
void built()
{
	lista1.assign(MAX, vi());
	lista2.assign(MAX, vi());
	l1.assign(MAX, vi());
	l2.assign(MAX, vi());
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(a[i] < a[j])
				l1[a[i]].push_back(a[j]);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(b[i] < b[j])
				l2[b[i]].push_back(b[j]);
}
int main()
{
	int tested;
	scanf("%d", &tested);
	while(tested--)
	{
		scanf("%d", &n);
		for(int i=0;i<n;i++)
		{
			scanf("%d", &a[i]);
			a[i]--;
			b[i]=a[i];
		}	
		reverse(a, a+n);
		built();
		memset(m1, -1, sizeof m1);
		memset(m2, -1, sizeof m2);
		for(int i=0;i<n;i++)
		{
			f1(a[i]); f2(b[i]);
		}
		/*for(int i=0;i<n;i++)
		{
			cout<<a[i]+1<<" : "<<f1(a[i])<<endl;
		
		}
				for(int i=0;i<n;i++)
		{
		
			cout<<a[i]+1<<" * "<<f2(a[i])<<endl;
		}*/
		/*
		for(int i=0;i<n;i++)
		{
			cout<<i+1<<" : "<<endl;
			for(int j=0;j<lista1[i].size();j++)
				cout<<lista1[i][j]+1<<"  ";
			cout<<endl;	
		}
		cout<<"--------"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<i+1<<" : "<<endl;
			for(int j=0;j<lista2[i].size();j++)
				cout<<lista2[i][j]+1<<"  ";
			cout<<endl;	
		}*/
		memset(memo, -1, sizeof memo);
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				ans=max(ans, dp(a[i], b[j]));
				cout<<a[i]+1<<" : "<<b[j]+1<<" --> "<<dp(a[i], b[j])<<endl;
			}	
		cout<<ans<<endl	;
	}
}

