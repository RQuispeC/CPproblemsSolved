#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector <int> a;
	int x,y,z;
	while(cin>>x>>y>>z && x!=0 && y!=0 && z!=0)
	{
		a.clear();
		a.push_back(x);
		a.push_back(y);
		a.push_back(z);
		sort(a.begin(),a.end());
		if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2])
			cout<<"right"<<endl;
		else
			cout<<"wrong"<<endl;	
		
	}
	return 0;
}
