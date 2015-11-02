#include <iostream>
#include <string.h>
#include<algorithm>
#include<cstring>
using namespace std;
int indice(string cadena,char c )
{
	int posision=-1;
	for(int i=0;i<cadena.size();i++)
	{
		if(cadena[i]==c)
		{
			posision=i;
			break;
		}
	}
	return posision;
}
int main()
{
	string num ="0123456789";
	string real="OIZEASGTBP";
	int n;
	cin>>n;
	string a;
	getline(cin,a);
		while(getline(cin,a))
		{
			if(a=="")
				break;
			string b="";
			for(int i=0;i<a.size();i++)
			{
				int in=indice(num,a[i]);
				if(in>=0)
					b+=real[in];
				else 
					b+=a[i];
			}
			cout<<b<<endl;	
		}

}
