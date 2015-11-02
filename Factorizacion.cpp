#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAX 10000000
using namespace std;
int p[MAX];
vector < int > f;
int N;
void cribaExtended(int k)
{
	for(int i=4 ; i<=k ; i+=2)
		p[i]=2;
	for(int i=3 ; i*i<=k ; i+=2)
		if(!p[i])
			for(int j=i*i ; j<=k ; j+=i*2)
				p[j]=i;
	/*
	esta criba almacena un factor primo para cada numero
	representa con " 0 " los # primos
	*/			
}
int fact(int n)
{
	int F=0;
	while(p[n])
	{
		f.push_back(p[n]);
		n/=p[n];
	}
	if(n>1)
		f.push_back(n);
	return F;
	/*
		para factorisar aprovechamos que ya tenemos un afctor pimo de cada numero y  
		almacenamos en "f" todos los factores de de N  
	*/
}

int main()
{
	f.clear();
	memset(p,0,sizeof(p));
	cin>>N;
	cribaExtended(N);
	for(int i=0;i<=N;i++)
		//if(!p[i])
		cout<<i<<"   "<<p[i]<<" "<<endl;
	cout<<"--------------------------"<<endl;
	fact(N);
	for(int i=0;i<f.size();i++)
		cout<<f[i]<<" "<<endl;
	return 0;
}

