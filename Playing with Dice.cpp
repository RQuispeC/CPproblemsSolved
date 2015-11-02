#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a, b, first=0, second=0, draw=0;
	cin>>a>>b;
	for(int i=1;i<=6;i++)
	{
		int aux1=abs(i-a);
		int aux2=abs(i-b);
		if(aux1==aux2)
			draw++;
		else if(aux1>aux2) second++;
		else first++;		
	}
	cout<<first<<" "<<draw<<" "<<second<<endl;
}
