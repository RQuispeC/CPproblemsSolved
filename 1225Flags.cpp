#include<iostream>
#define MAX 46
using namespace std;
long long A[MAX];
int main()
{
	A[1]=2ll;
	A[2]=2ll;
	for(int i=3;i<MAX;i++)
		A[i]=A[i-1]+A[i-2];
	int n;
	cin>>n;
	cout<<A[n]<<endl;	
}

