#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	int b[n];
	for(int i=0;i<n;i++)
	{
		int aux;
		scanf("%d", &aux);
		a[i]=aux;
		b[i]=aux;
	}
	sort(b, b+n);
	int tot=0;
	for(int i=0;i<n;i++)
		if(a[i]!=b[i]) tot++;
	if(tot<=2)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;		
}
