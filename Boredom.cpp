#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX 100005
using namespace std;
long long dp[MAX];
long long acumular[MAX];
int main(){
	int n,x;
	cin>>n;
	memset(dp,0,sizeof(dp));
	memset(acumular,0,sizeof(dp));
	int mayor=0;
	for(int i=0; i<n; i++){
		cin>>x;
		acumular[x]++;
		mayor=x>mayor?x:mayor;
	}
	for(int i=0; i<=mayor; i++)
		acumular[i]=acumular[i]*i;
	dp[0]=0;
	long long ans=0;
	for(int i=1; i<=mayor; i++){
		if(i>1)
			dp[i]=max(dp[i-1],acumular[i]+dp[i-2]);
		else
			dp[i]=max(acumular[i],dp[i-1]);	
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}

