#include<bits/stdc++.h>
#define MAX 110
using namespace std;
typedef vector < int > vi;
vector < vi >  lista;
vi toposort;
bool visited [MAX];
void dfs(int u)
{
	visited[u]=1;
	for(int i=0;i<lista[u].size();i++)
	{
		int v=lista[u][i];
		if(!visited[v])
			dfs(v);
	}
	toposort.push_back(u);
}
int main()
{
	string a[MAX];
	map < string ,  int > mapa;
	int n , m , k, cas=1;
	while(cin>>n)
	{
		toposort.clear();
		mapa.clear();
		lista.assign(MAX, vi());
		memset(visited, false, sizeof visited);
		k=1;
		for(int i=0;i<n;i++)
		{
			string s;
			cin>>s;
			mapa[s]=k;
			a[k]=s;
			k++;
		}
		cin>>m;
		for(int i=0;i<m;i++)
		{
			string b1,b2;
			cin>>b1>>b2;
			lista[mapa[b1]].push_back(mapa[b2]);
		}
		
		for(int i=1;i<=n;i++)
			if(!visited[i])
				dfs(i);
		reverse(toposort.begin(),toposort.end());
		cout<<"Case #"<<cas++<<": Dilbert should drink beverages in this order:";
		for(int i=0;i<n;i++)
			cout<<" "<<a[toposort[i]];
		cout<<"."<<endl<<endl;	
	}
	
}

