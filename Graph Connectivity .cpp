#include<iostream>
#include<algorithm>
#include<cstring>
#define MAX 26
using namespace std;
int parents[MAX];
int Find(int x)
{
	if(parents[x]==x)
		return x;
	else
		return parents[x]=Find(parents[x]);	
}
void Union(int x, int y) 
{
	int rootX=Find(x);
	int rootY=Find(y);
	parents[rootX]=rootY;
}  
int main()
{
	int testCases;
	cin>>testCases;
	string aux;
	cin>>aux;
	bool blankLine =false;
	while(testCases--)
	{
		int limit=aux[0] - '@';
		for(int i=0;i<limit;i++) 
			parents[i]=i;
		while(cin>>aux && aux.size()==2)
		{		
			Union(aux[0]-'A',aux[1]-'A');
		}
		int componetsConexed=0;
		for(int i=0;i<limit;i++)
			if(parents[i]==i)
				componetsConexed++;
		if (blankLine) cout<<endl;
		blankLine=true;	
		cout<<componetsConexed<<endl;		
	}
	return 0;
}
