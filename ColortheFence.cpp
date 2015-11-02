#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
string f(string b, int litros, int menor,int posMen)
{
	if(litros==0  || menor>litros)
	{
		return b;
	}
	else
	{
		posMen++;
		int aux=litros/menor;
		litros%=menor;
		for(int i=0;i<aux;i++)
		{
			b.push_back(posMen+'0');
		}
		v[posMen-1]=100001;
		for(int i=0;i<9;i++)
		{
			if(v[i]<=menor)
			{ 
				menor=v[i];
				posMen=i;
			}
		}
		 return f(b,litros, menor, posMen);
	}
		 
}
int main()
{
	int litros, aux;
	cin>>litros;
	int menor=100001, posMen=-1;
	v.clear();
	for(int i=0;i<9;i++)
	{
		cin>>aux;
		v.push_back(aux);
		if(aux<=menor)
		{
			menor=aux;
			posMen=i;
		}
	}
	string ans=f("",litros, menor, posMen);
	if(ans!="")
		cout<<ans<<endl;
	else
		cout<<"-1"<<endl;	
	return 0;
}

