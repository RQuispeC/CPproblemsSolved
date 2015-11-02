#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring> 
using namespace std;
int precios [25][25];
int buy [210][25];
int m,c;
int dp(int money, int g)
{
	if(money<0) return -10000000; // el dinero es insuficiente
	if(g==c) return m - money;//se puso comprar todo, tenemos una posible respuesta!!!
	if(buy[money][g]!=-1) return buy[money][g];
	int ans=-1;
	for(int i=1;i<=precios[g][0];i++)
		ans=max(ans,dp(money-precios[g][i], g+1));
	return buy[money][g]=ans;	//memorisacion
}
int main()
{
	int tested;
	cin>>tested;
	while(tested--)
	{
		cin>>m>>c;
		for(int i=0;i<c;i++)
		{
			cin>>precios[i][0];
			for(int j=1;j<=precios[i][0];j++)
				cin>>precios[i][j];
		}
		memset(buy,-1, sizeof buy);
		int ans=dp(m,0);
		if(ans<0)
			cout<<"no solution"<<endl;
		else 
			cout<<ans<<endl;		
		  
	}
}

