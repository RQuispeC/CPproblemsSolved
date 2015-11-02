#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n, d, r;
	while(cin>>n>>d>>r && n!=0 && d!=0 && r!=0)
	{
		vector <int> m;
		vector <int> t;
		for(int i=0;i<n;i++)
		{
			int aux;
			cin>>aux;
			m.push_back(aux);
		}
		for(int i=0;i<n;i++)
		{
			int aux;
			cin>>aux;
			t.push_back(aux);
		}
		sort(m.begin(), m.end());	
		sort(t.rbegin(), t.rend());
		int ans=0;
		for(int i=0;i<n;i++)
		{
			int aux=m[i]+t[i];
			if(aux>d)
				ans+=aux-d;
		}
		cout<<ans*r<<endl;
	}
}
