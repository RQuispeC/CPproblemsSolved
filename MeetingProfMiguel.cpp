#include<bits/stdc++.h>
#define MAX 30
#define INF 1e5
using namespace std;
int Y[MAX][MAX], M[MAX][MAX];
void ini()
{
	for(int i=0;i<MAX;i++)
		for(int j=i;j<MAX;j++)
				if(i==j)
					Y[i][j]=M[i][j]=0;
				else
					Y[i][j]=Y[j][i]=M[i][j]=M[j][i]=INF;	
}
int main()
{
	int n;
	while(scanf("%d", &n))
	{
		if(n<=0 ) break;
		ini();
		for(int i=0;i<n;i++)
		{
			char dir,type,c1,c2;
			int w;
			cin>>type>>dir>>c1>>c2>>w;
			if(type=='Y')
			{
				Y[c1-'A'][c2-'A']=min(Y[c1-'A'][c2-'A'], w);
				if(dir=='B')
					Y[c2-'A'][c1-'A']=min(Y[c2-'A'][c1-'A'], w);
			}
			else
			{
				M[c1-'A'][c2-'A']=min(M[c1-'A'][c2-'A'], w);
				if(dir=='B')
					M[c2-'A'][c1-'A']=min(M[c2-'A'][c1-'A'], w);
			}
		}
		for(int k=0;k<MAX;k++)
			for(int i=0;i<MAX;i++)
				for(int j=0;j<MAX;j++)
				{
					Y[i][j]=min(Y[i][j], Y[i][k] +Y[k][j]);
					M[i][j]=min(M[i][j], M[i][k] +M[k][j]);
				}		
		char p1,p2;
		cin>>p1>>p2;
		int mini=INF;
		for(int i=0;i<MAX;i++)
		{
			if( Y[p1-'A'][i]+M[p2-'A'][i] < mini )
			{
				mini=Y[p1-'A'][i]+M[p2-'A'][i];
			}
		}
		if(mini!=INF)
		{
			vector < char > ans;
			ans.clear();
			for(int i=0;i<MAX;i++)
			{
				if(Y[p1-'A'][i]+M[p2-'A'][i]==mini)
					ans.push_back((char)(i+'A'));
			}
			cout<<mini;
			for(int i=0;i<ans.size();i++)
				cout<<" "<<ans[i];
			cout<<endl;	
		}
		else
			cout<<"You will never meet."<<endl;
	}
}

