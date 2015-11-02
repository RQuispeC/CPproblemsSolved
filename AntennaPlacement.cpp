#include<bits/stdc++.h>
#define MAX 1000
#define INF 1e9
using namespace std;
int fil , col, n , m , NIL;
vector < string > grip;
vector < vector < int  > > lista; 
int dist[MAX], match[MAX];
int ele[50][50], der[50][50], izq[50][50];
int dx[4]={0, 1 , 0 , -1};
int dy[4]={1, 0 , -1,  0};
bool validate( int i, int j )
{
	return i>=0 && j>=0 && i<fil && j<col;
}
void ini()
{
    bool flag=1;
    for(int i=0;i<49;i++)
        for(int j=0;j<49;j++)
        {
            flag?ele[i][j]=0:ele[i][j]=1;
            flag= not flag;
        }
}
bool bfs()
{
    queue < int > q;
    for(int i=0;i<n;i++)
    {
        if(match[i]==NIL)
        {
            dist[i]=0;
            q.push(i);
        }
        else
            dist[i]=INF;
    }
    dist[NIL]=INF;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<lista[u].size();i++)
        {
            int v=lista[u][i];
            if(dist[match[v]]==INF)
            {
                dist[match[v]]=dist[u]+1;
                q.push(match[v]);
            }
        }
    }
    return dist[NIL]!=INF;
}
bool dfs(int u)
{
    if(u!=NIL)
    {
        for(int i=0;i<lista[u].size();i++)
        {
            int v=lista[u][i];
            if(dist[match[v]] == dist[u]+1)
                if(dfs(match[v]))
                {
                    match[v]=u;
                    match[u]=v;
                    return true;
                }
        }
        dist[u]=INF;
        return false;
    }
    return true;
}
int hopcroft_karp()
{
    NIL=n+m;
    for(int i=0;i<n+m;i++)
        match[i]=NIL;
    int matching=0;
    
    //greedy
    for(int u=0;u<n;u++)
        for(int i=0;i<lista[u].size();i++)
        {
            int v=lista[u][i];
            if(match[v]==NIL)
            {
               matching++;
               match[u]=v; 
               match[v]=u;
               break;
            }
        }
    while(bfs())
    {
        for(int u=0;u<n;u++)
        {
            if(match[u]==NIL && dfs(u))
                matching++;
        }
    }
    return matching;
}
int main()
{
    vector < int > xxx;
    xxx.clear();
    ini();
    int tested;
    scanf("%d", &tested);
    while(tested--)
    {
        grip.clear();
        lista.assign(MAX, xxx);
        memset(der, -1, sizeof der);
        memset(izq, -1, sizeof izq);
        scanf("%d %d", &fil , &col);
        for(int i=0;i<fil;i++)
        {
            string s;
            cin>>s;
            grip.push_back(s);
        }
        n=m=0;
        for(int i=0;i<fil;i++)
            for(int j=0;j<col;j++)
            {
                if(grip[i][j]=='*' && ele[i][j]==1)
                {
                    der[i][j]=n++;
                }
                if(grip[i][j]=='*' && ele[i][j]==0)
                {
                    izq[i][j]=m++;
                }
            }
		for(int i=0;i<fil;i++)
            for(int j=0;j<col;j++)
            {
                if(grip[i][j]=='*' && ele[i][j]==1)
                {
					for(int k=0;k<4;k++)
					{
						int ni=i+dy[k], nj=j+dx[k];
						if(validate(ni, nj) && grip[ni][nj]=='*')
						{
							lista[der[i][j]].push_back(izq[ni][nj]+n);
						}
					}                    
                }
				
            }
         int match=hopcroft_karp();
         //printf("**%d\n", match );
         printf("%d\n", match + NIL-2*match  );   
    }   
}

