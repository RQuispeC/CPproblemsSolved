#include<bits/stdc++.h>
#define MAX 5010
using namespace std;
typedef vector < int > vi;
typedef pair < int  , int > pii;
vector < vi > lista;
int n, dist[MAX], diam, cent1, cent2;
pii diametro()
{
	memset(dist, -1, sizeof dist);
	queue < int  > q;
	q.push(0);
	dist[0]=0;
	int ext1, ext2;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<lista[u].size();i++)
		{
			int v=lista[u][i];
			if(dist[v]==-1)
			{
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
		ext1=u;
	}
	memset(dist, -1 , sizeof dist);
	q.push(ext1);
	dist[ext1]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<lista[u].size();i++)
		{
			int v=lista[u][i];
			if(dist[v]==-1)
			{
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
		ext2=u;
	}
	diam=dist[ext2];
	return make_pair(ext1, ext2);
}
bool bfs(int node)
{ 
	//cout<<" -->node:  "<<node+1<<endl;
	memset(dist, -1, sizeof dist);
	queue < int > q;  
	q.push(node);
	dist[node]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<lista[u].size();i++)
		{
			int v=lista[u][i];
			if(dist[v]==-1)
			{
				dist[v]=dist[u]+1;
				//cout<<v+1<<" ---> "<<dist[v]<<endl;
				if(diam %2 ==0 )
				{
					if(dist[v] > diam/2)
					{
						//cout<<"entra1" <<endl;
						return false;		
					}
				}
				else
				{
					if(dist[v] > (diam/2) +1)
					{
						//cout<<"entra2" <<endl;
						return false;		
					}
				}	
				q.push(v);
			}
		}
	}
	//cout<<"sale"<<endl;
	return true;
}
void bfs2(int node)
{
	memset(dist, -1, sizeof dist);
	queue < int > q;  
	q.push(node);
	dist[node]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<lista[u].size();i++)
		{
			int v=lista[u][i];
			if(dist[v]==-1)
			{
				dist[v]=dist[u]+1;		
				q.push(v);
			}
		}
	}
}
int main()
{
	vi worst, best, posibles;
	while(cin>>n)
	{
		lista.assign(MAX, vi());
		worst.clear(); best.clear();
		for(int u=0;u<n;u++)
		{
			int k;
			scanf("%d", &k);
			for(int j=0;j<k;j++)
			{
				int v;
				scanf("%d", &v);
				v--;
				lista[u].push_back(v);
			}
		}
		pii ext=diametro();
		//cout<<ext.first+1 << " *  "<<ext.second +1<<" : " <<diam<<endl;
		
		if(diam%2 == 0) // existe solo una raiz
		{
			posibles.clear();
			for(int i=0 ; i<n;i++)
				if(dist[i]== diam/2)
					posibles.push_back(i);
						
			for(int i=0;i<posibles.size();i++)
			{
				if(bfs(posibles[i]))
				{
					//cout<<"ent "<<i+1<<endl;
					best.push_back(posibles[i]);
					break;
				}
			}
			bfs2(best[0]);
			for(int i=0;i<n;i++)
				if(dist[i]==diam/2)
					worst.push_back(i);
				
		}
		else //existen varias raices
		{
			posibles.clear();
			bool flag;
			if(dist[ext.first]==0) flag=false;
			else flag=true;
			for(int i=0 ; i<n;i++)
				if(dist[i]== diam/2)
					posibles.push_back(i);
			for(int i=0;i<posibles.size();i++)
			{
				if(bfs(posibles[i]))
				{
					best.push_back(posibles[i]);
					break;
				}
			}
			bfs2(best[0]);
			for(int i=0;i<n;i++)
				if(dist[i]==diam/2 +1 )
					worst.push_back(i);
			
					
			if(flag == false)
				bfs2(ext.second);
			else
				bfs2(ext.first);
			posibles.clear();	
			for(int i=0 ; i<n;i++)
				if(dist[i]== diam/2)
				{
					posibles.push_back(i);
				}		
			for(int i=0;i<posibles.size();i++)
			{
				bool ans=bfs(posibles[i]);
				if(ans)
				{
					//cout<<posibles[i]+1<<" ++ "<<endl;
					best.push_back(posibles[i]);
					break;
				}
			}
			bfs2(best[1]);
			for(int i=0;i<n;i++)
				if(dist[i]==diam/2 +1)
					worst.push_back(i);	
		}
		sort(best.begin(), best.end());
		sort(worst.begin(), worst.end());
		printf("Best Roots  :");
		for(int i=0;i<best.size();i++)
			printf(" %d", best[i]+1);
		printf("\nWorst Roots :");
		for(int i=0;i<worst.size();i++)
			printf(" %d", worst[i]+1);	
		printf("\n");
	}
}

