#include<bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
vi a, b;
int comunes=0;
bool iguales(vi x, vi y)
{
	int cont=0;
	for(int i=0;i<x.size();i++)
	{
		if(x[i]==y[i])
			cont++;
	}
	if(cont==x.size())
		return true;
	return false;	
}
bool contiene(vi x, vi y)
{	
	for(int i=0;i<y.size();i++)
	{
		//int ind=binary_search(x.begin(), x.end(), y[i] );
		//cout<<y[i]<<" : "<<ind<<endl;
		if(!binary_search(x.begin() , x.end(), y[i] ))
			return false;
	}
	return true;
}
bool disjoint(vi x, vi y)
{
	int con=0;
	for(int i=0;i<y.size();i++)
	{
		//int ind=binary_search(x.begin() , x.end(), y[i] );
		//cout<<y[i]<<" : "<<ind<<endl;
		if(binary_search(x.begin() , x.end(), y[i] ))
		{
			con++;
		}
	}
	if(con==0)
		return true;
	else
		return false;	
}
int main()
{
	string na,nb;
	while(getline(cin, na))
	{
		getline(cin, nb);
		stringstream ina(na);
		stringstream inb(nb);
		a.clear(), b.clear();
		int aux;
		while(ina>>aux)
		{
			a.push_back(aux);
		}
		while(inb>>aux)
		{
			b.push_back(aux);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		//cout<<a.size()<<" :"<<b.size()<<
		if(a.size() == b.size())
		{
			if(iguales(a, b))
				cout<<"A equals B"<<endl;
			else
			{
				if(disjoint(a,b))
					cout<<"A and B are disjoint"<<endl;
				else
					cout<<"I'm confused!"<<endl;
			}		
		}
		else if(a.size() > b.size())
			{
				if(contiene(a, b))
					cout<<"B is a proper subset of A"<<endl;
				else 
				{
					if(disjoint(a,b))
						cout<<"A and B are disjoint"<<endl;
					else
						cout<<"I'm confused!"<<endl;
				}			
			}
		else //if(a.size() < b.size())
			{
				if(contiene(b,a))
					cout<<"A is a proper subset of B"<<endl;
				else
				{
					if(disjoint(a,b))
						cout<<"A and B are disjoint"<<endl;
					else
						cout<<"I'm confused!"<<endl;
				}		
			}
	}
}


