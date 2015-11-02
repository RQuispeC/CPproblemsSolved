#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n, m, d;
	cin>>n>>d;
	vector < int > a;
	a.clear();
	for(int i=0;i<n;i++)
	{
		int aux;
		cin>>aux;
		a.push_back(aux);
	}
	sort(a.begin(), a.end());
	cin>>m;
	if(m==n)
	{
		int acu=0;
		for(int i=0;i<n;i++)
			acu+=a[i];
		cout<<acu<<endl;	
	}
	if(m<n)
	{
				int acu=0;
		for(int i=0;i<m;i++)
			acu+=a[i];
		cout<< acu<<endl;
	}
	if(m>n)
	{
				int acu=0;
		for(int i=0;i<n;i++)
			acu+=a[i];
		cout<<acu-(m-n)*d<<endl;
	}
}

