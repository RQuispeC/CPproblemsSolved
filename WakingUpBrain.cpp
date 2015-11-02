#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX 26
using namespace std;
int sleeped ;
bool wake [MAX];
bool brain[MAX][MAX];
int f (int anio, int despiertos)
{
	if(despiertos==sleeped )
		return anio;
	else
	{
		vector  < int > despertados;
		despertados.clear(); 
		for(int i=0;i<MAX;i++)
		{
			int conected=0;
			if(!wake[i])
			for(int j=0;j<MAX;j++)
			{
				if(brain[i][j] && wake[j])
					conected++;
			}
			if(conected>=3)
				despertados.push_back(i);
		}
		if(despertados.size()==0) return -1;//no se desperto ninguna area nueva, por ende no se despertara nada más
		else
		{ //despertar nuevas areas
			for(int i=0;i<despertados.size();i++)
				wake[despertados[i]]=true;
			return f(anio+1,despiertos+despertados.size());
		}	
	}	
}
int main()
{
	memset(wake ,false,sizeof wake);
	memset(brain,false,sizeof brain);
	cin>>sleeped;
	int conex;
	cin>>conex;
	string aux;
	cin>>aux;
	for(int i=0;i<aux.size();i++)
		wake[aux[i]-'A']=true;
	for(int i=0;i<conex;i++)
	{
		cin>>aux;
		int a=aux[0]-'A';
		int b=aux[1]-'A';
		brain[a][b]=true;
		brain[b][a]=true;
	}
	int anio=f(0,3);
	if(anio>0)
		cout<<"WAKE UP IN, "<<anio<<", YEARS"<<endl;
	else 
		cout<<"THIS BRAIN NEVER WAKES UP"<<endl;		
}

