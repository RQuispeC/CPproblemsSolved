#include<bits/stdc++.h>
#define MAX (int)1e4 + 5
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
vector < vii > v;
int n, m, c[MAX], deg[MAX];
ll memo[MAX];
bool vis[MAX];
vi corr;
int main()
{
	while(cin>>n>>m)
	{
		corr.clear();
		v.assign(MAX, vii());
		memset(memo, -1, sizeof memo);
		for(int i=0;i<n;i++)
			scanf("%d", &c[i]);
		for(int i=0;i<m;i++)	
		{
			int a, x, y;
			scanf("%d %d %d", &a, &x, &y);
			a--, x--, y--;
			v[a].push_back(pii(x,y));
		}
		priority_queue < pii, vii, greater < pii > > q;
		for(int i=0;i<n;i++)
		{
			q.push(pii(v[i].size(), i));			
			deg[i]=v[i].size();
		}	
		while(!q.empty())
		{
			pii tope = q.top();
			q.pop();
/*			if(corr.size()> 0 )
			{
				for(int i=0;i<n;i++)
					cout<<i+1<<" -->" <<memo[i]<<endl;
				if(q.empty()) cout<<"**"<<endl;
				if(tope.first > v[corr[0]].size()) cout<<"--"<<endl;
				if(tope.first > v[corr[0]].size() || q.empty())
				{
					cout<<"em"<<endl;
					q.push(tope);
					for(int i=0;i<corr.size();i++)
						q.push(pii(v[corr[i]].size(), corr[i]));
					corr.clear();
					continue;
				}
			}
			
	*/		//cout<<tope.first<<" : "<<tope.second+1<<endl;
			int u = tope.second;
			if(memo[u]!=-1) continue;
			//cout<<u+1<<"  ";
			ll ans=ll(c[u]);
			bool f=1;
			for(int j=0;j<v[u].size();j++)
			{
				if(memo[v[u][j].first] != -1 && memo[v[u][j].second]!= -1)
					ans=min(ans, memo[v[u][j].first] + memo[v[u][j].second]);
				else
				{
					/*for(int k=0;k<n;k++)
						cout<<k+1<<":* "<<memo[k]<<endl;
					cout<<u+1<<" ** "<<endl;
					cout<<v[u][j].first+1<<" "<<memo[v[u][j].first]<<endl;
					cout<<v[u][j].second+1<<" "<<memo[v[u][j].second]<<endl;*/
			//		corr.push_back(u);
					if(memo[v[u][j].first] == -1)
						q.push(pii(--deg[v[u][j].first], v[u][j].first));
					if(memo[v[u][j].second] == -1)
						q.push(pii(--deg[v[u][j].second], v[u][j].second));	
					q.push(tope);
					f=0;
					break;
				}
			}	
			if(f)
				memo[u]=ans;
		}
		cout<<memo[0]<<endl;
		//cout<<"...................."<<endl;
	}
}

