#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2147483647
using namespace std;
int p[MAX];
void cribaExtended(int k)
{
	for(int i=4 ; i<=k ; i+=2)
		p[i]=2;
	for(int i=3 ; i*i<=k ; i+=2)
		if(!p[i])
			for(int j=i*i ; j<=k ; j+=i*2)
				p[j]=i;
	/*
	esta criba almacena un factor primo para cada numero
	representa con " 0 " los # primos
	*/			
}
struct factor
{
	int base, exp;
	factor()
	{
		base=0;
		exp=0;
	}
	factor(int b, int e)
	{
		base=b;
		exp=e;
	}
};
vector < factor > A;
vector < factor > B;
vector < factor > comb ( vector < factor > a, vector < factor > b)
{
	int  i=0,j=0;
	vector < factor > ans;
	ans.clear();	
	while(true)
	{
		if(i==a.size() && j==b.size()) break;
		else if(i==a.size())
			ans.push_back(b[j++]);
		else if(j==a.size())
			ans.push_back(a[i++]);
		else if(a[i].base==b[j].base)
			{
				ans.push_back(factor(a[i].base, a[i].exp + b[j].exp ) );
				i++;
				j++;
			}
		else if(a[i].base<b[j].base)
			{
				ans.push_back(a[i]);
				i++;
			}
		else if(a[i].base>b[j].base)
			{
				ans.push_back(b[j]);
				j++;
			}		
	}
	return ans;
}
vector < factor > factorizacion(int n) //factorización de n
{
	vector < factor > aux;
	aux.clear();
	for(int i=2;i*i<=n;i++)
	{
		int	exp=0;
		while(n%i==0)
		{
			exp++;
			n/=i;
		}
		if(exp!=0)
			aux.push_back(factor(i,exp));
	}
	if(n!=1)	
		aux.push_back(factor(n,1));
	return aux;
} 
vector < factor > fact(int n)
{
	vector < factor > aux;
	aux.clear();
	while(p[n])
	{
		f.push_back(p[n]);
		n/=p[n];
	}
	if(n>1)
		f.push_back(n);
	return F;
	/*
		para factorisar aprovechamos que ya tenemos un afctor pimo de cada numero y  
		almacenamos en "f" todos los factores de de N  
	*/
}
vector < factor > fact(int n) //factorización de n!
{
	vector < factor > ans;
	ans.clear();
	for(int i=2;i<=n;i++)
	{
		//cout<<" ** "<<i<<endl;
		vector < factor > a;
		a.clear();
		a= factorizacion ( i );
		ans=comb(ans,a);
	}
	return ans;
}
bool solution(vector < factor > a, vector < factor > b)//a! y b
{
	int  i=0,j=0;
	int corrects=0;
	int comparados=0;
	while(true)
	{
		if(i==a.size() || j==b.size()) break;
		else if	(a[i].base==b[j].base)
			{
				comparados++;
				if(b[j].exp<=a[i].exp)
					corrects++;
				i++;
				j++;	
			}
		else if(a[i].base<b[j].base)
				i++;
		else if(a[i].base>b[j].base)
				j++;
	}
	if(comparados==b.size() && corrects==comparados)
		return true;
	return false;	
}
int main()
{
	int   a, b;
	while(cin>>a>>b)
	{
		cout<<"******" <<a<<"  : "<<b<<endl;
		A.clear();B.clear();
		
		B=factorizacion(b);
		cout<<"paso"<<endl;
		for(int i=0;i<B.size();i++)
			cout<<B[i].base<<" :  "<<B[i].exp<<endl;
		cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
		A=fact(a);
		/*for(int i=0;i<A.size();i++)
			cout<<A[i].base<<" :  "<<A[i].exp<<endl;
		*/if(solution (A,B))
			cout<<b<<" divides "<<a<<"!"<<endl;
		else
			cout<<b<<" does not divide "<<a<<"!"<<endl;
	}
}
