#include<bits/stdc++.h>
#define MAX 80
using namespace std;
typedef vector < int > vi;
int a[MAX][MAX], b[MAX][MAX], n , k;
int main()
{
	while(cin>>n>>k)
	{
		if(n==0 && k==0) break;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d", &a[i][j]);
				
	}
}
/*
- leer datos
- generar DAG struct node (k, v)
	*	determinar node(i, j) =i*n+j 
	*   pos (i,j) puede conectar a otro pos (i',j')si j0=j0' |  j0=j1' | j1=j0' | j1=j1' , AB, A=(i0,j0), B=(i1,j1)
		
- vector dist
- correr camino minimo en dag (con costo de aristas invertido)
*/
