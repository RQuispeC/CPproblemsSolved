#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m , a, b;
	cin>>n>>m>>a>>b;
	double costV= (double)b/(double)m;
	if((double)a <= costV)
	{
		cout<<n*a<<endl;
	}
	else
	{
		cout<<(n/m)*b + min((n%m)*a, b)<<endl;
	}	
}

