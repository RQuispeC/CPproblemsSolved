#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX 100005
using namespace std;
bool first[MAX];
bool second[MAX];
int a[MAX];
int b[MAX]; 
int c[2*MAX];
int main()
{
	int n;
	cin>>n;
	for(int l=0;l<n;l++)
	{
		cin>>a[l]>>b[l];
	}
	int i=0,j=0,k=0;
	while(true)//ordenar en un solo Array
	{
		if(i==n && j==n) break;
		if(a[i]>b[j])
		{
			c[k++]=b[j++];
		}
		else 
		{
			c[k++]=a[i++];
		}
		if(i==n)
		{
			while(j<n)
			{
				c[k++]=b[j++];
			}
		}
		if(j==n)
		{
			while(i<n)
			{
				c[k++]=a[i++];
			}
		}
	}
	for(int l=0;l<n;l++)//inicializar
	{
		if(2*(l+1)<=n)
		{
			first[l]=true;
			second[l]=true;
		}
		else
		{
			first[l]=false;
			second[l]=false;
		}
	}	
	for(int l=0;l<k;l++)
		cout<<c[l]<<"  ";
	cout<<endl;	
	/*for(int l=0;2*l<=n;l++)
	{
		i=0;
		j=0;
		k=0;
		int to=n-2*l;
		while(to>0)
		{
			if(l>0)
			{
				if(c[k]==a[i] && i>=l)
				{
					if(!first[i])
					{
						first[i]=first[i] | true;
						to--;
					}
					i++;
				}
				else
				if(c[k]==b[j] && j>=l)
				{ 	
					if(!second[j])
					{
						second[j]=second[j] | true;
						to--;
					}
					j++;
				}
			}
			else
			{
				if(c[k]==a[i])
				{
					first[i]=first[i] | true;
					i++;
				}
				else
				{
					second[j]=second[j] | true;
					j++;
				}
				k++;
				to--;	
			}
		}
	}*/
	string A="",B="";
	for(int l=0;l<n;l++)//generar respuesta
	{
		if(first[l]==true)A+="1";
		else A+="0";
		if(second[l]==true)B+="1";
		else B+="0";
	}
	cout<<A<<endl;
	cout<<B<<endl;
	
}
