#include<iostream>
using namespace std;
int main()
{
	int n,feets,inches;
	cin>>n;
	inches=n/3;
	n%=3;
	if(n>=2) inches++;
	feets=inches/12;
	inches%=12;
	cout<<feets<<" "<<inches<<endl;
	return 0;
}
