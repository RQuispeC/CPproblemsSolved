#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int main()
{
	double m[25][25];
	double help[25][25];
	int p[25][25];
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i==j) m[i][j]=1.0;
				else cin>>m[i][j];
				help[i][j]=m[i][j];
				p[i][j]=i;
			}
				
		}
		bool cam[25];
		memset(cam, false, sizeof cam);
		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
				{
					if(!cam[i])
					{
						if(help[i][j]< m[i][k]*m[k][j])
						{
							help[i][j]=help[i][k]*help[k][j];
							if(i==j && help[i][j]-1.0>=0.01)
								cam[i]=true;
							p[i][j]=p[k][j];	
						}
					}	
				}
		for(int i=0;i<n;i++)
			cout<<help[i][i]<<endl;	
			cout<<"-------------------------"<<endl;	
	}
}
