#include<iostream>
#define MAX 50002
using namespace std;
int parents[MAX];
int find(int x)
{
	if(parents[x]==x) return x;
	else return parents[x]=find(parents[x]);
}
void Union(int x , int y)
{
	int rootX=find(x);
	int rootY=find(y);
	parents[rootX]=rootY;

}
int main()
{
	int n, m;
	int j=0;
	while(cin>>n>>m && n!=0 && m!=0)
	{
		for(int i=1;i<=n;i++)
			parents[i]=i;
		for(int i=0;i<m;i++)
		{
			int aux1,aux2;
			cin>>aux1>>aux2;
			Union(aux1,aux2);
		}
		int compoConex=0;
		for(int i=1;i<=n;i++)
			if(find(i)==i)
				compoConex++;
		cout<<"Case "<<++j<<": "<<compoConex<<endl;	
	}
	return 0;
}
	
