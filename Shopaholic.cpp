#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int tested;
	cin>>tested;
	while(tested--)
	{
		int n;
		cin>>n;
		vector < int > v;
		v.clear();
		for(int i=0;i<n;i++)
		{
			int aux;
			cin>>aux;
			v.push_back(aux);
		}
		sort(v.rbegin(), v.rend());
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(i%3==0)
				ans+=v[i-1];
			
		}
		cout<<ans<<endl;
	}
}
