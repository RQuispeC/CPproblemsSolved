#include<bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
bool work( vi x)
{
	double me=(double)(x[0]+ x[1] +x[2] + x[3])/4.;
	double me2=(double)(x[1] + x[2])/2.;
	double me3=(double)(x[3]-x[0]);
	bool f= me==me2 && me2==me3 && x[0]>=1 && x[1]>=1 && x[2]>=1 && x[3]>=1;
	f=f && x[0]<=x[1] && x[1]<=x[2] && x[2]<=x[3];
	return f;
}
int main()
{
	int n;
	vi v;
	v.clear();
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int aux;
		cin>>aux;
		v.push_back(aux);
	}	
	sort(v.begin(), v.end());
	if(n==0)
	{
		cout<<"YES"<<endl;
		cout<<1<<endl<<1<<endl<<3<<endl<<3<<endl;
	}
	if(n==1)
	{
		cout<<"YES"<<endl;
		cout<<v[0]<<endl<<3*v[0]<<endl<<3*v[0]<<endl;
	}
	if(n==4)
	{
		if(work(v))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	if(n==3)
	{
		for(int i=1;i<=1e6;i++)
		{
			vi aux (v.begin(), v.end());
			aux.push_back(i);
			sort(aux.begin(), aux.end());
			if(work(aux))
			{
				cout<<"YES"<<endl;
				cout<<i<<endl;
				return 0;
			}
		}
		cout<<"NO"<<endl;
	}
	if(n==2)
	{
		int c=4*v[0]-v[1];
		int d=3*v[0];
		v.push_back(c), v.push_back(d);
		sort(v.begin(), v.end());
		if(work(v))
		{
			cout<<"YES"<<endl;
			cout<<c<<endl<<d<<endl;
		}	
		else
			cout<<"NO"<<endl;
	}
	
}

