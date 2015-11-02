#include<iostream>
#include<cstring>
#define MAX 110
using namespace std;
int A[MAX];
int main()
{
	memset(A, -1, sizeof A);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		for(int j=a;j<b;j++)
			A[j]=i;
	}
	int ans=0;
	for(int i=0;i<MAX;i++)
		if(A[i]==0)
			ans++;
	cout<<ans<<endl;		
}

