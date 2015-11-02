#include<bits/stdc++.h>
#define MAX  55
using namespace std;
typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
vector < vi > lista;
int n , m;
bool visited[MAX];
long long con;
void dfs(int u)
{
	visited[u]=1;
	for(int i=0;i<lista[u].size();i++)
	{
		int v=lista[u][i];
		if(!visited[v])
		{
			con++;
			dfs(v);
		}	
	}
}
int main()
{
	lista.assign(MAX, vi());
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
    	int u , v;
    	scanf("%d %d", &u , &v);
    	u--;v--;
    	lista[u].push_back(v);
    	lista[v].push_back(u);
    	//cout<<u<<" : "<<v<<endl;
    }
    //cout<<"pas"<<endl;
    memset(visited, 0, sizeof visited);
    long long  ans=1ll;
    for(int i=0;i<n;i++)
    {
    	if(!visited[i])
    	{
    		con=1;
    		dfs(i);
    		ans*=(1ll<<(con-1));
    	}
    }
    cout<<ans<<endl;
}

