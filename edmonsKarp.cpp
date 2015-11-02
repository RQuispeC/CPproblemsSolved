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

