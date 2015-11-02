#include<iostream>
#include<cmath>
#define MAX 100020
using namespace std;
long long a [MAX];
int main()
{
	int n;
	while(cin>>n)
	{
		int ans=0;
		for(int k=0;k<n;k++)
			cin>>a[k];
		a[n]=-100;	
		int i=0,j=0;
		//WRONG ANSWER
		while(true)
		{
			if(j+1==n) 
			{
				ans=max(ans, j-i+1);
				break;
			}	
			if(a[j]<a[j+1])
				j++;
			else
			{
				ans=max(ans, j-i+1);
				i=j+1;
				j++;
			}	
		}
		cout<<ans<<endl; 		
	}
}

