#include<iostream>
#include<cmath>
#define MAX 2000000000
using namespace std;
int  main()
{
	int left = -MAX;
	int right=MAX;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string sig, ans;
		int x;
		cin>>sig>>x>>ans;
		if(sig==">")
		{
			if(ans=="Y")
				left=max(left,x+1);
			else
				right=min(right, x);		
		}
		else if(sig=="<")
		{
			if(ans=="Y")
				right=min(right,x-1);
			else
				left=max(left, x);	
		}
		else if(sig==">=")
		{
			if(ans=="Y")
				left=max(left,x);
			else
				right=min(right, x-1);
		}
		else // sig=="<="
		{
			if(ans=="Y")
				right=min(right,x);
			else
				left=max(left, x+1);
		}
		
	}
	if(left>right)	
		cout<<"Impossible"<<endl;
	else
		cout<<left<<endl;	
}

