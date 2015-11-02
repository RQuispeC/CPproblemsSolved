#include<bits/stdc++.h>
#define	INF 1<<20
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define MAX 100005
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef pair < string , string > pss; 
typedef long long ll;
char s[MAX];
int sol()
{
	int n =strlen(s);
	stack <char> q;
	for(int i=0;i<n;i++)
	{
		if(q.empty())
			q.push(s[i]);
		else	
		{
			if(s[i]=='(')
				q.push(s[i]);
			else
			{
				if(q.top()=='(')
					q.pop();
				else
					q.push(s[i]);	
			}	
		}	
	}
	return n - q.size();
}
int main()
{
	//freopen("bbreeds.in", "r", stdin);
	//freopen("bbreeds.out", "w", stdout);
	scanf("%s", s);
	int tot=sol();
	tot/=2;
	if(tot==0)
		printf("%d\n", 0);
	else
	{
		int ans=1;
		for(int i=0;i<tot;i++)
			ans= (ans*2)%2012;
		printf("%d\n", ans);	
	}	
}

