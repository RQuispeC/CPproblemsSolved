#include<iostream>
#include<cstring>
#include<cstdio>
#define MAX 50010
using namespace std;
struct node
{	
	int father,  weight;
	node()
	{
		father=-1;
		weight=0;
	}
	node(int f, int w)
	{
		father=f;
		weight=w;
	}
	
};
node A[MAX];
int Hight[MAX];
int Weight[MAX];
int n,m;
int hight(int i)
{
	if(A[i].father==i) return 0;
	if(Hight[i] != -1 ) return Hight[i];
	return Hight[i]=1+hight(A[i].father);	
}
int weight(int i)
{
	if(A[i].father==i) return 0;
	if(Weight[i]!=-1) return Weight[i];
	return Weight[i]=A[i].weight+weight(A[i].father);
}
int query(int a, int b)
{
	int i=a,  j=b;
	while(Hight[i]!=Hight[j])
	{
		
		if(Hight[i]<Hight[j]) 
			j=A[j].father;
		else
			i=A[i].father;	
	}
	if(i==j) 
	{
		if(A[i].father==i) // el padre comun es la raiz
			return Weight[a]+Weight[b];
		else// el padre comun es diferente de la raiz
		{
			return Weight[a]+Weight[b] - 2* Weight[j];
		}	  
	}
	else //buscamos padre comun de menor altura
	{
		while(i!=j)
		{
			
			i=A[i].father;
			j=A[j].father;
		}
		return Weight[a]+Weight[b] - 2* Weight[j];
	}
	
}
int main()
{
	scanf("%d", &n);
	memset(Hight, -1, sizeof Hight);
	memset(Weight, -1, sizeof Weight);
	for(int i=0;i<n;i++)
		A[i]=node(i,0);
	for(int i=0;i+1<n;i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u ,&v ,&w);
		A[u]=node(v,w);
	}
	/*for(int i=0;i<n;i++)
		cout<<i<<" : "<<A[i].father<<"  "<<A[i].weight<<endl;
	cout<<">>>>>>>>>>>>>>>>>>>>>>>>"<<endl;	
	*/
	for(int i=0;i<n;i++)
	{
		Hight[i]=hight(i);
		Weight[i]=weight(i);
	}
	/*for(int i=0;i<n;i++)
		cout<<i<<" :  "<<Hight[i]<<endl;
		cout<<">>>>>>>>>>>>>><<<<<"<<endl;
	for(int i=0;i<n;i++)
		cout<<i<<" :  "<<Weight[i]<<endl;
	*/
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a, &b);
		printf("%d\n",query(a,b));
	}
}

