#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,m,k;
	cin>>n>>m>>k;
	int mat[n][m];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%d",&mat[i][j]);	
		}
	}
	int a,b;
	vector<int> lis[m];
	int res[n];
	for (int i = 0; i < n; ++i)
	{
		res[i]=0;
	}

	for (int i = 0; i < k; ++i)
	{
		cin>>a>>b;
		lis[b-1].push_back(a-1);
		res[a-1]--;
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			res[j]+=lis[i].size()*mat[j][i];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if(i!=0) printf(" ");
		if(res[i]>=0)printf("%d",res[i]);
		else printf("0");
	}
	printf("\n");
}
