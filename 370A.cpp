#include <bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
typedef long long ll;
bool tab[11][11];
void generate()
{
	bool f=0;
	for(int i=0;i<11;i++)
		for(int j=0;j<11;j++)
		{
			tab[i][j]=f;
			f=not f;
		}
}
bool posible(int a, int b, int c, int d)
{
	return abs(a-c) == abs (b-d);
}
int main()
{
	generate();
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int ansR, ansA, ans;
	if(a==c || b == d)
		ansR=1;
	else
		ansR=2;
	if(!(tab[a][b] xor tab[c][d]))//iguales
	{
		if(posible(a,b,c,d))
			ansA=1;
		else
			ansA=2;	
	}
	else
		ansA=0;
	int x = max(abs(c-a), abs(b-d));
	ans=x + max (abs(c-a) - x, 0) + 	max (abs(b-d) -x, 0);
	cout<<ansR<<" "<<ansA<<" "<<ans<<endl;
}

