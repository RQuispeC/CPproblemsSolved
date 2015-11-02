#include<bits/stdc++.h>
#define MAX (int) 2505
using namespace std;
typedef pair < int , int > pii;
typedef vector < int > vi;
typedef vector < pii > vii;
vector < vi > lista;
bool vis[MAX];
int p[MAX], dist[MAX], far[MAX], n;
pii diametro(int node)
{
	memset(vis, 0, sizeof vis);
	memset(p, -1, sizeof p);
	queue < int >  q;
	q.push(node);
	vis[node]=1;
	int ini=node;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<lista[u].size();i++)
		{
			int v=lista[u][i];
			if(v >= 0 && !vis[v])
			{
				vis[v]=1;
				q.push(v);
			}
		}
		ini=u;
	}
	memset(vis, 0, sizeof vis);
	q.push(ini);
	vis[ini]=1;
	p[ini]=ini;
	dist[ini]=0;
	int end=ini;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<lista[u].size();i++)
		{
			int v=lista[u][i];
			if(v >=0 && !vis[v])
			{
				vis[v]=1;
				p[v]=u;
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
		end=u;
	}
	return pii(ini, end);
}
int nodeAt(int ini, int d)
{
	while(d--)
	{
		ini=p[ini];
	}
	return ini;
}
vii path(int ini, int end)
{
	vii  ans;
	ans.clear();
	while(ini != end )
	{
		ans.push_back(pii(ini, p[ini]));
		ini=p[ini];
	}
	return ans;
}
void eliminar(int x, int y)
{
	for(int i=0;i<lista[x].size();i++)
		if(lista[x][i]==y)
		{
			lista[x][i]=-1;
			break;
		}
	//cout<<"el1"<<endl;	
    for(int i=0;i<lista[y].size();i++)
		if(lista[y][i]==x)
		{
			//cout<<lista[y][i]<<"  --"<<endl;
			lista[y][i]=-1;
			break;
		}	
	//cout<<"el2"<<endl;	
}
int main()
{
	int tested;
	scanf("%d", &tested);
	while(tested--)
	{
		lista.assign(MAX, vi());
		scanf("%d", &n);
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d %d", &u, &v);
			u--, v--;
			
			lista[u].push_back(v);
			lista[v].push_back(u);
		}
		pii ext=diametro(0);
		int lastWorst=dist[ext.second];
		//cout<<"dist :  "<<(lastWorst + 1 ) / 3<<endl;
		
		int begin=nodeAt(ext.second, (lastWorst + 1 ) / 3 );
		int lim=p[nodeAt(begin, (lastWorst + 1 ) / 3)];
		pii newVertex=pii(begin, lim);
		//cout<<"beg :  "<<begin+1<<endl;
		//cout<<"lim :  "<<lim+1<<endl;
		lista[lim].push_back(begin);
		lista[begin].push_back(lim);
		
		vii cam=path(begin, lim);

		int newWorst =lastWorst;
		pii oldVertex;
		for(int i=0;i<cam.size();i++)
		{
			//cout<<"en"<<endl;
			eliminar(cam[i].first, cam[i].second);
			//cout<<"en2"<<endl;
			//cout<<cam[i].first+1<<" : "<<cam[i].second+1<<endl;
			pii newExt=diametro(0);
			//cout<<dist[newExt.second] <<endl;
			if(dist[newExt.second] < newWorst )
			{
				newWorst = dist[newExt.second];
				oldVertex=pii(cam[i].first, cam[i].second);
			}
			//cout<<"pas"<<endl;
			lista[cam[i].first].push_back(cam[i].second);
			lista[cam[i].second].push_back(cam[i].first);
			//cout<<"pas"<<endl;
			//cout<<"-----"<<endl;
		}
		cout<<lastWorst-newWorst<<endl;
		cout<<oldVertex.first+1<<" "<<oldVertex.second+1<<endl;
		cout<<newVertex.first+1<<" "<<newVertex.second+1<<endl;
	}
}

