#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 10005
using namespace std;
int filas, columnas;
bool fil[MAX];
bool col[MAX];
int x[]={0,1,0,-1};
int y[]={1,0,-1,0};
bool validate(int f, int c)
{
	return (f>=0 && f<filas && c>=0 && c<columnas);
}
int main()
{
	int n;
	int ca=0;
	while(cin>>filas>>columnas>>n)
	{
		if(filas==0 && columnas== 0 && n==0) break;
		//cout<<filas<<"  "<<columnas<<"  "<< n<<endl;
		memset(fil,false,filas+3);
		memset(col, false, columnas+3);
		int f,c;
		for(int i=0;i<n;i++)
		{
			int fi,co;
			cin>>fi>>co;
			fil[fi]=true;
			col[co]=true;
		}
		cin>>f>>c;
		int con=0;
		if(fil[f] || col [c]) con++;
		for(int i=0;i<4;i++)
		{
			int nf=f+x[i];
			int nc=c+y[i];
			if(validate(nf,nc))
			{
				if(fil[nf] || col [nc]) con++;
			}
			else con++;
		}
		//cout<<con<<endl;
		cout<<"Case "<<++ca<<": ";
		if(con==5) cout<<"Party time! Let's find a restaurant!"<<endl;
		else cout<<"Escaped again! More 2D grid problems!"<<endl;
	}
}
