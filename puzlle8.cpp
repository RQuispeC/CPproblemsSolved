#include<bits/stdc++.h>
#define	INF 1<<30
#define MAX 1000005
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long int64;
typedef pair< int64, int64 > pll;
const  int MAXSIZE  = 3;
struct node
{
	vector < vi > grip;
	vii sol;
	int cost;
	int idProc, pastDistance;
	string str;
	void getCost() // distancia hamiltoniana
	{
		int pos=1;
		cost=0;
		for(int i=0;i<MAXSIZE;i++)
			for(int j=0;j<MAXSIZE;j++)
			{
				cost+= abs(i- sol[grip[i][j]].first) + abs(j- sol[grip[i][j]].second);
			}
	}
	void getStr()
	{
		str="";
		for(int i=0;i<MAXSIZE;i++)
			for(int j=0;j<MAXSIZE;j++)
				str+= (char)('0'+ grip[i][j]);
	}
	node()
	{
		grip.assign(MAXSIZE, vi(MAXSIZE, -1));
		cost = INF;
		pastDistance=0;
	}
	node(vector < vi > _grip, int id) 
	{
		grip = _grip;
		idProc = id;
		pastDistance=0;
	
		sol.push_back(pii(MAXSIZE-1, MAXSIZE-1));
		int ans=1;
		for(int i=0;i<MAXSIZE;i++)
			for(int j=0;j<MAXSIZE;j++)
				sol.push_back(pii(i, j));
		
		getCost();
	}
	bool operator < ( node other) const // A* distance
	{
		//if(cost + pastDistance != other.cost + other.pastDistance)
			return cost + pastDistance > other.cost + other.pastDistance;
		//return idProc < other.idProc;
	}
	
	bool operator == (node other) const
	{
		for(int i=0;i<MAXSIZE;i++)
			for(int j=0;j<MAXSIZE;j++)
				if(grip[i][j] != other.grip[i][j])
					return 0;
		return 1;
	}
	void show()
	{
		for(int i=0;i<MAXSIZE;i++)
		{
			for(int j=0;j<MAXSIZE;j++)
				printf("%d  ", grip[i][j]);
			puts("");
		}
	}
};
map < node, int > vis;
map < node, node> p;
bool valid(int i, int j)
{
	return i>=0 && j>=0 && i<MAXSIZE && j<MAXSIZE;
}
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
vector < node > getAdj(node cur)
{
	vector < node >  ans;
	ans.clear();
	int i, j;
	bool f=1;
	for(i=0;i<MAXSIZE && f;i++)
	{
		for(j=0;j<MAXSIZE && f;j++)	
			if(cur.grip[i][j]==0)
			{
				f=0;
				break;
			}	
		if(!f) break;	
	}
	for(int k=0;k<4;k++)
	{
		int ni = i+dy[k];
		int nj = j+dx[k];
		if(valid(ni, nj))
		{
			vector < vi > tmp;
			tmp = cur.grip;
			tmp[i][j] = cur.grip[ni][nj];
			tmp[ni][nj] = 0;
			ans.push_back(node(tmp, -1));
		}
	}
	return ans;
}
node ans;
bool A(node cur)
{
	p.clear(), vis.clear();
	priority_queue < node > q;
	q.push(cur);
	p[cur] = cur;
	int idProc = 2;
	while(!q.empty())
	{
		node u= q.top();
		vis[u] = 1;
		u.show(), cout<<"cost : "<<u.cost<<" : "<<u.pastDistance<<endl;
		q.pop();
		cout<<"-----------"<<endl;
		if(u.cost==0) 
		{
			ans=u;
			//ans.show();
			//p[ans].show();
			return 1;
		}	
		vector < node > adj = getAdj(u);
		for(int i=0;i<adj.size();i++)
			if(!vis.count(adj[i]))
			{
				adj[i].idProc = idProc++;
				adj[i].pastDistance = u.pastDistance + 1;
				q.push(adj[i]);
				p[adj[i]] = u;
				/*adj[i].show();
				cout<<"------->"<<endl;
				p[adj[i]].show();
				cout<<"**********"<<endl;*/
			}		
		
	}
	return 0;
}
void getPath(node beg, node cur)
{
	if(cur == beg ) 
	{
		cur.show();
		return;
	}
	
	cur.show();
	if(cur==ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	cout<<"--->"<<endl;
	p[cur].show();
	if(p[cur].grip[0][0]==-1) return;
	cout<<"---------"<<endl;
	getPath(beg, p[cur]);
	cur.show();
}
int main()
{
	printf("###############\n");
	printf("A*\n");
	printf("###############\n");
	printf("Ingrese grip:\n");
	
	vector < vi > v, sol;
	v.assign(MAXSIZE,vi(MAXSIZE));
	sol.assign(MAXSIZE,vi(MAXSIZE));
	
	int ans=1;
	for(int i=0;i<MAXSIZE;i++)
		for(int j=0;j<MAXSIZE;j++)
		{
			scanf("%d", &v[i][j]);
			sol[i][j] = ans++;
		}
	
	sol[MAXSIZE-1][MAXSIZE-1]	= 0;
	
	node root  = node(v, 1);
	
	A(root);
	
	getPath(root, node(sol, 0));
}
/*
123
456
87	
*/
