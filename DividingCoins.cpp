#include<bits/stdc++.h>
using namespace std;
int monedas[110];
int n,total;
int memo[50010][110];
int dp( int pos, int remainder) //KADNASCK
{
	if(remainder == 0 || pos==n) return 0;
	if(memo[remainder][pos] != -1) return memo[remainder][pos];
	int ans;
	if(monedas[pos] > remainder)
		ans=dp(pos+1, remainder);
	else
		ans=max(dp(pos+1, remainder- monedas[pos])+monedas[pos], dp(pos+1, remainder))	;
	return memo[remainder][pos]=ans;
}
int main()
{
	int tested;
	scanf("%d", &tested);
	while(tested--)
	{
		scanf("%d", &n);
		total=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d", &monedas[i]);
			total+=monedas[i];
		}	
		memset(memo, -1, sizeof memo);
		int conj1=dp(0,total/2);
		//cout<<conj1<<" : " <<total<<endl;
		cout<<abs((total-conj1) - conj1 )<<endl;
	}
}
