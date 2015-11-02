#include<iostream>
#include<math.h>
using namespace std;
int find(char c, string s)
{
	for(int i=0;i<s.size();i++)
		if(s[i]==c) return i;
	return -1;	
}
int gsd(int x,int y)
{
	if(x%y==0) return y;
	else
		return gsd(y,x%y);
}
int numer(float a, int n, int j)
{
	return (int)pow(10,n+j)*a - (int)pow(10,n)*a;
}
int denom(float a, int n, int j)
{
	return (int)pow(10,n+j)-(int) pow(10,n);
}
int  cifrasNoPeriodicas(float a, int n)
{
	string num=string(n);
	return num.size()-n-1-find('.',num);
}

int main()
{
	int n;
	while(cin>>n && n!=-1)
	{
		float a;
		cin>>a;
		int j=cifrasNoPeriodicas(a,n);
		int num=numer(a,n,j);
		int den=denom(a,n,j);
		int g=gsd(den,num);
		num/=g;
		den/=g;
		cout<<num<<"/"<<den<<endl;
	}
	return 0;
}
