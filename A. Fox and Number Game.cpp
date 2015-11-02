#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	if(b==0 ) return a;
	else return gcd(b,a%b);
}
int main()
{
	int n;
	cin>>n;
	int aux;
	cin>>aux;
	int ans=aux;
	for(int i=1;i<n;i++)
	{
		cin>>aux;
		ans=gcd(ans,aux);
	}
	cout<<ans*n<<endl;
}
