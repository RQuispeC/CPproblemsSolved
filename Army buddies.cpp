#include<bits/stdc++.h>
#define MAX (int)1e5 + 5
using namespace std;
int a[MAX], b[MAX], n, q;
char f(int x)
{
	if(x==0 || x==n+1)
		return '*';
	return (char)(x+'0');
}
int main()
{
	while(scanf("%d %d", &n , &q))	
	{
		if(n==0 && q==0) break;
		
		for(int i=1;i<=n;i++)
			a[i]=i-1, b[i]=i+1;
		for(int i=0;i<q;i++)
		{
			int l,r;
			scanf("%d %d", &l,&r);
			int rA=b[a[l]]=b[r];
			int lA=a[b[r]]=a[l];
			if(lA==0 || lA==n+1)
				cout<<'*'<<" ";
			else
				cout<<lA<<" ";
			if(rA==0 || rA==n+1)
				cout<<'*'<<endl;
			else
				cout<<rA<<endl;	
		}
		cout<<'-'<<endl;
	}
}

