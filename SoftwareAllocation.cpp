#include<bits/stdc++.h>
#define INF 1e9
#define MAX 50
using namespace std;
typedef vector < int > vi;
vector < vi > lista;
int s, t, f, mf, p[MAX] , res[MAX][MAX], ans[MAX];
void argument(int u, int minEdge)
{
	if(u == s)
	{
		f=minEdge;
		return;
	}
	else if(p[u] != -1)
		{
			argument(p[u], min (minEdge, res[p[u]][u]));
			ans[u]=p[u];
			res[p[u]][u] -= f;
			res[u][p[u]] += f;
		}
	
}
void edmons_Karp()
{
	bool vis[MAX];
	mf=0;
	while(1)
	{
		f=0;
		queue < int > q;
		q.push(s);
		memset(p,-1, sizeof p);
		memset(vis, 0, sizeof vis);
		vis[s]=1;
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			if(u == t ) break;
			for(int i=0;i<lista[u].size();i++)
			{
				int v=lista[u][i];
				if(res[u][v] && !vis[v]) 
				{
					q.push(v);
					p[v]=u;
					//ans[v]=u;
					vis[v]=1;
					
				}
			}
		}
		argument(t, INF);
		if(f==0) break;
		mf+=f;
	}
}
int main()
{
	bool first[MAX];
	lista.assign(MAX, vi());
	memset(res, 0, sizeof res);
	memset(first, 0, sizeof first);
 	int tot=0;
 	s=0, t=38;
 	string st;
 	bool f=1;
 	while(getline(cin , st))
 	{
 		if(!st.size())
	 		f=0;
 		if(f)
 		{
	 		stringstream in(st);
	 		string a, b;
	 		in>>a, in>>b;
	 	 	int app = a[0] - 'A' + 1 ;
	 	 	tot += (a[1] - '0');
	 	 	
	 	 	lista[s].push_back(app);
	 	 	lista[app].push_back(s);
	 	 	res[s][app] = a[1] - '0';
	 	 	for(int i=0;i+1<b.size();i++)
	 	 	{
	 	 		int comp = b[i] - '0' + 27;
	 	 		lista[app].push_back(comp);
	 	 		lista[comp].push_back(app);
	 	 		res[app][comp]=INF;
	 	 		if(!first[comp])
	 	 		{
	 	 			lista[comp].push_back(t);
	 	 			lista[t].push_back(comp);
	 	 			res[comp][t]=1;
	 	 		}	
	 	 		first[comp] = 1;
	 	 	}
	 	 	
 	 	}
 	 	else
 	 	{
 	 		memset(ans, -1, sizeof ans);
	 	 	edmons_Karp();
	 	 	if(mf == tot)
	 	 	{
	 	 		for(int i= 27;i<37;i++ )
	 	 		{
	 	 			char c=(char)(ans[i] - 1 + 'A');
	 	 			if(c>='A' && c<='Z')
	 	 				cout<<c;
	 	 			else
	 	 				cout<<'_';
	 	 		}	
	 	 		cout<<endl;	
	 	 	}
	 	 	else
	 	 		cout<<"!"<<endl;
	 	 	f=1;	
	 	 	lista.assign(MAX, vi());
 			memset(res, 0, sizeof res);
 			memset(first, 0, sizeof first);
 			tot=0;
	 	}		
 	}
 	memset(ans, -1, sizeof ans);
 	edmons_Karp();
	if(mf == tot)
	{
		for(int i= 27;i<37;i++ )
 		{
 			char c=(char)(ans[i] - 1 + 'A');
 			if(c>='A' && c<='Z')
 				cout<<c;
 			else
 				cout<<'_';
 		}
		cout<<endl;	
	}
	else
		cout<<"!"<<endl;
}



