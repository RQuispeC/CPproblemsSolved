#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int time [10][50005];
	int finish [10][50005];
	int n, m;
	memset (finish, 0 , sizeof (finish));
	scanf("%d %d", &m ,&n);
	for(int j=0;j<m;j++)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d" , &time[i][j]);
		}
	}
	finish[0][0]=time[0][0];		
	for(int j=1;j<m;j++)
		finish[0][j]=finish[0][j-1]+time[0][j];
	for(int i=1;i<n;i++)
		finish[i][0]=finish[i-1][0]+time[i][0];
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			finish[i][j] = max(finish[i-1][j], finish[i][j-1]) + time[i][j];
		}
	}	
	for(int j=0;j<m;j++)
	{
		printf("%d", finish[n-1][j]);
		if(j+1<m)
			printf(" ");
	}
	printf("\n");		
	
}

