#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<sstream>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<string>
#include<map>
using namespace std;
int main()
{
	int tested;
	cin>>tested;
	int n, p;
	while(tested--)
	{
		cin>>n>>p;
		int i=1, j=i+1;
		for(int l=0;l<2*n+p;l++)
		{
			printf("%d %d\n", i,j);
			j++;
			if(j>n)
			{
				i++;
				j=1+i;
			}
		}
	}	
}

