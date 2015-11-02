#include<bits/stdc++.h>
#define	INF 1ll<<40
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define MAX 100005
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef pair < string , string > pss; 
typedef long long ll;
int n , a, b;
vector < string > grip;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
map < pii, int  >  mp;
int mapa[1000][1000];
bool valid(int i, int j)
{
	return i>=0 && j>=0 && i<n && j<n;
}
ll dp[1000][1000];
void getGraph()
{
	for(int i=0;i<1000;i++)
		for(int j=0;j<1000;j++)
			if(i==j) dp[i][j]=0ll;
			else dp[i][j]=INF;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<4;k++)
				if(valid(i + dy[k] ,j + dx[k] ))
				{
					if(grip[i][j]==grip[i+dy[k]][j+dx[k]])
						dp[ mapa[i][j] ][ mapa[i+dy[k]][j+dx[k]] ] = a;
					else	
						dp[ mapa[i][j] ][ mapa[i+dy[k]][j+dx[k]] ] = b;
				}	
		}
	}					
}
int main()
{
	freopen("distant.in", "r", stdin);
	freopen("distant.out", "w", stdout);
	cin>>n>>a>>b;
	grip.clear();
	int K=0;
	for(int i=0;i<n;i++)
	{
		string tmp;
		cin>>tmp;
		grip.push_back(tmp);
		for(int j=0;j<n;j++)
			mapa[i][j] = K++;
	}
	getGraph();
	
	for(int k=0;k<K;k++)
		for(int i=0;i<K;i++)
			for(int j=0;j<K;j++)			
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				
	ll ans=0ll;
	for(int i=0;i<K;i++)
		for(int j=0;j<K;j++)						
			ans=max(ans, dp[i][j]);
	cout<<ans<<endl;		
	
}

