#include<bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef long long ll;
int na, nb, a[105], b[105];
int main()
{
	scanf("%d", &na);
	for(int i=0;i<na;i++)
		scanf("%d", &a[i]);
	scanf("%d", &nb);
	for(int i=0;i<nb;i++)
		scanf("%d", &b[i]);	
	sort(a, a+na);
	sort(b, b+nb);
//	cout<<"pas"<<endl;
	int ans=0;
	if(na<nb)
	{
		int pos=0;
		for(int i=0;i<na;i++)
		{
			for(int j=pos;j<nb;j++)
				if(abs(a[i] - b[j]) <= 1)
				{
					ans++;
					pos=j+1;
					break;
					//cout<<i<<" "<<j<<endl;
				}
		}
	}
	else
	{
		int pos=0;
		for(int i=0;i<nb;i++)
		{
			for(int j=pos;j<na;j++)
				if(abs(a[j] - b[i]) <= 1)
				{
					ans++;
					pos=j+1;
					break;
					//cout<<i<<" "<<j<<endl;
				}
		}
	}
	cout<<ans<<endl;
}

