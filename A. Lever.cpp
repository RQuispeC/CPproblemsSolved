#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string a;
	cin>>a;
	long long  left=0 , right=0;
	int k=-1;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='^')
		{
			k=i;
			break;
		}	
	}
	int aux=0;
	for(int i=k;i>=0;i--)
	{
		if((int)a[i]>=48 && (int)a[i]<=57)
		{
			left=left+((a[i]-'0')*aux);
		}
		aux++;
	}
	aux=0;
	for(int i=k;i<a.size();i++)
	{
		if((int)a[i]>=48 && (int)a[i]<=57)
		{
			right=right+((a[i]-'0')*aux);
		}
		aux++;
	}
	if(left==right)
		cout<<"balance"<<endl;
	else if(left>right)
		cout<<"left"<<endl;
	else cout<<"right"<<endl;	
}
