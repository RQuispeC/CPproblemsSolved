#include<bits/stdc++.h>
#define	INF 1e9
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define MAX 105
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long int64;
typedef pair< int64, int64 > pll;
int n, m, a[MAX], b[MAX];
vector < vi >  lista;
bool vis[2*MAX];
int64 begin, end, res[2*MAX+10][2*MAX+10],f, mf;
int p[2*MAX];
void argPath(int x, int64 cost)
{
    if(x == begin) 
        f = cost;
    else if(p[x]!=-1)
    {
        argPath(p[x], min(cost, res[p[x]][x]));
        res[p[x]][x] -= f;
        res[x][p[x]] += f;
        
    }
}
void sol()
{
    mf=0;
    while(1)
    {
        f=0;
        memset(vis, 0, sizeof vis);
        memset(p, -1, sizeof p);
        queue < int > q;
        q.push(begin);
        p[begin] = begin;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            vis[u] = 1;
            if(u==end) break;
            for(int i=0;i<lista[u].size();i++)
            {
                int v= lista[u][i];
                if(!vis[v] && res[u][v]>0)
                {
                    vis[v] = 1;
                    q.push(v);
                    p[v] = u;
                    
                }
            }
        }
        argPath(end,INF);
        if(f==0) break;
        mf+=f;
    }
}
int main()
{
    int sum = 0, sum2=0;
    scanf("%d %d", &n, &m);    
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]), sum2+=a[i];
    for(int i=0;i<n;i++)
        scanf("%d", &b[i]), sum+=b[i];
    begin=0 , end = 2*n +4;
    lista.assign(2*MAX+10 , vi());
    memset(res, 0,sizeof res);
    for(int i=0;i<m;i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        lista[x].push_back(y + n);
        lista[y].push_back(x + n);
        lista[y + n].push_back(x);
        lista[x + n].push_back(y);
        res[x][y + n] = res[y][x + n] = INF;
    }
    for(int i=1;i<=n;i++)    
    {
        lista[begin].push_back(i);
        lista[i].push_back(begin);
        lista[end].push_back(i + n);
        lista[i+ n].push_back(end);
        lista[i].push_back(i+n);
        lista[i+n].push_back(i);
        res[begin][i] = a[i-1];
        res[i + n][end] = b[i-1];
        res[i][i+n] = INF;
    }    
    sol();
    if(mf!=sum || sum2 != sum)
        puts("NO");
    else
    {
        puts("YES");
        for(int i=1;i<=n;i++)
        {
            //cout<<i<<" : "<<endl;
            for(int j=1;j<=n;j++)
               // cout<<j<<" ::: "<<res[i][j+n]<<endl;
               if(res[i][j+n]==0 || res[i][j+n] == INF )
                    cout<<0<<" ";
               else
                    cout<<INF - res[i][j+n]<<" ";  
            cout<<endl;        
        }
    }       
}

