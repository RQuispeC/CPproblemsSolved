#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string aux;
string a,b;
int posicion(int j, int inicio)
{
	int posicion=-1;
	for(int i=inicio;i<b.size();i++)
	{
		if(a[j]==b[i])
		{
			posicion=i;
			break;
		}
	}
	return posicion;
}
int main()
{
	while(cin>>a && cin>>b)
	{
		aux="";
		int posi=0;
		for(int i=0;i<a.size();i++)
		{
			int p=posicion(i, posi);
			if(p>=0)
			{
				aux+=b[p];
				posi=p+1;
			}
			else
				break;
		}
		if(aux==a)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
