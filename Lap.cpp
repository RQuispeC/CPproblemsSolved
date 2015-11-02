#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x, y;
	while(cin>>x>>y)
	{
		int ans=0;
		for(int time=x;1;time+=x)
		{
			int numVuelSecond=time/y;
			int numVuelFirst=time/x;
			ans++;
			if(time%y==0 && numVuelFirst>numVuelSecond) break;
			if(numVuelFirst>numVuelSecond+1) break;
		}
		printf("%d\n", ans);
	}
}

