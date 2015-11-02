#include<bits/stdc++.h>
#define MAX  5005
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
int n , m , a[MAX], GCD[MAX];
set < int > s;
int gcd(int x,int y)
{
	if(y==0)
		return x;
	return gcd(y, x%y);
}
pii f(int x)
{
	pii ans=pii(0,0);
	for(int i=2;i*i<=x;i==2?i++:i+=2)
	{
		if(x%i==0)
		{
			int cont=0;
			while(x%i==0)
			{
				cont++;
				x/=i;
			}
			if(s.find(i)!=s.end()) //bad
				ans.first+=cont;
			else
				ans.second+=cont;
		}
	}
	if(x>1)
		if(s.find(x)!=s.end()) //bad
			ans.first++;
		else
			ans.second++;
	return ans;	
}
int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	s.clear();
	for(int i=0;i<m;i++)
	{
		int x;
		scanf("%d", &x);
		s.insert(x);
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		pii fun=f(a[i]);
		ans+=(-fun.first + fun.second);
		if(i==0) GCD[0]=a[0];
		else GCD[i]=gcd(GCD[i-1], a[i]);
	}
	int fact=1;
	for(int i=n-1;i>=0;i--)
	{
		pii fun=f(GCD[i]/fact);
		if(fun.first > fun.second)
		{
			fact=GCD[i];
			ans-=((fun.second - fun.first)*(i+1));
		}
	}
	printf("%d\n", ans);
}

