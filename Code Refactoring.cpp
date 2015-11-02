#include<iostream>
using namespace std;
int factors[4];
int main()
{
	int tested;
	cin>>tested;
	int j=0;
	while(tested--)
	{
		for(int i=0;i<4;i++)
			factors[i]=0;
		int n;
		cin>>n;
		int k=0;
		for(int i=2;i*i<n;i++)
		{
			if(n%i==0)
			{
				factors[k]=i;
				k++;
				factors[k]=n/i;
				k++;
			}
		}
		cout<<"Case #"<<++j<<": "<<n<<" = "<<factors[0]<<" * "<<factors[1]<<" = "<<factors[2]<<" * "<<factors[3]<<endl;
		
	}
	return 0;
}
