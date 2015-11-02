#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int polos [5];
int des[5][5]={	0,1,2,3,4,
				1,2,0,3,4,
				2,3,1,4,0,
				3,4,2,1,0,
				4,3,2,1,0};
int main()
{
	/*des[0]={0,1,2,3,4};
	des[1]={1,2,0,3,4};
	des[2]={2,3,1,4,0};
	des[3]={3,4,2,1,0};
	des[4]={4,3,2,1,0};*/
	for(int i=0;i<5;i++)
		cin>>polos[i];
	int n;
	cin>>n;
	while(n--)
	{
		string str;
		cin>>str;
		int d=-1;
		if(str=="S")
			d=0;
		else if(str=="M")
			d=1;
		else if(str=="L")
			d=2;	
		else if(str=="XL")
			d=3;
		else //if(str=="XXL")
			d=4;
		for(int i=0;i<5;i++)
			if(polos[des[d][i]]>0)
			{
				if(des[d][i]==0)
					printf("S\n");
				else if(des[d][i]==1)
					printf("M\n");
				else if(des[d][i]==2)
					printf("L\n");
				else if(des[d][i]==3)
					printf("XL\n");
				else //if(des[d][i]==4)
					printf("XXL\n");
				polos[des[d][i]]--;	
				break;								
			}				
	}	
	
}

