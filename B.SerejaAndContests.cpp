#include<iostream>
#include<cstring>
#define MAX 4010
using namespace std;
int A[MAX];
int n,k;
int main()
{
	memset (A, 0, sizeof A);
	cin>>n>>k;
	n--;
	for(int i=0;i<k;i++)
	{
		int id,x,y;
		cin>>id;
		if(id==1)
		{
			cin>>x>>y;
			A[x-1]=2;
			A[y-1]=1;
		}
		else
		{
			cin>>x;
			A[x-1]=2;
		}
	}
	int Min=0;
	int Max=0;
	for(int i=0;i<n;i++)
	{
		if(A[i]==0) Max++;
	}
	for(int i=0;i<n;i++)
	{
		int j=i+1;
		if(j<n && A[i]==0 && A[j]==0)
		{
			Min++;
			A[i]=-1;
			A[j]=-1;
		}
		else if(A[i]==0) 
		{
			Min++;
			A[i]=-1;
		}
	}
	cout<<Min<<" "<<Max<<endl;
}

