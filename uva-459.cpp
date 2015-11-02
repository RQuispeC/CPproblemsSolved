#include<iostream>
#define MAX 26
using namespace std;
int parents[MAX];
int find(int x)
{
	if(parents[x]==x) return x;
	else return parents[x]=find(parents[x]);
}
void Union(int x , int y)
{
	int rX=find(x);
	int rY=find(y);
	parents[rX]=rY;
}
int main()
{
	int tested;
	cin>>tested;
	string aux;
	cin>>aux;
	bool blank=false;
	while(tested--)
	{	
		if(blank) cout<<endl;
		blank=true;
		int limite =aux[0]-'A'+1;
		for(int i=0;i<limite;i++)
			parents[i]=i;		
		while(cin>>aux && aux.size()==2 )
		{
			Union(aux[0]-'A',aux[1]-'A');
		}
		int cont=0;
		for(int i=0;i<limite;i++)
		{
			if((i)==parents[i]){
				cont++;
			}
		}	
		cout<<cont<<endl;		
	}
	return 0;
}
