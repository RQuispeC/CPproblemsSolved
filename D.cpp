#include<bits/stdc++.h>
#define	INF 1e9
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define MAX 123490
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
typedef pair< ll, ll > pll;
vector < vi > gg, g;
int n, m, root, dis[MAX];
bool vis[MAX], need[MAX];
int sum=0;
bool dfs1( int u)
{
    vis[u] = 1;
    bool ans = need[u];
    for(int i=0;i<gg[u].size();i++)
    {
        int v=gg[u][i];
        if(!vis[v])
        {
            bool tmp = dfs1(v);
            ans|=tmp;
            if(tmp)
            {
                sum++;
                g[u].push_back(v);
                g[v].push_back(u);
                //cout<<u+1<<" --> "<<v+1<<endl;
            }
        }
    }
    return ans;
}
void getSol()
{
    queue < int > q;
    memset(vis, 0, sizeof vis);
    dis[root]=0;
    q.push(root);
    int left=root;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=1;
        left=u;
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(!vis[v])
            {
                vis[v] = 1;
                dis[v] = dis[u]+1;
                q.push(v);
            }
        }
    }
    memset(dis, -1, sizeof dis);
    memset(vis, 0, sizeof vis);
    q.push(left);
    dis[left]=0;
    int maxDis=0, right=left;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=1;
        maxDis=max(maxDis, dis[u]);
        right=u;
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(!vis[v])
            {
                vis[v] = 1;
                dis[v] = dis[u]+1;
                q.push(v);
            }
        }
    }
    for(int i=0;i<n;i++)
        if(dis[i]==maxDis && i<left)
        {
            left=i;
            break;
        }
    memset(dis, -1, sizeof dis);
    memset(vis, 0, sizeof vis);
    q.push(right);
    dis[right]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=1;
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(!vis[v])
            {
                vis[v] = 1;
                dis[v] = dis[u]+1;
                q.push(v);
            }
        }
    }    
    int ans = min(left, right);
    for(int i=0;i<n;i++)
        if(dis[i]==maxDis && i<ans)
        {
            ans=i;
            break;
        }    
    cout<<ans+1<<endl;
    cout<<sum*2 - maxDis<<endl;
}
int main()
{
    memset(need, 0, sizeof need);
    gg.assign(MAX, vi());
    g.assign(MAX, vi());
    scanf("%d %d", &n, &m);
    for(int i=1;i<n;i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        gg[u].push_back(v);
        gg[v].push_back(u);
    }
    for(int i=0;i<m;i++)
    {
        int u;
        scanf("%d", &u);
        u--;
        need[u]=1;
        root=u;
    }
    memset(vis, 0,sizeof vis);
    dfs1(root);
    getSol();
}

