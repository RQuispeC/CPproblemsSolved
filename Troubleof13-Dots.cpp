#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct elemento
{
	int beneficio, int costo;
	elemento()
	{
		beneficio=0;
		costo=0;
	}
	elemento(int ben , int cos)
	{
		beneficio=ben;
		costo=cos;
	}
};
int main()
{
	int m, n;
	while(cin>>m>>n)
	{
		vector < elemento > a; 
		a.clear();
		for(int i=0;i<n;i++)
		{
			int ben,cos;
			cin>>ben>>cos;
			a.push_back(elemento(ben,cos));
		}
		for(int i=0;i<n;i++)
		{
			cout<<a[i].beneficio()<<"    "<<a[i].costo()<<endl;
		}
		
	}
}

