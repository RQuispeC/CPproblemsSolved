#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
typedef   vector < int  > vi;
vector < vi > tree, children;
int root, memo[MAX][2], n;
bool visited[MAX];
void generate()
{
	memset(visited, 0, sizeof visited);
	visited[root]=1;
	queue < int > q;
	q.push(root);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<tree[u].size();i++)
		{
			int v=tree[u][i];
			if(!visited[v])
			{
				visited[v]=1;
				children[u].push_back(v);
				q.push(v);
			}
		}
	}
}
bool leaf(int v)
{
	return children[v].size() == 0 ;
}
int MVC(int v, int flag)
{
	int ans=0;
	if(memo[v][flag] != -1) return memo[v][flag];
	else if(leaf(v))
		ans=flag;
	else if(flag==0)
	{
		ans=0;
		for(int i=0;i<children[v].size();i++)
		{
			ans+= MVC(children[v][i], 1);
		}
	}
	else if(flag==1)
	{
		ans=1;
		for(int i=0;i<children[v].size();i++)
		{
			ans+= min(MVC(children[v][i], 1), MVC(children[v][i], 0));
		}
	}
	return memo[v][flag]=ans;
}

int main()
{	
	tree.assign(MAX, vi());
	children.assign(MAX, vi());
	scanf("%d", &n);
	int maxim=-1;
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d %d", &u, &v);
		u--, v--;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	root=0;
	generate();
	memset(memo, -1, sizeof memo);
	printf("%d\n", min(MVC(root, true), MVC(root, false) ));
}

