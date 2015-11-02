#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main()
{
	while(cin>>n)
	{
		float ans=0.0;
		int scoreT=0;
		for(int i=0;i<n;i++)
		{
			int score;
			string op;
			cin>>score>>op;
			if(op=="A"){ ans+=(4.0*(float)score); scoreT+=score; }
			else if(op=="A-"){ ans+=(3.7*(float)score); scoreT+=score;}
			else if(op=="B+"){ ans+=(3.3*(float)score); scoreT+=score;}
			else if(op=="B"){ ans+=(3.0*(float)score); scoreT+=score;}
			else if(op=="B-"){ ans+=(2.7*(float)score); scoreT+=score;}
			else if(op=="C+"){ ans+=(2.3*(float)score); scoreT+=score;}
			else if(op=="C"){ ans+=(2.0*(float)score) ; scoreT+=score;}
			else if(op=="C-"){ ans+=(1.7*(float)score); scoreT+=score;}
			else if(op=="D"){ ans+=(1.33*(float)score); scoreT+=score; }
			else if(op=="D-"){ ans+=(1.0*(float)score); scoreT+=score; }
			else if(op=="F") { ans+=(0.0*(float)score); scoreT+=score; }
		}
		if(scoreT>0) ans=ans/(float)scoreT;
		printf("%.2f\n", ans);
	}	
}

