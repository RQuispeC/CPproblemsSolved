#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
int n, a[MAX];
bool sol()
{
	stack < int > s;
	vector < int > v;
	v.clear();
	int tok=n;
	for(int i=n-1;i>=0;i--)
	{
		s.push(a[i]);
		while(s.top()==tok)
		{
			v.push_back(s.top());
			tok--;
			s.pop();
			if(s.empty()) break;
		}
	}
	while(!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	reverse(v.begin(), v.end());
	for(int i=0;i<v.size();i++)
		if(v[i] -1 != i)
			return 0;
	return 1;		
}
int main()
{
	while(cin>>n)
	{
		if(n==0) break;
		while(1)
		{
			bool f=0;
			scanf("%d", &a[0]);
			if( a[0]==0 ) break;
			for(int i=1;i<n;i++)
			{
				scanf("%d", &a[i]);
			}
			if(sol())
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;	
		}
		cout<<endl;
	}
}

