#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int x,y,a;
	cin>>x>>y;
	if(x>0 && y>0) //primer cuadrante m=-1
	{
		a=x+y;
		cout<<0<<" "<<a<<" "<<a<<" "<<0<<endl;
	}
	if(x<0 && y>0) //segundo cuadrante m=1
	{
		a=y-x;
		cout<<(-1*a)<<" "<<0<<" "<<0<<" "<<a<<endl;
	}
	if(x<0 && y<0) //tercer cuandrante m=-1
	{
		a=x+y;
		cout<<a<<" "<<0<<" "<<0<<" "<<a<<endl;
	}
	if(x>0 &&  y<0) //cuarto cuadrante m=1
	{
		a=y-x;
		cout<<0<<" "<<a<<" "<<(-1*a)<<" "<<0<<endl;
	}
}

