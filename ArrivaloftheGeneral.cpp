#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
        int max=0, min=101, posMax, posMin; 
	for(int i=0;i<n;i++)
	{
		int aux;
		cin>>aux;
		if(aux>max)//obtenemos la posicion del mayor de indice menor
		{
			max=aux;
			posMax=i;
		}
		if(aux<=min)//obtenemos la posicion del menor de indice mayor
		{
			min=aux;
			posMin=i;
		}	
	}
	int ans=posMax;//movemos el maximo adelante
	ans+=(n-posMin-1);//movemos el minimo atras
	if(posMax>posMin)  ans--;
	cout<<ans<<endl;	 		
	return 0;
}

