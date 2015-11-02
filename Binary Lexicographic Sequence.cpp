#include <algorithm>
#include <iostream>
#include <cstdio>
#include <utility>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#define MAX 45
using namespace std;
int n,m,k;
long long Validos[MAX];
long long noValidos[MAX];
vector <int> numero;
void generate()
{
   Validos[1]=2;
   Validos[2]=3;
   for(int i=3;i<=MAX;i++)
   {
      Validos[i]=Validos[i-1]+Validos[i-2];   
   }
}
int det(int x)
{
   int i=1;
   while(Validos[i] < x)
   {
      i++;
   }
     return i; 
}
long long out(int x)
{
   if(x<=2)
   {
       return x-1;
   }
   else
   {
		double ans=0;
		while(x>2)
		{
			int max=det(x);
			ans+=pow(2.0,max-1);
			x=x-Validos[max-1];
		}
		ans+=x;
		return (long long)ans-1;
   }
      
}
int main(){
   generate();
   cin>>n>>m;
   if(Validos[n]<m)
   {
		cout<<"-1"<<endl;
		return 0;
   }
   int p=out(m); 
   numero.clear();
   bool flag=true;
   //cout<<"total : "<<p<<endl;
   while(flag )
   {
      numero.push_back(p%2);
      p/=2;
      if(p<=1 && p/10==0)
      {
         numero.push_back(p);
         flag=false;
      }
   }
   for(int i=0;i<n-numero.size();i++)
      cout<<0;
   for(int i=numero.size()-1;i>=0;i--)
      cout<<numero[i];
	cout<<endl;	    
   return 0;

}
