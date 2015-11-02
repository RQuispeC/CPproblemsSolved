#include<bits/stdc++.h>
#define X1 31 
#define X2 37
#define MAX 1005
using namespace std;
typedef long long ll;
/*	
usare dos funciones hash para optimizar las colisiones y evitar obtener WA.
*/
string s, sr;//s: string original, sr:string S volteado.
ll hs1[MAX], hsr1[MAX], hs2[MAX], hsr2[MAX];
//hs1:hash del string S (primera funcion hash)
//hsr1:hash del string SR (primera funcion hash), string volteado
//hs2:hash del string S (segunda funcion hash)
//hsr2:hash del string SR (segunda funcion hash), string volteado
ll pot1[MAX], pot2[MAX];
void precalc()//determina el hash de todo el string
{
/*	
la implemnetacion del hash se parece a una tabla de sumas acumulativas
*/
	for(int i=0;i<s.size();i++)
	{
		if(i==0)
		{
			pot1[i]=pot2[i]=1ll;
			hs1[i]= ll(s[i]-'a');
			hsr1[i]= ll(sr[i]-'a');
			hs2[i]= ll(s[i]-'a');
			hsr2[i]= ll(sr[i]-'a');
		}	
		if(i>=1)
		{
			pot1[i]=pot1[i-1]*X1;
			pot2[i]=pot2[i-1]*X2;
			hs1[i]=hs1[i-1]*X1 + (s[i]-'a');
			hsr1[i]=hsr1[i-1]*X1 + (sr[i]-'a');
			hs2[i]=hs2[i-1]*X2 + (s[i]-'a');
			hsr2[i]=hsr2[i-1]*X2 + (sr[i]-'a');
		}	
	}
}
ll h1(int i, int j) //hash (primera funcion) de string S desde indice i al indice j
{
 	if(i==0)
 		return hs1[j];
 	return hs1[j]-hs1[i-1]*pot1[j-i+1];
 		
}
ll h2(int i, int j) //hash (segunda funcion) de string S desde indice i al indice j 
{
 	if(i==0)
 		return hs2[j];
 	return hs2[j]-hs2[i-1]*pot2[j-i+1];
 		
}
ll hr1(int i, int j) //hash (primera funcion) de string SR desde indice i al indice j
{
	if(i==0)
 		return hsr1[j];
 	return hsr1[j]-hsr1[i-1]*pot1[j-i+1];
}
ll hr2(int i, int j) //hash (segunda funcion) de string SR desde indice i al indice j
{
	if(i==0)
 		return hsr2[j];
 	return hsr2[j]-hsr2[i-1]*pot2[j-i+1];
}
int main()
{
	cin>>s; //leer S
	sr=s; // String sr (volteada)
	reverse(sr.begin(),sr.end());// complejidad O(n)
	int ans=0, n=s.size();
	precalc(); //llenar las tablas hash, complejidad: O(n)
	for(int i=0;i<n;i++) //O(n)
		for(int j=i;j<n;j++) //O(n*n)
			if(h1(i, j) == hr1(n-j-1, n-i-1) && h2(i, j) == hr2(n-j-1, n-i-1)) //O(1), la comparacion de las dos funciones hash se hace así, es algo asi como una formula.
				ans++;
	cout<<ans<<endl;	
		
}

