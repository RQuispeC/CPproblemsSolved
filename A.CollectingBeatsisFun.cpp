#include<iostream>
#include<cstring>
using namespace std;
string a[4];
int acum[10];
int main()
{
	memset( acum, 0, sizeof acum);
	int k;
	cin>>k;
	k*=2;
	for(int i=0;i<4;i++)
		cin>>a[i];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(a[i][j]!='.')
			{
				acum[a[i][j]-'0']++;
			}	
		}
	}
	bool ans=true;
	for(int i=0;i<10;i++)
		if(acum[i]>k) ans=false;
	if(ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;		
}

