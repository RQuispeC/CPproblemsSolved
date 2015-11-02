#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int swapLong(int i, int j)
{
	int vec=0;
	for(int k=i;k<j;k++)
	{	
		if(s[k] != s[k+1])
		{
			swap(s[k],s[k+1]);
			vec++;
		}	
	}	
	return vec;
}
int main()
{
	int a, b;
	while(cin>>a>>b>>s)
	{
		ll ans=0ll;
		int i=0, j=s.size()-1;
		while(i<j)
		{	
			if(s[i]=='B' && s[j]=='B')
				i++;
			else
			{
				if(s[i]=='B' && s[j]=='W')
					i++, j--;
				else
				{
					if(s[i]=='W' && s[j]=='B') //swap
					{
						ll cost=ll(a-b)*ll(j-i);
						if( a < cost ) //swap simple
						{
							ans+=ll(a);
							swap(s[i], s[j]);
						}
						else
						{
							int ve=swapLong(i,j);
							ans+=(ll(ve)*ll(a-b));
						}
					}
					else //s[i]=='W' && s[j]=='W'
						j--;	
				}
			}
		}
		cout<<ans<<endl;
	}
}

