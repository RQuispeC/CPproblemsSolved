#include<iostream>
using namespace std;
int GCD(int x, int y )
{
  	if(y==0) return x;
	return GCD(y,x%y);
}
pair< int,int > eGCD(int x, int y)
{
	if(y==0)
	{
		return make_pair(1,0);	
	}
	else
	{
		pair < int , int > ans=eGCD(y,x%y);
		return make_pair(ans.second, ans.first-ans.second*(x/y));
	}
}

int main()
{
	int n, m;
	cin>>n>>m;
	cout<<GCD(n,m)<<endl;
	pair < int , int > a=eGCD(n,m);
	cout<<a.first<<"   "<<a.second<<endl;
	return 0;
}

