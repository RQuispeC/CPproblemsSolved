#include <iostream>
#include <cstring>
#define MAX 100005
using namespace std;
int main()
{
	long long a[MAX];
	int n;
	cin>>n;
	for(int j=0;j<n;j++)
	{
		long long aux;
		cin>>aux;
		a[j]=aux;
	}
	int i;
	int lenght=0;
	int mayor=-1;
	for(i=0;i<n;i++)
	{
		if (i>1)
		{
			if(a[i]==a[i-1]+a[i-2]) lenght++;
			else
			{
				if(lenght>mayor) mayor=lenght;
				lenght=2;
			}
		}
		else
		{
			lenght++;
		}
	}
	if(lenght>mayor) mayor=lenght;
	if(n>2)
		cout<<mayor<<endl;
	else 	
		cout<<n<<endl;
}
