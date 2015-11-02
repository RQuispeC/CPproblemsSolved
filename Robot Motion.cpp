#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX 1000000
using namespace std;
int filas, columnas,inicio;
vector <string> a;
bool validate(int fi, int co)
{
	return fi>=0 && co>=0 && fi<filas && co<columnas;
}
pair<int , int > fun( int f ,int c)
{
	if(!validate (f,c )) return make_pair(-1,-1);
	else if( a[f][c]=='W')
		return make_pair(f,c-1);
	else if( a[f][c]=='E')
		return make_pair(f,c+1);
	else if( a[f][c]=='N')
		return make_pair(f-1,c);
	else if( a[f][c]=='S')
		return make_pair(f+1,c);
}
int ans1( int f ,int c)
{
	if(!validate (f,c )) return 0;
	else if( a[f][c]=='W')
		return 1+ans1(f,c-1);
	else if( a[f][c]=='E')
		return 1+ans1(f,c+1);
	else if( a[f][c]=='N')
		return 1+ans1(f-1,c);
	else if( a[f][c]=='S')
		return 1+ans1(f+1,c);
}
int main()
{
	while(cin>>filas>>columnas>>inicio)
	{
		if(filas==0 && columnas==0 && inicio==0) break;
		a.clear();
		for(int i=0;i<filas;i++)
		{
			string aux;
			cin>>aux;
			a.push_back(aux);
		}
		pair<int , int > tortuga=fun(0,inicio-1);
		pair<int , int > liebre=fun(fun(0,inicio-1).first , fun(0,inicio-1).second);
		while(tortuga!=liebre && liebre !=make_pair(-1,-1))
		{
			tortuga=fun(tortuga.first, tortuga.second);
			liebre=fun(fun(liebre.first , liebre.second).first , fun(liebre.first, liebre.second).second);
		}
		if(liebre == make_pair(-1,-1))//puede salir de GRIP
		{
			cout<<ans1(0,inicio-1)<<" step(s) to exit"<<endl;
		}
		else//existe un bucle
		{
			pair<int , int > aux=tortuga;
			tortuga=fun(tortuga.first, tortuga.second);
			int bucle=1;
			while(tortuga!=aux)
			{
				bucle++;
				tortuga=fun(tortuga.first, tortuga.second);
			}
			vector < pair < int , int > > camino;
			camino.clear();
			camino.push_back(make_pair(0,inicio-1));
			int to=1;
			tortuga=fun(0,inicio-1);
			while(true)
			{
				camino.push_back(make_pair(tortuga.first, tortuga.second));
				tortuga=fun(tortuga.first, tortuga.second);
				if(to>=bucle)
				{
					if(camino[to]==camino[to-bucle])
					break;
				}
				to++;
			}
			cout<<to-bucle<<" step(s) before a loop of "<<bucle<<" step(s)"<<endl;
		}
	}
}
