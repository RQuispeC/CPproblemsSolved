#include <iostream>
#include <vector>
#include <cstring>
#define MAXN 100
#define MAXW 1000
using namespace std;
int profit[MAXN];
int weight[MAXN];
int dp[MAXN][MAXW];
int N,W;
int f(int a,int b)
{
	if(a>=N)return 0;
	if(dp[a][b]!=-1)return dp[a][b];
	int ans=0;
	if(b+weight[a]<=W)
		ans=max(ans,f(a+1,b+weight[a])+profit[a]);
	ans=max(ans,f(a+1,b));
	return dp[a][b]=ans;
}
vector<int> sol;
void getsol(int a,int b){
	if(a>=N)return;
	if(b+weight[a]<=W){
		if(f(a+1,b+weight[a])+profit[a]>f(a+1,b))
		{
			sol.push_back(a);
			getsol(a+1,b+weight[a]);
		}
		else
			getsol(a+1,b);
	}else
		getsol(a+1,b);
}
int main()
{
	cin>>N>>W;
	for(int i=0;i<N;i++)
		cin>>profit[i]>>weight[i];
	memset(dp,-1,sizeof dp);
	cout<<"maximo beneficio "<<f(0,0)<<endl;
	getsol(0,0);
	cout<<"elementos"<<endl;
	for(int i=0;i<sol.size();i++)
		cout<<(sol[i]+1)<<endl;
}
