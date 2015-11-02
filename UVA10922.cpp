#include <iostream>
#include <sstream>
#include <string.h>
#include <stdio.h>

using namespace std;
int SumaDigitos(string n)
{
	int suma=0;
	for(int i=0;i<n.size;i++)
		suma=suma+(n[i]);
	return suma;
}
int main()
{
    string a;
	cin>>a;
	while(a!="0")
	{
		stringstream aux;
		int grado=0;
		if(suma(a)%9==0)
		{
			grado++;
			aux<<suma(a);
			a=aux.str();
			while(true)
			{
				if(a=="9")
					break;
				else
				{
					grado++;
					aux<<suma(a);
					a=aux.str();
				}
			}
		cout<<a<<"  is a multiple of 9 and has 9-degree "<<grado<<"."<<endl;
		}
		else
			cout<<a<<" is not a multiple of 9."<<endl;	
		cin>>a;	
	}
	return 0;		
}

