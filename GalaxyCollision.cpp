#include<bits/stdc++.h>
#define	INF 1<<30
#define MAX 50005
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long int64;
typedef pair< int64, int64 > pll;
struct point
{
	int x, y;
	point(){}
	point(int _x,int _y)
	{
		x=_x, y=_y;
	}
	bool  operator < (point other) const
	{
		if(x != other.x)
			return x < other.x; 
		return 	y < other.y;
	}
	bool operator == (point other) const
	{
		return x==other.x && y==other.y;
	}
	
};
int n;
point a[MAX];
bool vis[MAX];
vector < vi > lista;
map  < point, int > mapa;
map  < point, int >::iterator it;
vector < point > v;

void getAdj(int u)
{		
	//cout<<u<<" -----:< :::"<<endl;
	//cout<<"::"<<a[u].x<<" "<<a[u].y<<endl;
	for(int i=0;i<v.size();i++)
	{
		point p = point(a[u].x + v[i].x, a[u].y + v[i].y);
		it = mapa.find(p);
		//cout<<"-->::"<<p.x<<" "<<p.y<<endl;
		if(it!=mapa.end())
		{
			//cout<<u<<" --> "<<(it->first.x)<<" "<< (it->first.y)<<endl;
		//	cout<<u+1<<"-->"<< it->second <<endl;
			lista[u+1].push_back(it->second);
			lista[it->second].push_back(u+1);
		}	
	}
	//cout<<"---------------------"<<endl;
}
void dfs(int u, int &numElem, int &left, bool side)
{
	numElem++;
	if(side) left++;
	vis[u] = 1;
	for(int i=0;i<lista[u].size();i++)
	{
		int v=lista[u][i];
		if(!vis[v])
			dfs(v, numElem, left, !side);
	}
	
}
void show()
{
	for(it = mapa.begin();it!=mapa.end();it++)
		cout<< (it->first.x)<<" "<< (it->first.y)<<" : " << (it->second) <<endl;
}
int main()
{
	v.clear();
	for(double i=0;i<=5.0;i++)
		for(double j=0;j<=5.0;j++)
			if(i==j && i==0) continue;
			else if((i*i) + (j*j) <= 25.0)
			{
			 	v.push_back(point(i, j));
			 	if(j!=0)
			 		v.push_back(point(i, -j));
			}
	//cout<<v.size()<<endl;
	while(scanf("%d", &n)==1)
	{
		mapa.clear();
		lista.assign(n+1, vi());
		for(int i=0;i<n;i++)
		{
			scanf("%d %d", &a[i].x, &a[i].y);
			vis[i] = vis[i+1] = 0;
		}	
		sort(a, a+n);
		for(int i=n-1;i>=0;i--)
		{
			getAdj(i);
			mapa[a[i]] = i+1;
		}
		//show();
		int ans=0;
		for(int i=1;i<=n;i++)
			if(!vis[i])
			{
				int numElemt=0, left=0;
				dfs(i, numElemt, left, 0);
				//cout<<i<<" *** "<<numElemt<<" "<<left<<endl;
				ans+=min(numElemt -left, left);
			}	
		printf("%d\n", ans);
	}	
}

