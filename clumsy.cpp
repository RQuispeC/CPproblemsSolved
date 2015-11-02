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
int ac[MAX];
vi getUnmachet()
{
	memset(ac, 0, sizeof ac);
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
	vector < int > v;
	v.clear();
	while(!q.empty())
	{
		v.push_back(q.top());
		q.pop();
	}
	for(int i=0;i<v.size();i++)
		if(i==0) ac[i] = (v[i]==')');
		else ac[i] = ac[i-1] + (v[i]==')');
	return v;
}
int queryLeft(int i, int j)
{
	if(i==0) return ac[j];
	return ac[j] - ac[i-1];
}
int queryRight(int i, int j)
{
	return j - i +1 - queryLeft(i, j);
}
int cost(int lo, int hi)
{
	//cout<<lo<<": "<<hi<<endl;
	if(lo>=hi) return INF;
	int m=(lo+hi)>>1;
	if(hi-lo==1) return queryRight(lo, m) + queryLeft(m+1, hi);
	int ans = queryRight(lo, m) + queryLeft(m+1, hi);
	if((m-lo+1)%2==0)
		ans=min(ans , cost(lo, m) + cost(m+1, hi));
	else
		ans=min(ans, cost(lo, m-1) + cost(m+2, hi) + cost(m, m+1));
	return ans;
}
int sol()
{
	vi v =getUnmachet();
	return cost(0, v.size()-1);
}
int main()
{
	freopen("clumsy.in", "r", stdin);
	freopen("clumsy.out", "w", stdout);
	scanf("%s", s);
	printf("%d\n", sol());
}

