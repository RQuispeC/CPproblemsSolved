#include<iostream>
using namespace std;

int main()
{
	int tested;
	cin>>tested;
	while(tested--)
	{
		int x,y;
		cin>>x>>y;
		if(y%x==0)
			cout<<x<<" "<<y<<endl;
		else
			cout<<"-1"<<endl;
		
	}
	return 0;
}

