#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int tested;
	cin>>tested;
	for(int t=1;t<=tested;t++)
	{
		cout<<"Case "<<t<<": ";
		int n, p ,q;
		cin>>n>>p>>q;
		vector <int > v;
		v.clear();
		for(int i=0;i<n;i++)
		{
			int aux;
			cin>>aux;
			v.push_back(aux);
		}
		int ans=0;
		int to=0;
		int i=0;
		while(true)
		{
			if(i==v.size()|| to+v[i]>q || ans+1>p ) break;
			to+=v[i];
			ans++;
			i++;
		}
		cout<<ans<<endl;
	}
}
