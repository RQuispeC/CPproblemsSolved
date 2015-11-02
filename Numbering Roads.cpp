#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int roads,numbers;
	int i=0;
	while(cin>>roads>>numbers && roads>0 && numbers>0)
	{
		cout<<"Case "<<(++i)<<": ";
		if(27*numbers<roads)
			cout<<"impossible"<<endl;
		else
		{
			int ans=roads/numbers;
			if(roads%numbers==0)
				cout<<ans-1<<endl;
			else
				cout<<ans<<endl;	
		}	
	}
	return 0;
}
	