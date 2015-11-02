#include <bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
typedef long long ll;
int main()
{
	int v[10];
	memset(v,0,sizeof v);
	int k;
	string a[4];
	cin>>k;
	for(int i=0;i<4;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(a[i][j]>='0' && a[i][j] <='9')
			{
				int num=a[i][j]-'0';
				v[num]++;
			}
		}
	}
	bool ans=1;
	k=k*2;
	//cout<<"jas : "<<k<<endl;
	for(int i=0;i<10;i++)
	{
		//cout<<i<<" -->  "<<v[i]<<endl;
		if(v[i] > k)
			ans=0;
	}
	if(ans)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;		
}

