#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<sstream>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<string>
#include<map>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int x[100005];
	int y[100005];
	int fr[100005];
	memset(fr, 0, sizeof fr);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d", &x[i], &y[i]);
		fr[x[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		int home=n-1+fr[y[i]];
		cout<<home<<" "<<2*(n-1)-home<<endl;
	}
}
