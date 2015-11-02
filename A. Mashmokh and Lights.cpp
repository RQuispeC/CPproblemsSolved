#include<iostream>
#include<cstring>
using namespace std;
int n, m;
int main()
{
	int a[105];
	int ans[105];
	bool visited[105];
	memset(a, -1, sizeof a);
	memset(ans, -1, sizeof ans);
	memset(visited, false, sizeof visited);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int l;
		cin>>l;
		for(int j=l-1;j<n;j++)
		{
			if(!visited[j])
			{
				visited[j]=true;
				ans[j]=l;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i];
		if(i+1<n) cout<<" ";
	}
	cout<<endl;
}
