#include<iostream>
#include<cstring>
#define MAX 125
using namespace std;
int letrasA[MAX];
int letrasB[MAX];
int main()
{
	int tested;
	cin>>tested;
	while(tested--)
	{
		memset(letrasA, 0, sizeof letrasA);
		memset(letrasB, 0, sizeof letrasB);
		string a, b;
		cin>>a>>b;
		for(int i=0;i<a.size();i++)
			letrasA[a[i]]++;
		for(int i=0;i<b.size();i++)
			letrasB[b[i]]++;
		long long ans=0;
		for(int i=45;i<MAX;i++)
		{
			if(letrasA[i]<letrasB[i])
				ans+=letrasA[i];
			else
				ans+=letrasB[i];
		}
		cout<<ans<<endl;		
	}
}
