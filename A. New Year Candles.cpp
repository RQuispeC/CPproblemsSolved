#include<iostream>
using namespace std;
int main()
{
	int a, b;
	cin>>a>>b;
	int total=0,  aux=0;
	while(true)
	{
		total+=a;
		a+=aux;
		aux=a%b;
		a=a/b;
		if(a+aux<b) break;
	}
	total+=a;
	cout<<total<<endl;
}
