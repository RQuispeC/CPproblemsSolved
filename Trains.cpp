#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	if(a%b==0) return b;
	else return gcd(b,a/b);
}
int main()
{
	int a, b;
	long long mcm;
	int dasha=0,masha=0; 
	cin>>a>>b;
	mcm=(a*b)/gcd(a,b);
	dasha+=mcm/a;
	masha+=mcm/b;
	if(a>b) dasha++;
	else masha++;
	if(dasha>masha) cout<<"Dasha"<<endl;
	else if(masha>dasha) cout<<"Masha"<<endl;
	else cout<<"Equal"<<endl;
	cout<<gcd(a,b)<<endl;
	return 0;	
}

