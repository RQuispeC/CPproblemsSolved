#include<bits/stdc++.h>
#define MAX 1025
using namespace std;
int BIT[MAX][MAX],a[MAX][MAX], n;
int f(int x)
{
	return x & -x;
}
void updateY(int x, int y, int val)
{
	while(y<=n)
	{
		BIT[x][y]+=val;
		y+=f(y);
	}
}
void update(int x, int y, int val)
{
	while(x<=n)
	{
		updateY(x, y, val);
		x+=f(x);
	}
}
int queryY(int x, int y)
{
	int ans=0;
	while(y>0)
	{
		ans+=BIT[x][y];
		y-=f(y);
	}
	return ans;
}
int query(int x, int y)
{
	int ans=0;
	while(x>0)
	{
		ans+=queryY(x, y);
		x-=f(x);
	}
	return ans;
}
int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		memset(BIT, 0, sizeof BIT);
		memset(a, 0, sizeof a);
		scanf("%d", &n);
		char op[3];
		while(1)
		{
			scanf("%s", op);
			if(!strcmp(op, "END")) break;
			if(!strcmp(op, "SET"))
			{
				int x, y, val;
				scanf("%d %d %d", &x, &y, &val);
				x++, y++;
				if(a[x][y] != val)
				{
					update(x, y, val - a[x][y]); //want to replace
					a[x][y]=val;
				}	
			}
			if(!strcmp(op, "SUM"))
			{
				int x1, y1, x2, y2;
				scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
				x1++, y1++, x2++, y2++;
				printf("%d\n",query(x2,y2) - query(x2,y1-1) - query(x1-1,y2) + query(x1-1,y1-1));
			}
		}
		printf("\n");
	}
}

