#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	bool ans=true;
	int tienen=0;
	for(int i=0;i<n;i++)
	{
		int aux;
		cin>>aux;
		if(aux-25>tienen)
		{
			ans=false;
			break;
		}
		else
		{
			 tienen+=25;
					
		}	

	}
	if(ans)
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
	return 0;
}

