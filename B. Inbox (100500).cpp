#include<bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
typedef long long ll;
int main()
{
	vi pos;
	pos.clear();
	int n, ans=0, aux;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>aux;
		if(aux)
			pos.push_back(i);
	}
	if(pos.size()<=1)
		cout<<pos.size()<<endl;
	else
	{
		ans=1;
		for(int i=0;i<pos.size()-1;i++)
		{
			int j=i+1;
			if(pos[j]-pos[i]==1)
				ans++;
			else
				ans+=2;	
		}
		cout<<ans<<endl;
	}		
}

