#include<bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
int main()
{
	int a[310];
	memset(a, -1, sizeof a);
	int n, p;
	cin>>p>>n;
	bool f=1;
	for(int i=0;i<n;i++)
	{
		int xi, pos;
		cin>>xi;
		pos=(xi%p);
		//cout<<xi<<" : "<<p<<" -->"<<pos<<endl;
		if(a[pos]!= -1)
		{
			f=0;
			cout<<i+1<<endl;
			break;
		}
		else
			a[pos]=xi;	
	}
	if(f)
		cout<<-1<<endl;
}

