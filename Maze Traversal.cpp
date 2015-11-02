#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<sstream>
#include<stdlib.h>
using namespace std;
int filas, columnas;
vector < string > v;
char dir[]={'N','E','S','W'};
bool validate( pair <int , int > a)
{
	return a.first>=0 && a.second>=0 && a.first<filas && a.second<columnas && v[a.first][a.second]!='*';
}
pair<int , int > mov( pair < int , int > a, int d)
{
	pair <int, int > aux;
	if( dir[d]=='W')
	{
		aux=make_pair(a.first,a.second-1);
		if(!validate(aux)) return a;
		else return aux;
	}
	else
	{	
		if( dir[d]=='E')
		{
			aux=make_pair(a.first,a.second+1);
			if(!validate(aux)) return a;
			else return aux;
		}
		else
		{
			if( dir[d]=='N')
			{
				aux=make_pair(a.first-1,a.second);
				if(!validate(aux)) return a;
				else return aux;
			}
			else //if( dir[d]=='S')
			{
				aux=make_pair(a.first+1,a.second);
				if(!validate(aux)) return a;
				else return aux;
			}
		}
	}
}
int main()
{
	string aux;
	getline(cin, aux);
	int tested = atoi(aux.c_str());
	bool blank=false;
	while(tested--)
	{
		if(blank) cout<<endl;
		blank=true;
		v.clear();
		cin>>filas>>columnas;
		getline(cin,aux);
		for(int i=0;i<filas;i++)
		{	
			getline(cin,aux);
			v.push_back(aux);
		}
		int aux1,aux2;
		cin>>aux1>>aux2;
		pair < int, int > inicio=make_pair(aux1-1, aux2-1);
		if(v[inicio.first][inicio.second]=='*')
		{
			cout<<inicio.first+1<<" "<<inicio.second+1<<" "<<'N'<<endl;;
			return 0;
		}
		int d=0;
		string s;
		bool end=false;
		while(!end)
		{
			cin>>s;
			if(s[s.size()-1]=='Q') 
			{
				end=true;
			}
			for(int i=0;i<s.size();i++)
			{
				if(s[i]=='L')
				{
					d=(d+3)%4;
				}
				else
				{
					if(s[i]=='R')
					{
						d=(d+1)%4;
					}
					else//movemos el robot
					{
						if(s[i]=='F')
							inicio=mov(inicio,d);
						else
							end=true;	
					}
				}
			}
		}
		cout<<inicio.first+1<<" "<<inicio.second+1<<" "<<dir[d]<<endl;
	}
	return 0;
}
