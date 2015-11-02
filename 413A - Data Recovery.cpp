#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<stack>
#include<set>
#include<bitset>
#include<vector>
using namespace std;

int main()
{	
	int a[105];
	int n, m , l, r, left, right;
	cin>>n>>m>>l>>r;
	left=200;
	right=-12;
	for(int i=0;i<m;i++)
	{
		int aux;
		cin>>aux;
		left=min(left, aux);
		right=max(right, aux);
	}
	if(left < l || right>r)
		cout<<"Incorrect"<<endl;
	else
	{
		if(left==l || right==r)
		{
			cout<<"Correct"<<endl;
		}
		else if(n-m>=2)
			cout<<"Correct"<<endl;
		else
			cout<<"Incorrect"<<endl;	
	}	
}

