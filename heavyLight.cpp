#include <bits/stdc++.h>
#define MAX 100
using namespace std;
typedef vector < int > vi;
vector < vi > lista;
int childNum[MAX], root, mapa[MAX], numHeavyComp, indice, indPa;
bool vis[MAX], isHeavy[MAX];
struct heavyComp
{
	int n, root;
	vi vertex, ST;
	heavyComp()
	{
		vertex.clear();
		ST.clear();
		n=0;
	}
	void addVertex(int u)
	{
		n++;
		vertex.push_back(u);
	}
	//-------ST code -------------
	void built(int p, int i, int j)
	{
		if(i==j) 
		{
			ST[p]=vertex[i];
		}
		else
		{
			int m=(i+j)/2;
			built(2*p, i, m);
			built(2*p+1, m+1, j);
			ST[p]=ST[2*p] + ST[2*p+1];
		}
	}
	//----------------------------
	void getST()
	{
		ST.assign(3*n, 0);
		built(1, 0, n-1);
		int maxChild=0;
		for(int i=0;i<vertex.size();i++)
			if(maxChild < childNum[vertex[i]])
			{
				root=vertex[i];
				maxChild=childNum[vertex[i]];
			}
	}
};
int n , m;
int getChild(int u)
{
	vis[u]=1;
	int ans=1;
	for(int i=0;i<lista[u].size();i++)
		if(!vis[lista[u][i]])
			ans+=getChild(lista[u][i]);
	return childNum[u]=ans;
}
int builtHL(int u, bool flag)
{
	mapa[u]=indPa;
	if(flag) isHeavy[mapa[u]]=1;
	vis[u]=1;
	int ind=-1, maxChil=0;
	for(int i=0;i<lista[u].size();i++)
	{
		if(maxChil < childNum[lista[u][i]] && !vis[lista[u][i]])
		{
			maxChil = childNum[lista[u][i]];
			ind=i;
		}
	}
	//if(ind != -1) cout<<u+1<<" --> "<<lista[u][ind]+1<<endl;
	if(ind != -1) builtHL(lista[u][ind], 1);
	for(int i=0;i<lista[u].size();i++)
		if(!vis[lista[u][i]] && i!=ind && childNum[lista[u][i]]!=1)
		{
			indPa++;
			builtHL(lista[u][i], 0);
		}	
}
heavyComp h[MAX];
void getHL()
{
	for(int i=0;i<MAX;i++) h[i]=heavyComp();
	builtHL(root, 1);
	for(int u=0;u<n;u++)
		if(isHeavy[mapa[u]])
		{
			if(h[mapa[u]].n==0) numHeavyComp++;
			h[mapa[u]].addVertex(u);
		}	
	/*for(int i=0;i<numHeavyComp;i++)
	{
		h[i].getST();
		cout<<h[i].root+1<<endl;
		for(int j=0;j<h[i].vertex.size();j++)
			cout<<h[i].vertex[j]+1<<"  ";
		cout<<endl;	
	}
	for(int i=0;i<n;i++)
		cout<<i+1<<" : "<<(isHeavy[mapa[i]]?"YES": "NO")<<endl;
	cout<<numHeavyComp<<endl;
		*/
}
int main()
{
	lista.assign(MAX, vi());
	//get input data
	scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		lista[u].push_back(v);
		lista[v].push_back(u);
	}
	root=0;
	indice=0;
	numHeavyComp=0; 	
 	memset(vis, 0, sizeof vis);
 	memset(isHeavy, 0, sizeof isHeavy);
 	memset(mapa, -1,sizeof mapa);
 	getChild(root);
 	memset(vis, 0, sizeof vis);
 	getHL();
}
/*
32 31
1 2
1 3
1 4
1 5
2 6
3 7
3 8
3 9
3 10
5 11
7 12
8 13
9 14
9 15
9 16
11 17
11 18
11 19
12 20
12 21
13 22
13 23
17 24
19 25
22 26
24 27
24 28
25 29
25 30
25 31
25 32
*/
