#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
typedef unsigned long long ll;
int player[MAX], n , m ,  k, fedor;
string bin(int x)
{
	string ans="";
	while(x>0)
	{
		int re=x%2;
		x=x/2;
		ans+= (char)('0'+re);
	}
	string fin;
	for(int i=ans.size()-1;i>=0 ;i--)
		fin+=ans[i];
	return fin;
}
bool  valid(int x)
{
	int dif = x xor fedor;
	int tot=0; 
	while(dif>0)
	{
		if(1 & dif)
			tot++;
		dif = dif>>1 ;
	}
	if(tot<=k)
		return 1;
	return 0;	
}
int main()
{
	scanf("%d %d %d", &n, &m ,&k);
	for(int i=0;i<m;i++)
		scanf("%d", &player[i]);
	scanf("%d", &fedor);
	int ans=0;
	for(int i=0;i<m;i++)
	{
		//cout<<bin(fedor)<<endl<<bin(player[i])<<endl;
		if(valid(player[i]))
			ans++;
	}
	printf("%d\n",ans);
	
}

