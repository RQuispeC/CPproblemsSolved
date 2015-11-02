#include<bits/stdc++.h>
#define MAX (int)1e5 + 5
using namespace std;
typedef vector < int > vi;
queue < int > q;
vector < vector < int > > lista;
int n, m, k, keyOpen[MAX], newKey;
bool isDoor[MAX], isKey[MAX],haveKey[MAX], vis[MAX];
int dfs(int u)
{
	if(isKey[u])
	{
		haveKey[u]=1;
		newKey++;
	}
	if(isDoor[u])
	{
		if(haveKey[keyOpen[u]])//tenemos la llave
		{
			vis[u]=1;
			for(int i=0;i<lista[u].size();i++)
			{
				int v=lista[u][i];
				if(!vis[v])
					dfs(v);
			}		
		}
		else
		{
			q.push(u);
			return 0;
		}
	}
	else
	{
		vis[u]=1;
		for(int i=0;i<lista[u].size();i++)
		{
			int v=lista[u][i];
			if(!vis[v])
				dfs(v);
		}
	}
	return 1;
}
void ini()
{
	lista.assign(n, vi());
	for(int i=0;i<n;i++)
	{
		isDoor[i]=0;
		isKey[i]=0;
		haveKey[i]=0;
		keyOpen[i]=-1;
		vis[i]=0;	
	}
	queue < int > emptyQ;
	swap(q,emptyQ);
}
int main()
{
	while(scanf("%d %d %d", &n, &k, &m))
	{
		if(n==-1 && k==-1 && m==-1) break;
		ini();
		for(int i=0;i<k;i++)
		{
			int a,b;
			scanf("%d %d", &a, &b);
			a--,b--;
			isDoor[b]=1;
			isKey[a]=1;
			keyOpen[b]=a;
		}
		for(int i=0;i<m;i++)
		{
			int u,v;
			scanf("%d %d", &u, &v);
			u--, v--;
			lista[u].push_back(v);
			lista[v].push_back(u);
		}
		//cout<<"pas"<<endl;
		q.push(0);
		bool f=0;
		while(!q.empty())
		{
			newKey=0;
			int u=q.front();
			q.pop();
			dfs(u);
			//cout<<u+1<<endl;
			//cout<<"** "<<newKey<<endl;
			if(vis[n-1])
			{
				f=1;
				break;
			}
			if(!newKey) //error :(
				break;			
		}
		if(f)
			printf("Y\n");
		else
			printf("N\n");	
	}
}


