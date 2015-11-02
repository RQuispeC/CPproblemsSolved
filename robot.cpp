/*
	robot caminante con A* 
	Alumnos:
	Condori Delgado Johanine 		122241
	Farfan Escobedo Jean Franco 	120885
	Quispe Condori Edgar Rodolfo 	120682	
*/
#include<bits/stdc++.h>
#define	INF 1<<30
#define MAX 105
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long int64;
typedef pair< int64, int64 > pll;

int n, m; //tablero de n X m
// h = h' + g 
pii p[MAX][MAX]; //nodo anterior del cual viene (padre de nodo)
int past[MAX][MAX]; // cantidad de pasos ya realizados: g
bool vis[MAX][MAX]; //estructura para controlar lista de cerrados y abiertos
vector < string > grip; //mapa para el robot
pii  begin, end;// posicion de incio y fin

/*
	un  mapa para el robot estara dado por la siguiente entrada:
	n, m (dimensiones del mapa), un mapa de nXm con las siguientes caracteristicas:
	B:  posicion de inicio.
	E:  posicion de fin.
	.:  un lugar libre para caminar
	*: un lugar por donde no se puede caminar(pared).
	
*/ 
bool valid(int i, int j)
{
	return i>=0 && j>=0 && i<n && j<m && grip[i][j]!='*';
}
// direcciones del robot
int dx[4]={0, -1, 0, 1}; 
int dy[4]={-1, 0, 1, 0};

struct node // clase nodo del grafo
{
	pii pos; //posicion en tablero
	int cost;
	node(){}
	void getCost() // retorna h=h' + g
	{
		int h= abs(pos.first - end.first) + abs(pos.second - end.second);
		int g= past[pos.first][pos.second];
		//cout<<pos.first<<" "<<pos.second<<"-->"<<h<<" : "<<g<<endl;
		cost = h + g;
	}
	node (pii _pos)
	{
		pos=_pos;
		getCost();
	}
	//sobrecargamos el operador < para poder obtener el nodo con menor h=h' + g
	bool operator < ( node other ) const 
	{
		return cost > other.cost;
	}
};
// retorna true si se puede llegar a la meta
bool sol(node cur) //A*
{
	memset(vis, 0, sizeof vis); // todos los nodos en abiertos
	memset(past, -1, sizeof past); //inicializar en valores nulos
	p[cur.pos.first][cur.pos.second] =  cur.pos; //p[inicio] = inicio
	past[cur.pos.first][cur.pos.second] = 0; //g(inicio) = 0;
	//cola de prioridad que nos permitira sacar el nodo mas optimo en O(log(espacio de busqueda))
	priority_queue < node > q; 
	q.push(cur);
	while(!q.empty())
	{
		node u = q.top(); // el top de la cola de prioridad siempre tendra al nodo mas optimo
		vis[u.pos.first][u.pos.second]=1; //entra a lista de cerrados
		//cout<<u.pos.first<<" : "<<u.pos.second<<"-->"<<u.cost<<endl;
		q.pop();
		if(u.pos == end ) return 1; //llegamos a la meta
		for(int k=0;k<4;k++) //genera
		{
			int ni = u.pos.first + dx[k]; 
			int nj = u.pos.second + dy[k]; 
			if(valid(ni, nj) && !vis[ni][nj]) // posicion dentro del tablero, que no es pared y esta en abierto
			{
				//el nodo no es repetido o, es repetido pero se mejora su costo 
				if(past[ni][nj]==-1 || ( past[u.pos.first][u.pos.second] + 1 < past[ni][nj] )) 
				{
					p[ni][nj] = u.pos;
					past[ni][nj] = past[u.pos.first][u.pos.second] + 1;
					q.push(node(pii(ni, nj)));
				}
			}
		}
	}
	return 0;
}
//nos mostrara el camino optimo
void getPath(pii cur)
{
	grip[cur.first][cur.second] = '%'; //marcamos el camino
	if(cur == begin)
	{
		cout<<cur.first<<" "<<cur.second<<endl;
		return;
	}
	getPath(p[cur.first][cur.second]);
	cout<<cur.first<<" "<<cur.second<<endl;
}
int main()
{
	//leer input
	printf("###############\n");
	printf("A*\n");
	printf("###############\n");
	printf("Ingrese tamaño del tablero:\n");	
	cin>>n>>m;
	printf("Ingrese grip:\n");
	grip.clear();
	for(int i=0;i<n;i++)
	{
		string tmp;
		cin>>tmp;
		grip.push_back(tmp);
	}
	
	
	// obtener posicion inicial y final
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(grip[i][j]=='B') begin=pii(i, j);
			if(grip[i][j]=='E') end=pii(i, j);
		}
	if(!sol(node(begin)))
		puts("NO EXISTE CAMINO HASTA LA META!!!!");
	else
	{
		puts("EL CAMINO ES:");
		getPath(end);
		for(int i=0;i<n;i++)
			cout<<grip[i]<<endl;	
	}	
}
/*
NOTA: 
% :  el camino minimo del robot
Para ejecutar el codigo en linea puede usar:
https://ideone.com/

casos de prueba:

caso de prueba 1:
4 6
**..B.
...*..
.****.
..E...

link de la ejecucion:
https://ideone.com/thhxjE

-------------------------------------------------

caso de prueba 2:
8 10
..........
....*****.
.B..*.....
....*.....
....*.*.E.
......*...
..*****...
..........
..........

link de la ejecucion:
https://ideone.com/nhcU1Y


*/



