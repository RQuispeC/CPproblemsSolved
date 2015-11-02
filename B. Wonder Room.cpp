#include<bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
typedef unsigned long long ll;
int main()
{
	ll a,b,n;
	cin>>n>>a>>b;
	if(a*b >= 6ll*n)
	{
		cout<<a*b<<endl<<a<<" "<<b<<endl;
	}
	else
	{
		ll area=6*n;
		vector < ll > div;
		div.clear();
		for(ll i=1ll;i*i<=area;i++)
		{
			if(area % i ==0)
			{
				div.push_back(i);
			}
		}
		for(int i=0;i<div.size();i++)
		{
			if(div[i] >= a && area/div[i] >=b   )
			{
				//cout<<"as"<<endl;
				cout<<area<<endl;
				cout<<div[i]<<" "<<	area/div[i]<<endl;
				return 0;
			}
			if(div[i] >= b && area/div[i] >=a)
			{
				cout<<area<<endl;
				cout<<area/div[i]<<" "<<div[i]<<endl;
				return 0;
			}
		}
		//cout<<a<<" * "<<b<<endl;
		//cout<<"llega"<<endl;
		ll ar1 = a*((area / a) + (area % a > 0 ));
		ll ar2 = b*((area / b) + (area % b > 0 ));
		//cout<<ar1<<" "<<ar2<<endl;
		ll ans =min (ar1, ar2);
		for(ll i = area +1 ;i <= min(ar1, ar2);i++)
		{
			//cout<<i<<" : "<<endl;
			for(int j=min(a,b);j*j<= i;j++)
			{
				if(i % j == 0)
				{
					//cout<<j<<" : "<<i/j<<endl;
					if( a < b && i/j >= b)
					{
						cout<<i<<endl;
						cout<<j<<" "<<i/j<<endl;
						return 0;	
					}
					else if(b <= a &&  i/j >= a)
					{
						cout<<i<<endl;
						cout<<i/j<<" "<<j<<endl;
						return 0;
					}
				}
			}
		}
		if(ans == ar1 )
		{
			cout<<ar1<<endl;
			cout<<a<<" "<<(area / a) + (area % a> 0 )<<endl;
		}	
		else
		{
			cout<<ar2<<endl;
			cout<<(area / b) + (area % b > 0 )<<" "<<b<<endl;
		}			
	}	
}

