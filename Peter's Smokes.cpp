#include<iostream>
using namespace std;
int main()
{
	int cigarretes,needed;
	while(cin>>cigarretes>>needed)
	{
		int butts=cigarretes;
		int smoked=cigarretes;
		while(butts>=needed)
		{
			smoked+=butts/needed;
			butts=butts/needed+butts%needed;
		}
		cout<<smoked<<endl;
	}
	return 0;
}
