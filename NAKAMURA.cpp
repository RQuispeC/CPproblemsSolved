#include<iostream>
#include<cmath>
using namespace std;
double f(double x)
{
	return tan(x);
}
double derivadaAnalitica(double x)
{
	double aux=1/cos(x);
	return aux*aux;
}
double derI (double x, double h)
{
	return (f(x)-f(x-h))/h;
}
double derII (double x, double h)
{
	return (f(x+h)-f(x))/h;
}
double derIII (double x, double h)
{
	return (f(x+h)-f(x-h))/(2.0*h);
}
double derIV (double x, double h)
{
	return (3.0*f(x)-4.0*f(x-h)+f(x-2.0*h))/(2.0*h);
}
double derV (double x, double h)
{
	return (-f(x+2.0*h)+4.0*f(x+h)-3.0*f(x))/(2.0*h);
}
double rx(double ana, double expe)
{
	return abs((ana-expe)/ana)*100.0;
}
double segundaDerivadaI(double x, double h)//Dif. ATRAS
{
	return (f(x)-2.0*f(x-h)+f(x-2.0*h))/(h*h);
}
double segundaDerivadaII(double x, double h)//Dif. CENTRAL
{
	return (-2*f(x)+f(x-h)*f(x+h))/(h*h);
}
double segundaDerivadaIII(double x, double h)//Dif. ADELANTE
{
	return (f(x+2.0*h)-2.0*f(x+h)+f(x))/(h*h);
}
int main()
{
	double x, h;
	while(cin>>x>>h)
	{
		cout<<"X : "<<x<<endl;
		cout<<"h : "<<h<<endl;
		double ana=derivadaAnalitica ( x);
		cout<<"Valor Analítico : "<< ana<<endl;
		cout<<"derivada 1 :  "<<derI(x, h)<<endl;
		cout<<"ERROR : "<<rx(ana, derI(x, h))<<endl;
		cout<<"derivada 2 :  "<<derII(x, h)<<endl;
		cout<<"ERROR : "<<rx(ana, derII(x, h))<<endl;
		cout<<"derivada 3 :  "<<derIII(x, h)<<endl;
		cout<<"ERROR : "<<rx(ana, derIII(x, h))<<endl;
		cout<<"derivada 4 :  "<<derIV(x, h)<<endl;
		cout<<"ERROR : "<<rx(ana, derIV(x, h))<<endl;
		cout<<"derivada 5 :  "<<derV(x, h)<<endl;		
		cout<<"ERROR : "<<rx(ana, derV(x, h))<<endl;
	}
}

